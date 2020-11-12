//20-5-20 chocolate Frog subclass of food
//item stocked in Candy bar for consumption options in Cinema simulator
#include "chocolateFrog.h"
#include <cstdlib>
#include <iostream>

using namespace std;

//constructor
chocolateFrog::chocolateFrog(){
	hunger_restore = rand() % 3 - 2; // how satisfying the snack is (random generator)
	value = 1; 						// the price at the Candy bar
	name = "Chocolate Frog";			// Item name

}

chocolateFrog::~chocolateFrog()
{
}



