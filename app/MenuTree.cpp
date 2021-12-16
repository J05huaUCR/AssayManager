/*	=============================================================================
	MenuTree Source
	
	@version	0.1.1
	@author	JP
	========================================================================== */
	
#include "MenuTree.h"

/*	==========================================================================
	R-Tree class instantiation
	
	@param 	null		nothing
	@return 	null		nothing
	========================================================================== */
MenuTree::MenuTree() {
	init();	
}	

/*	==========================================================================
	R-Tree class destructor
	
	@param 	null		nothing
	@return 	null		nothing
	========================================================================== */
MenuTree::~MenuTree() {
	// Delete root node when complete
	delete Root;
}

/*	==========================================================================
	Define
	
	@param 	null		nothing
	@return 	null		nothing
	========================================================================== */
void MenuTree::init() {

	if ( getDebugMode() ) {
		std::cout << TAB2 << "^ MenuTree::init() called...\n";
	}

	// Init, create root node
	Root = new MenuNode;
	Root->id = "root";
	Root->key = "";
	Root->label = "Top Menu";
	Root->level = 0;
	Root->index = 0;
	CurrentMenu = Root;
	
	// Add Menus
	addMenu("file", "F", "[F]ile");
	addMenu("file", "newFile", "N", "[N]ew File");
	addMenu("file", "openFile", "O", "[O]pen File");
	addMenu("file", "saveFile", "S", "[S]ave File");
	addMenu("file", "saveFileAs", "A", "Save File [A]s");
	addMenu("file", "exportLayout", "L", "Export [L]ayout");
	addMenu("exportLayout", "exportPDF", "P", "Export [P]DF");
	addMenu("exportLayout", "exportSVG", "V", "Export S[V]G");
	
	addMenu("edit", "E", "[E]dit");
	addMenu("properties", "P", "[P]roperties");
	addMenu("view", "V", "[V]iew");
	addMenu("help", "H", "[H]elp");
	
	if ( getDebugMode() ) {
		std::cout << TAB2 << "v MenuTree::init() called...DONE\n";
	}

	return;
}

/*	==========================================================================
	==========================================================================
	
	MODIFIERS
	
	==========================================================================
	========================================================================== */

/*	==========================================================================
	Define
	
	@param 	null		nothing
	@return 	null		nothing
	========================================================================== */
void MenuTree::setDebugMode(unsigned b) {
	DebugMode = b;
	return;
}

/*	==========================================================================
	Define
	
	@param 	null		nothing
	@return 	null		nothing
	========================================================================== */
int MenuTree::setCurrentMenu(MenuNode* m) {
	if ( m == NULL ) {
		CurrentMenu = Root;
	} else {
		CurrentMenu = m;
	}
	return 0;
}

/*	==========================================================================
	Define
	
	@param 	str		menu key
	@param 	str		shortcut char
	@param 	str		Label
	@return 	null		status: 0 = OK, <0 = ERROR
	========================================================================== */
int MenuTree::addMenu(std::string id, std::string shortcutKey, 
							 std::string menuLabel) {
	
	return addMenu(Root, id, shortcutKey, menuLabel);
}

/*	==========================================================================
	Define
	
	@param 	str		Parent menu ID
	@param 	str		menu id
	@param 	str		shortcut char
	@param 	str		Label
	@return 	null		status: 0 = OK, <0 = ERROR
	========================================================================== */
int MenuTree::addMenu(std::string parentMenuID, std::string id, 
							 std::string shortcutKey, std::string menuLabel) {
	
	MenuNode* menu = findMenu( parentMenuID );
	
	return addMenu(menu, id, shortcutKey, menuLabel);
}

/*	==========================================================================
	Define
	
	@param 	ptr		Parent menu node
	@param 	str		menu key
	@param 	str		shortcut char
	@param 	str		Label
	@return 	null		status: 0 = OK, <0 = ERROR
	========================================================================== */
