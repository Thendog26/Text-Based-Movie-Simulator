//20-5-20 Slushie subclass of food
//item stocked in Candy bar for consumption options in Cinema simulator
#ifndef SLUSHIE_H //defining Slushie subclass
#define SLUSHIE_H
#include "Food.h"


class Slushie: public food { //Slushie class creation
	public: 
	//constructor
	Slushie();
	//noises emitted by player upon eating item
	void consumePrint(){
		cout << "Slurp!" << endl;
	}
	//constructor
	~Slushie();
};
#endif
