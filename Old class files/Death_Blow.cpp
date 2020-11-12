//20-5-20 Death Blow subclass of Movie
//functionality for Death Blow object shown in Cinema simulator
#include "Death_Blow.h"
#include <cstdlib> //use of the c std library
#include <iostream> //allows it to interact with external files
using namespace std;
//constructor
Death_Blow::Death_Blow(){
        rating = 18; //the age required to enter this movie
        genre = "Dude, it's totally awesome!"; //can be called to aid movie selection at the ticket desk, this film is meant to be the dud option
        title = "Death Blow"; //title of the movie as it will appear at the ticket desk
        price = 14; //the price of this movie at the ticket desk
		availability = false;
}

//Deconstructor
Death_Blow::~Death_Blow()
{
}
