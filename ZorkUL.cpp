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
//    temp.play();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}


ZorkUL::ZorkUL() {
    createRooms();
// Creating instance of character
    createCharacter();
}
// Instance of Character Helper
void ZorkUL::createCharacter(){
    Character *Helper;
    Helper = new Character("Helper");
    theCharacter = Helper;
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
    string storyTitle = "C++ game developed by Darragh Grealish\n Based on the Scooby Doo Episode 'What a night for a Kight' \n";
    string storyLine = "When Scooby and Shaggy are walking home from the movies, they "
                       "discover a black suit of armor in a pickup truck, and the gang deliver it to the local museum. "
                       "The kids later break into the museum to search for clues, after learning that the archaeologist "
                       "who was transporting the suit is missing, and they heard that the knight's armor has come to life.\n";
    string theString = "starting... \ntype info for help \n" + currentRoom->longDescription() + "\n";
    return storyTitle + storyLine + theString;
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
//------------------------------------------Button Message Convertion------------------------------------------
string ZorkUL::nearlyProcessCommand(string someCommand) {
    Command* command = parser.getCommand(someCommand);
    string answer = processCommand(*command);
    return answer;
    delete command;
}
//------------------------------------------Processor------------------------------------------
string ZorkUL::processCommand(Command command) {
    if (command.isUnknown()) {
        return "invalid input --";
    }
	string commandWord = command.getCommandWord();
//------------------------------------------INFO------------------------------------------
	if (commandWord.compare("info") == 0)      
    //    printHelp()
        return "\n""valid inputs are; \ngo quit info map take put inventory";
//------------------------------------------MAP------------------------------------------
	else if (commandWord.compare("map") == 0)
		{
        std::string mapString ="\n"
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
    else if (commandWord.compare("go") == 0){
        return goRoom(command);
    }
//------------------------------------------TAKE------------------------------------------
    else if (commandWord.compare("take") == 0) {
        if (!command.hasSecondWord()) {
            return "incomplete input";
        }
        else if (command.hasSecondWord()) {
            string atemptMessage = "\nyou're trying to take " + command.getSecondWord();
            int location = currentRoom->isItemInRoom(command.getSecondWord());
            if (location  < 0 ){ // Character can't take up item
                return atemptMessage + "\nitem is not in room\n" + currentRoom->longDescription();
            }
            else {
                // Character can take up items
                Item* currentItem = currentRoom->getItemFromRoom(location);
                theCharacter->addItems(currentItem);
                currentRoom->removeItemFromRoom(location);
//                cout << currentRoom->longDescription() << endl;
                string locationString = to_string(location);
                string itemExists = "\nitem is in room \nindex number --> " + locationString;
                return atemptMessage + itemExists + currentRoom->longDescription();
            }
        }
    }
////------------------------------------------PUT------------------------------------------
    else if (commandWord.compare("put") == 0)
        {
        if (!command.hasSecondWord()) {
            return "incomplete input";
        }
        else if (command.hasSecondWord()) {
            string atemptAdd = "\nyou're adding " + command.getSecondWord();
            // Allowing Character to put
            Item itemToPut = theCharacter->hasItem(command.getSecondWord());
            // Item no there
            if(itemToPut.getShortDescription().compare("Nothing") == 0){
                return atemptAdd + "\nYou don't have that particular item... ;(" + currentRoom->longDescription();
            }
            // Item there and being put
            else {
                currentRoom->addItem(&itemToPut);
                theCharacter->putItems(&itemToPut);
                return atemptAdd + currentRoom->longDescription();
            }
        }
    }
////------------------------------------------INVENTORY------------------------------------------
    else if (commandWord.compare("inventory") == 0){
        return theCharacter->printInventory();
    }
////------------------------------------------QUIT------------------------------------------
    else if (commandWord.compare("quit") == 0) {
        if (command.hasSecondWord())
            return "overdefined input";
        else
            return "Thank you for playing the game."; /**signal to quit*/
    }
    return "false";
}
/** COMMANDS **/
 // PrintHelp() used to be here, now is inline

 //------------------------------------------goRoom------------------------------------------
string ZorkUL::goRoom(Command command) {
	if (!command.hasSecondWord()) {
        return "incomplete input";
	}

	string direction = command.getSecondWord();

	// Try to leave current room.
	Room* nextRoom = currentRoom->nextRoom(direction);

	if (nextRoom == NULL)
        return "underdefined input";
	else {
		currentRoom = nextRoom;
        return currentRoom->longDescription();
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
        return "\n" + currentRoom->longDescription();
	}
}
