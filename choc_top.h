//20-5-20 choc top subclass of food
//item stocked in Candy bar for consumption options in Cinema simulator
#ifndef CHOC_TOP_H //defining choc top subclass
#define CHOC_TOP_H
#include "Food.h"
#include <string>
#include <iostream>

class choc_top : public food { //choc top class creation

	public:
	//constructor	
	choc_top();
	//Prints consumsion noises
	void consumePrint() {
		cout << "nom nom nom" << endl;
	}
	//deconstructor	
	~choc_top();
	
};
#endif
