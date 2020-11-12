//20-5-20 My Dear Why Do You Cry So? subclass of Movie
//functionality for My Dear Why Do You Cry So? object shown in Cinema simulator
#include "My_Dear_Why_Do_You_Cry_So.h"
#include <cstdlib> //use of the c std library
#include <iostream> //allows it to interact with external files
using namespace std;

//constructor
My_Dear_Why_Do_You_Cry_So::My_Dear_Why_Do_You_Cry_So(){
        rating = 14; //the age required to enter this movie
        genre = "My girlfriend took me to see that, it's surprisingly poignant"; //can be called on to aid movie selection at the ticket desk, this film is meant to be the dud option
        title = "My Dear Why Do You Cry So?"; //title of the movie as it will appear at the ticket desk
        price = 13; //the price of this movie at the ticket desk
		availability = false;
}

//Deconstructor
My_Dear_Why_Do_You_Cry_So::~My_Dear_Why_Do_You_Cry_So()
{
}
