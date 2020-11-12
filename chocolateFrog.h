//20-5-20 chocolate frog subclass of food
//item stocked in Candy bar for consumption options in Cinema simulator
#ifndef CHOCOLATEFROG_H
#define CHOCOLATEFROG_H

#include "Food.h"

class chocolateFrog : public food { //choc top class creation
public:
	//Chocolate Frog Constructor
	chocolateFrog();
	//noises emitted by player upon eating item
	void consumePrint(){
		cout<<"damn that's good... I need more!!"<<endl; 
	}
	// Class Deconstructor
	~chocolateFrog();
};
#endif
