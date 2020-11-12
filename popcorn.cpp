//20-5-20 Cola subclass of food
//item stocked in Candy bar for consumption options in Cinema simulator
#include "popcorn.h"
#include <iostream> //use of the c std library
#include <cstdlib> //allows it to interact with external files

//Constructor
popcorn::popcorn(){
	hunger_restore = rand() % 3 -1;
	value = 5;
	name = "Popcorn";
}

//Deconstructor
popcorn::~popcorn(){
}

	
