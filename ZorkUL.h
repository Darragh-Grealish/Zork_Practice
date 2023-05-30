#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Character.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include <iostream>
#include <string>



using namespace std;

class ZorkUL {

private:
    Character *theCharacter;
	Parser parser;
	Room *currentRoom;
    void createCharacter();
    void createRooms();


    string processCommand(Command command);
    inline string printHelp(){
        return "valid inputs are; " + parser.showCommands();
    }
    void createItems();
    void displayItems();

protected:
    string goRoom(Command command);

public:
	ZorkUL();
	void play();
    string printWelcome();
    string modifyHello(Parser&) {return "hello I am a global variable modified ...\n";};
	string go(string direction);
    string nearlyProcessCommand(string someCommand);


//signals:
//    void printOutput(string text);
};


#endif //ZORKUL_H_
