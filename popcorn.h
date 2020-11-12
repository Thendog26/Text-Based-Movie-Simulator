//20-5-20 popcorn subclass of food
//item stocked in Candy bar for consumption options in Cinema simulator
#ifndef POPCORN_H
#define POPCORN_H

#include "Food.h"

class popcorn : public food { //popcorn class creation
public:
	//Constructor
	popcorn();

	//noises emitted by player upon eating item
	void consumePrint() {
		std::cout << "Crunch, crunch" << std::endl;
	}
	
	//Constructor
	~popcorn();

};
#endif
