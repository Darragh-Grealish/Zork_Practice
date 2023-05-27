#include <iostream>
#include "mainwindow.h"
#include <QApplication>

using namespace std;
#include "ZorkUL.h"

/*
int main(int argc, char *argv[]) {
    ZorkUL temp;
	temp.play();
	return 0;
}
*/

int main(int argc, char *argv[])
{
//    ZorkUL temp;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    temp.play();
    return a.exec();
}



ZorkUL::ZorkUL() {
    createRooms();
// Creating instance of character
    createCharacter();
}
// Instance of Character Darragh
void ZorkUL::createCharacter(){
    Character *Darragh;
    Darragh = new Character("Darragh");
    theCharacter = Darragh;
}

void ZorkUL::createRooms()  {
    Room *aRoom, *b, *c, *d, *e, *f, *g, *h, *i, *newRoom;

    aRoom = new Room("aRoom");
        aRoom->addItem(new Item("x", 1, 11));
        aRoom->addItem(new Item("y", 2, 22));
	b = new Room("b");
        b->addItem(new Item("xx", 3, 33));
        b->addItem(new Item("yy", 4, 44));
	c = new Room("c");
	d = new Room("d");
	e = new Room("e");
	f = new Room("f");
	g = new Room("g");
	h = new Room("h");
    i = new Room("i");
    newRoom = new Room("newRoom"); //Desription, inWeight, inValue (found in 'item.h' file)
        newRoom->addItem(new Item("newItem", 5, 55));


    //             (N, E, S, W)
    aRoom->setExits(f, b, d, c);
    b->setExits(NULL, NULL, NULL, aRoom);
    c->setExits(NULL, aRoom, NULL, NULL);
    d->setExits(aRoom, e, NULL, i);
    e->setExits(NULL, NULL, NULL, d);
    f->setExits(newRoom, g, aRoom, h);
    g->setExits(NULL, NULL, NULL, f);
    h->setExits(NULL, f, NULL, NULL);
    i->setExits(NULL, d, NULL, NULL);
    newRoom->setExits(NULL, NULL, f, NULL);

    currentRoom = aRoom; // A pointer to the current (starting room)
}

/**
 *  Main play routine.  Loops until end of play.
 */
void ZorkUL::play() {
	printWelcome();

	// Enter the main command loop.  Here we repeatedly read commands and
	// execute them until the ZorkUL game is over.

	bool finished = false;
	while (!finished) {
//		// Create pointer to command and give it a command.
//		Command* command = parser.getCommand();
//		// Pass dereferenced command and check for end of game.
//		finished = processCommand(*command);
//		// Free the memory allocated by "parser.getCommand()"
//		//   with ("return new Command(...)")
//		delete command;
	}
	cout << endl;
	cout << "end" << endl;
}

string ZorkUL::printWelcome() {
    string theString = "start \n info for help \n" + currentRoom->longDescription() + "\n";
    //cout << "start"<< endl;
    //cout << "info for help"<< endl;
    //cout << endl;
    //cout << currentRoom->longDescription() << endl;
    //emit printOutput(theString);
    return theString;
}



/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
string ZorkUL::nearlyProcessCommand(string someCommand) {
    cout << "In nearly command" << endl;
//    cout << someCommand << endl;
    Command* command = parser.getCommand(someCommand);
    cout << "commmand parsed" << endl;
    // Pass dereferenced command and check for end of game.
    string answer = processCommand(*command);
    return answer;
    cout << "Returned" << endl;
    delete command;
    cout << "Comand deleted" << endl;
}

