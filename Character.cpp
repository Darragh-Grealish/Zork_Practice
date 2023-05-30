#include "Character.h"

Character::Character(string description) {
	this->description = description;
}

void Character::addItems(Item *item) {
    itemsInCharacter.push_back(*item);
}
//------------------------------------------putITEMS------------------------------------------
void Character::putItems(Item *item) {
    int location = getItemIndex(item);
    if (location == -1){
        cout << "item is not here" << endl;
    }
    else{ // Removing choosen item from character
        itemsInCharacter.erase(itemsInCharacter.begin()+location);
    }
}
//------------------------------------------getItemINDEX------------------------------------------
int Character::getItemIndex(Item *item){
    string name = item->getShortDescription();
    int size = itemsInCharacter.size();
    for (int i = 0; i < size; i++){
        if(itemsInCharacter[i].getShortDescription().compare(name) == 0)
            return i;
    }
    return -1;
}

//------------------------------------------hasITEM------------------------------------------
// Character having an Item
Item Character::hasItem(Item *inItem){
    for (Item i : itemsInCharacter)
        if(i == *inItem)
            return i;
    Item* temp = new Item("Nothing");
    return *temp;
}

//------------------------------------------printINVENTORY------------------------------------------
string Character::printInventory()
{
    string returnString;
    for (Item i : itemsInCharacter){
        returnString = returnString + (i).getShortDescription() + " ";
    }
    return "\nInventory: " + returnString;
}



