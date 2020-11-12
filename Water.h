//20-5-20 Water subclass of food
//item stocked in Candy bar for consumption options in Cinema simulator
#ifndef WATER_H //defining water subclass
#define WATER_H
#include "Food.h"

class Water : public food {//Water class creation
public:
	//constructor
	Water();
	//noises emitted by player upon eating item
	void consumePrint(){
		cout << "Gulp, gulp, gulp" << endl;
	}
	//deconstructor
	~Water();
};
#endif