string ZorkUL::processCommand(Command command) {
    if (command.isUnknown()) {
        return "invalid input --";
    }

	string commandWord = command.getCommandWord();
//------------------------------------------INFO------------------------------------------
	if (commandWord.compare("info") == 0)
        return printHelp();
//------------------------------------------MAP------------------------------------------
	else if (commandWord.compare("map") == 0)
		{
        std::string mapString =
            "     [newRoom]     ""\n"
            "              |         ""\n"
            "              |         ""\n"
            "[h] --- [f] --- [g]""\n"
            "              |         ""\n"
            "              |         ""\n"
            "[c] - [aRoom] - [b]""\n"
            "              |         ""\n"
            "              |         ""\n"
            "[i] --- [d] --- [e]";
        return mapString;
		}
//------------------------------------------GO------------------------------------------
//	else if (commandWord.compare("go") == 0)
//		goRoom(command);
////------------------------------------------TAKE------------------------------------------
//    else if (commandWord.compare("take") == 0)
//    {
//       	if (!command.hasSecondWord()) {
//        cout << "incomplete input"<< endl;
//        }
//        else
//         if (command.hasSecondWord()) {
//        cout << "you're trying to take " + command.getSecondWord() << endl;
//        int location = currentRoom->isItemInRoom(command.getSecondWord());
//        if (location  < 0 ){
//            cout << "item is not in room" << endl;
//            cout << currentRoom->longDescription() << endl;
//        }
//        else{
//            cout << "item is in room" << endl;
//             cout << "index number " << + location << endl;
//            cout << endl;
//             // Character can take up items
//            Item* currentItem = currentRoom->getItemFromRoom(location);
//            theCharacter->addItems(currentItem);
//            currentRoom->removeItemFromRoom(location);
//            cout << currentRoom->longDescription() << endl;
//            }
//        }
//    }
////------------------------------------------PUT------------------------------------------
//    else if (commandWord.compare("put") == 0)
//        {
//        if (!command.hasSecondWord()) {
//            cout << "incomplete input"<< endl;
//        }
//        else
//            if (command.hasSecondWord()) {
//            cout << "you're adding " + command.getSecondWord() << endl;
//            // Allowing Character to put
//            Item itemToPut = theCharacter->hasItem(command.getSecondWord());
//            // Item no there
//            if(itemToPut.getShortDescription().compare("Nothing") == 0){
//            cout << "You don't have that particular item... ;(" << endl;
//            cout << currentRoom->longDescription() << endl;
//            }
//            // Item there and being put
//            else {
//            cout << "You put " << endl;
//            currentRoom->addItem(&itemToPut);
//            theCharacter->putItems(&itemToPut);
//            cout << currentRoom->longDescription() << endl;
//            }
//        }
//    }
////------------------------------------------INVENTORY------------------------------------------
//    else if (commandWord.compare("inventory") == 0){
//        theCharacter->printInventory();
//    }
////------------------------------------------QUIT------------------------------------------
//    else if (commandWord.compare("quit") == 0) {
//		if (command.hasSecondWord())
//			cout << "overdefined input"<< endl;
//		else
//			return true; /**signal to quit*/
//	}
    return "false";
}
/** COMMANDS **/
 // PrintHelp() used to be here, now is inline

 //------------------------------------------goRoom------------------------------------------
void ZorkUL::goRoom(Command command) {
	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
		return;
	}

	string direction = command.getSecondWord();

	// Try to leave current room.
	Room* nextRoom = currentRoom->nextRoom(direction);

	if (nextRoom == NULL)
		cout << "underdefined input"<< endl;
	else {
		currentRoom = nextRoom;
		cout << currentRoom->longDescription() << endl;
	}
}
//------------------------------------------GO Button------------------------------------------
string ZorkUL::go(string direction) {
	//Make the direction lowercase
	//transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
	//Move to the next room
	Room* nextRoom = currentRoom->nextRoom(direction);
	if (nextRoom == NULL)
		return("direction null");
	else
	{
		currentRoom = nextRoom;
		return currentRoom->longDescription();
	}
}
string ZorkUL::processCommand2(string commando2) {
    if (commando2.compare("map") == 0)
    {
        std::string mapString =
            "     [newRoom]     ""\n"
            "              |         ""\n"
            "              |         ""\n"
            "[h] --- [f] --- [g]""\n"
            "              |         ""\n"
            "              |         ""\n"
            "[c] - [aRoom] - [b]""\n"
            "              |         ""\n"
            "              |         ""\n"
            "[i] --- [d] --- [e]";
        return mapString;
    }
}
