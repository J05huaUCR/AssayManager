# CC contains the g++ compiler, supports multithreading
CC = g++ -std=c++11 -pthread -static-libstdc++

# CFLAGS contains the options for the compiler
CFLAGS = -g -c -Wall

# Path to Application Files
APP_PATH = app/
APP_FILES = BioReactor.o File.o Interface.o JSON.o MenuTree.o Structs.o Timer.o Utilities.o 

# Default option: compile everything
all: main

# Application Files
application: $(APP_FILES)

App.o: $(APP_PATH)App.cpp
	$(CC) $(CFLAGS) $(APP_PATH)App.cpp

BioReactor.o: $(APP_PATH)BioReactor.cpp
	$(CC) $(CFLAGS) $(APP_PATH)BioReactor.cpp
		
File.o: $(APP_PATH)File.cpp
	$(CC) $(CFLAGS) $(APP_PATH)File.cpp
		
Interface.o: $(APP_PATH)Interface.cpp
	$(CC) $(CFLAGS) $(APP_PATH)Interface.cpp
		
JSON.o: $(APP_PATH)JSON.cpp
	$(CC) $(CFLAGS) $(APP_PATH)JSON.cpp

MenuTree.o: $(APP_PATH)MenuTree.cpp
	$(CC) $(CFLAGS) $(APP_PATH)MenuTree.cpp
	
Structs.o: $(APP_PATH)Structs.cpp
	$(CC) $(CFLAGS) $(APP_PATH)Structs.cpp

Timer.o: $(APP_PATH)Timer.cpp
	$(CC) $(CFLAGS) $(APP_PATH)Timer.cpp
			
Utilities.o: $(APP_PATH)Utilities.cpp
	$(CC) $(CFLAGS) $(APP_PATH)Utilities.cpp
		
# Main File
main: main.o $(APP_FILES)
	$(CC) main.o $(APP_FILES) -o main.run
	
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
		
# Delete Object files
clean:
	rm -f *.o 
