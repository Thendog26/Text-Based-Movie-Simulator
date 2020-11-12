//20-5-20 Slushie subclass of food
//item stocked in Candy bar for consumption options in Cinema simulator
#include "Slushie.h"
#include <cstdlib> //use of the c std library
#include <iostream> //allows it to interact with external files

using namespace std;

//constructor
Slushie::Slushie() {
	hunger_restore = rand() % 5 - 1;
	value = 3;
	name = "Slushie";
}

//deconstructor
Slushie::~Slushie() {
}
