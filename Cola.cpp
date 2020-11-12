//20-5-20 Cola subclass of food
//item stocked in Candy bar for consumption options in Cinema simulator
#include "Cola.h"
#include <cstdlib> //use of the c std library
#include <iostream> //allows it to interact with external files

using namespace std;

//constructor
Cola::Cola(){
	hunger_restore = rand() % 3; //how satisfying the snack is
	value = 1; //the price at the Candy bar
	name = "Cola";

}

//Deconstructor
Cola::~Cola(){
}
