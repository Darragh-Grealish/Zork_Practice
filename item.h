// Inclusion guard, 'if file is included, don't include it again'
// Defines ITEM_H_ first, second time it goes to include the file, it won't include it
#ifndef ITEM_H_
#define ITEM_H_

// Standard header files from the standard header file that come with C++
// Angle brackets tells compiler to look in C++ library?, "" to look in local directory
#include <map>
#include <string>
#include <iostream>
using namespace std;

class Item {
private: //Private encapsulated data, a description of the inetrface
    string description; //Axe
    string longDescription; //Old axe with old scripture,
    int weightGrams; //Maybe have a carry limit
    float value; //Tradable...?
    bool weaponCheck; //Is it extendable, a wepon, clean

public:
    Item (string description, int inWeight, float inValue); //Constructor
    Item (string description);
	string getShortDescription();
    string getLongDescription();
	int getWeight();
	void setWeight(int weightGrams);
	float getValue();
	void setValue(float value);
	int getWeaponCheck();
	void setWeaponCheck(int weaponCheck);
    bool operator==(const Item &other) const;
};

// # is a preprocessor language, series of commands that let you edit the code before compiling, "replace this with this"
// can give the same software to all phone types, but you can say to use certain code for different phone types

#endif /*ITEM_H_*/
// Inclusion guard

