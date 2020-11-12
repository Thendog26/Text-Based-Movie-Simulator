//20-5-20 Slushie subclass of food
//item stocked in Candy bar for consumption options in Cinema simulator
#include "choc_top.h"
#include <cstdlib> //use of the c std library
#include <time.h>
#include <iostream> //allows it to interact with external files

using namespace std;

//contructor
choc_top::choc_top(){
	hunger_restore = rand() % 3; //how satisfying the snack is
	value = 5; // the cost
	name = "Choc Top"; //the name
}

//decontructor
choc_top::~choc_top(){
}
