//20-5-20 Slushie subclass of food
//item stocked in Candy bar for consumption options in Cinema simulator
#include "Water.h"
#include <cstdlib> //use of the c std library
#include <iostream> //allows it to interact with external files

using namespace std;

//constructor
Water::Water(){
	hunger_restore = rand() % 4 + 2;
	value = 1;
	name = "Water";

}

Water::~Water(){
}