int MenuTree::addMenu(MenuNode* parent, std::string id, 
							 std::string shortcutKey, std::string menuLabel) {
	
	if ( getDebugMode() > 0) {
		std::cout << TAB2 << "^ MenuTree::addMenu() called...\n";
	}
	
	if ( getDebugMode() > 1) {
		if ( parent == NULL ) std::cout << TAB3 << "MenuNode is NULL, set to Root\n";
		std::cout << TAB3 << "ID:|" << id << "|, ";
		std::cout << TAB3 << "shortcutKey:|" << shortcutKey << "|, ";
		std::cout << TAB3 << "menuLabel:|" << menuLabel << "|\n";
	}
	
	if ( parent == NULL ) parent = Root;
	int status = 0;
	
	// Create Menu Node
	MenuNode* m = new MenuNode();
	m->parent = parent;
	m->id = id;
	m->key = shortcutKey;
	m->label = menuLabel;
	m->level = parent->level + 1;
	m->index = parent->children.size();
	
	// Add to parent node
	parent->children.push_back(m);
	parent->isLeaf = false;
      
	if ( getDebugMode() > 0) {
		std::cout << TAB2 << "v MenuTree::addMenu() called...\n";
		std::cout << "DONE:|" << status << "|\n";
	}
	return status;					 
}

/*	==========================================================================
	Define
	
	@param 	str		menu key
	@return 	int		status: 0 = OK, <0 = ERROR
	========================================================================== */
int MenuTree::selectMenu(std::string menuKey) {

	// Check for going back
	if (menuKey == "B") {
		if (CurrentMenu != Root) {
			CurrentMenu = CurrentMenu->parent;
			return 0;
		} else {
			return -1;
		}
		
	}
	
	// Check children
	for (unsigned i = 0; i < CurrentMenu->children.size(); ++i) {
		if ( menuKey == CurrentMenu->children.at(i)->key) {
			CurrentMenu = CurrentMenu->children.at(i);
			return 0;
		}
	}
	return -1;
}

/*	==========================================================================
	Define
	
	@param 	null		nothing
	@return 	null		nothing
	========================================================================== */
int MenuTree::insertNode(MenuNode* m) {
	if ( m == NULL ) return -1;
	return insertNode(m, CurrentMenu);	
}

/*	==========================================================================
	Define
	
	@param 	ptr		MenuNode to add
	@param	ptr		Location to add MenuNode
	@return 	int		status: 0 = OK, <0 = ERROR
	========================================================================== */
int MenuTree::insertNode(MenuNode* m, MenuNode* n) {

	if ( getDebugMode() > 0) {
		std::cout << TAB2 << "^ MenuTree::insertNode() called...\n";
	}
	
	if ( getDebugMode() > 1) {
		std::cout << TAB3 << "MenuNode m is ";
		if ( m == NULL ) std::cout << "NOT ";
		std::cout << "present.\n";
		std::cout << TAB3 << "MenuNode n is ";
		if ( n == NULL ) std::cout << "NOT ";
		std::cout << "present.\n";
	}
	
	if ( m == NULL ) return -1;
	if ( n == NULL ) n = Root;
	n->children.push_back( m );
	
	if ( getDebugMode() > 0) {
		std::cout << TAB3 << "Node added.\n";
		std::cout << TAB2 << "v MenuTree::insertNode() called...DONE\n";
	}
	return 0;
}

/*	==========================================================================
	Remove children from node vector

	@param 	node		pointer to MenuNode
	@return 	unsigned	status of function call
	========================================================================== */
int MenuTree::clearChildren(MenuNode* node) {
	
	while (node->children.size() > 0) {
		//delete node->children[0];
		node->children.pop_back();
	}
	
	return 0;
}

/*	==========================================================================
	==========================================================================
	
	RETRIEVERS
	
	==========================================================================
	========================================================================== */

/*	==========================================================================
	Desc
	
	@param 	none		nothing
	@return 	bool		width
	========================================================================== */
unsigned MenuTree::getDebugMode() {
	return DebugMode;
}

/*	==========================================================================
	Test to see if node is a leaf

	@param 	node		pointer to MenuNode
	@return 	bool		true /false
	========================================================================== */
bool MenuTree::isLeaf(MenuNode* node) {

	// If there are no children, it's a leaf
	if (node->children.size() == 0) {
		node->isLeaf = true;
		return true;
	} else {
		node->isLeaf = false;
		return false;
	}
}

/*	==========================================================================
	Test to see if node is a empty

	@param 	node		pointer to MenuNode
	@return 	bool		true /false
	========================================================================== */
bool MenuTree::isEmpty(MenuNode* node) {
	if (node->children.size() == 0 ) return true; else return false;
}

/*	==========================================================================
	Returns the root node of thre tree
	
	@param 	none		nothing
	@return 	ptr		MenuNode*
	========================================================================== */
MenuNode* MenuTree::getRoot() {
	return Root;
}

/*	==========================================================================
	Returns the current node of thre tree
	
	@param 	none		nothing
	@return 	ptr		MenuNode*
	========================================================================== */
MenuNode* MenuTree::getCurrentMenu() {
	return CurrentMenu;
}

