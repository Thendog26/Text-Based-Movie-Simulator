//20-5-20 Cola subclass of food
//item stocked in Candy bar for consumption options in Cinema simulator
#ifndef COLA_H
#define COLA_H
#include "Food.h"

class Cola : public food { //Cola class creation
	public:
	//constructor
	Cola();

	//noises emitted by player upon eating item
	void consumePrint(){
		cout << "Gulp, gulp, gulp" << endl;
	}

	//constructor
	~Cola();
};
#endif
