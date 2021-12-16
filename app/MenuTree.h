/*	=============================================================================
	MenuTree Definition
	
	@version	0.1.1
	@author	JP
	========================================================================== */
	
#ifndef MENUTREE_H_
#define MENUTREE_H_

#include <stdio.h>      			// printf, scanf, NULL 
#include <stdlib.h>     			// malloc, free, rand
#include <iostream>					// input, output 
#include <cmath>						// Math Library
#include <string>						// C++ String Library
#include <vector>						// C++ Vector Library
#include <queue>						// C++ Queue Library
#include "Structs.h"
#include "Utilities.h"

//using namespace mtree;

// Structures for MenuTree Class
namespace smhdl {

	struct MenuNode {

		// Pointers to the MAX_NODES # of subtrees	
		MenuNode* parent; // Parent of this node, NULL if root
		std::vector< MenuNode* > children; // vector holding pointers to children

		std::string id = "";		
		std::string key = "";
		std::string label = "";
      
      // For flagging if leaf
      bool isLeaf = true;
      
      unsigned level = ERROR_UNT;
      unsigned index = ERROR_UNT;
      
      // Node constructor
      MenuNode() {
      	
      	// Initialize
      	parent = NULL;
      	
      }
	};

	class MenuTree {

		public:
			 MenuTree();
			~MenuTree();
			void init();
			
			// Modifiers
			void setDebugMode(unsigned);							// Set Debugging Level
			int setCurrentMenu(MenuNode*);
			int addMenu(std::string, 								// menu key
							std::string, 								// shortcut char
							std::string);								// Label
			int addMenu(std::string,								// Parent menu key
							std::string, 								// menu key
							std::string, 								// shortcut char
							std::string);								// Label
							
			int clearChildren(MenuNode*);

			// Retrievers
			unsigned getDebugMode();
			bool isLeaf(MenuNode*); 								// 
			bool isEmpty(MenuNode*);								// Checks to see if Empty
			std::string getMenu();
			MenuNode* getRoot();										//
			MenuNode* getCurrentMenu();
			MenuNode* findMenu(std::string);						// find menu by key, return node*
			void printTree();											// Prints the tree
			
			
			/* TO DO ============================================================== */
			
			
			int selectMenu(std::string);
			
			
							
			int insertNode(MenuNode*); 							// Insert Node at CurrentMenu
			int insertNode(MenuNode*, MenuNode*); 				// Insert Node at Node (GENERAL)
			int deleteNode(MenuNode*); 							// 	

			// RECURSIVE DELETE FUNCTION FOR DECONSTRUCTION
			
			/* TO DO ============================================================== */
			
		private:
			unsigned DebugMode = 0;									// Flag to output for debugging
			MenuNode* Root = NULL;
			MenuNode* CurrentMenu = NULL;
			
			void printTree(MenuNode*, unsigned); 				// Recursive print function 
			MenuNode* findMenu(MenuNode*,							// Recursive by node
									 std::string);						// find menu by key, return node*
			int addMenu(MenuNode*,									// Parent menu node
							std::string, 								// menu key
							std::string, 								// shortcut char
							std::string);								// Label
	};

} // end namespace

#endif