/*	==========================================================================
	find MenuNode* by key
	
	@param 	str		menu key to search for
	@return 	ptr		MenuNode* if found, root otherwise
	========================================================================== */
MenuNode* MenuTree::findMenu(std::string key) {
	return findMenu(Root, key);
}

/*	==========================================================================
	find MenuNode* by key, recursive function
	
	@param 	str		menu key to search for
	@return 	ptr		MenuNode* if found, root otherwise
	========================================================================== */
MenuNode* MenuTree::findMenu(MenuNode* n, std::string id) {

	if ( getDebugMode() > 0) {
		std::cout << TAB2 << "^ MenuTree::findMenu() called...\n";
	}
	
	if ( getDebugMode() > 1) {
		std::cout << TAB3 << "Searching for id:|" << id << "|\n";
	}


	if ( n == NULL ) {
		if ( getDebugMode() > 1) {
			std::cout << TAB2 << "v MenuTree::findMenu() called...DONE\n";
		}
		return Root;
	}
	
	if ( n->id == id ) { // Base case
		if ( getDebugMode() > 0) {
			if ( getDebugMode() > 1) std::cout << TAB3 << "menu found\n";
			std::cout << TAB2 << "v MenuTree::findMenu() called...DONE\n";
		}
		return n;
	} else {
		if ( isEmpty(n) ) {
			// no children to check, return root
			if ( getDebugMode() > 0) {
				if ( getDebugMode() > 1) std::cout << TAB3 << "menu not found, returning root.\n";
				std::cout << TAB2 << "v MenuTree::findMenu() called...DONE\n";
			}
			return Root;
		} else {
			// Check children
			if ( getDebugMode() > 0) {
				if ( getDebugMode() > 1) std::cout << TAB3 << "menu not found, searching children\n";
				std::cout << TAB2 << "v MenuTree::findMenu() called...DONE\n";
			}
			MenuNode* m = Root;
			for (unsigned i = 0; i < n->children.size(); ++i) {
				MenuNode* temp = findMenu(n->children.at(i), id);
				if ( temp != Root) m = temp;
			}
			if ( getDebugMode() > 0) {
				if ( getDebugMode() > 1) std::cout << TAB3 << "Done searching children\n";
				std::cout << TAB2 << "v MenuTree::findMenu() called...DONE\n";
			}
			return m;
		}
	}
	return Root;
}

/*	==========================================================================
	Define
	
	@param 	null		nothing
	@return 	null		nothing
	========================================================================== */
std::string MenuTree::getMenu() {

	if ( getDebugMode() > 0) {
		std::cout << TAB2 << "^ MenuTree::getMenu() called...\n";
		if ( getDebugMode() > 1) {
			std::cout << TAB3 << "Current menu is:|" << getCurrentMenu()->id << "\n";
		}
	}
	std::string s = "";

	MenuNode* m = getCurrentMenu();
	unsigned i = 0;
	for (i = 0; i < m->children.size(); ++i) {
		s += toString(i + 1) + ") "; 
		s += m->children[i]->label;
		s += "\n";
	}
	
	// If a submenu, add Back Option
	if (m != Root) {
		s += toString(i + 1) + ") "; 
		s += "[B]ack";
		s += "\n";
	}
	
	if ( getDebugMode() > 0) {
		std::cout << TAB2 << "v MenuTree::getMenu() called...DONE\n";
	}
	
	return s;
}


/*	==========================================================================
	Define
	
	@param 	null		nothing
	@return 	null		nothing
	========================================================================== */
void MenuTree::printTree() {
	std::cout << TAB2 << "------------------------------------------------------\n";
	std::cout << TAB2 << "MenuTree()::printTree() called.\n";
	std::cout << TAB2 << "------------------------------------------------------\n";
	printTree(Root, 1);
	std::cout << TAB2 << "------------------------------------------------------\n\n";
	return;
}

/*	==========================================================================
	Define
	
	@param 	null		nothing
	@return 	null		nothing
	========================================================================== */
void MenuTree::printTree(MenuNode* node, unsigned level) {

	// output chars for indent
	std::string tab = "   ";
	std::string tabs = "";
	
	for (unsigned j = 0; j <= level; ++j) {
		tabs += tab;
	}
	
	std::cout << tabs << "ID: " << node->id << "\n";
	
	// if not a leaf, output each child node
	for (unsigned i = 0; i < node->children.size(); ++i) {
		printTree(node->children[i], (level+1));		
	}
	
	return ;
}

