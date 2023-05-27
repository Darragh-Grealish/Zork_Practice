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

    string goRoom(Command command);
    void createItems();
    void displayItems();

public:
	ZorkUL();
	void play();
    string printWelcome();
	string go(string direction);
    string processCommand2(string commando2);
    string nearlyProcessCommand(string someCommand);

//signals:
//    void printOutput(string text);
};


#endif /*ZORKUL_H_*/
