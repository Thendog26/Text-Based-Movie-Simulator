//20-5-20 Parent class for food items
//item stocked in Candy bar for consumption options in Cinema simulator
#ifndef FOOD_H
#define FOOD_H
#include <iostream>
#include <string>

using namespace std;

class food 
{	
	protected:
	int hunger_restore;		// Hunger Restoration Value
	double value;			// Item value (for shop interation)
	std::string name;		// Item name

	public:
	// Returns hunger restore value to main code
	int GetHungerRestore(){
		return hunger_restore;
	}
	// Returns item value to main code
	double GetItemValue() {
		return value;
	}
	// Returns item name to main code
	string GetName() {
		return name;
	}
	//The noise emitter to sound out the food being eaten in the cinema
	virtual void consumePrint() {
		cout << "Default food print" << endl;
	}

};
#endif
