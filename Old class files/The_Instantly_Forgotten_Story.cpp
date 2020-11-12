//20-5-20 The Instantly Forgotten Story subclass of Movie
//functionality for The Instantly Forgotten Story object shown in Cinema simulator
#include "The_Instantly_Forgotten_Story.h"
#include <cstdlib> //use of the c std library
#include <iostream> //allows it to interact with external files
using namespace std;
//constructor
The_Instantly_Forgotten_Story::The_Instantly_Forgotten_Story()
{
        rating = 2; //the age required to enter this movie
        genre = "Well, my little sister liked it."; //can be calle don to aid movie selection at the ticket desk, this film is meant to be the dud option
        title = "The Instantly Forgotten Story"; //title of the movie as it will appear at the ticket desk
        price = 9; //the price of this movie at the ticket desk
        availability = true;
}


//Deconstructor
The_Instantly_Forgotten_Story::~The_Instantly_Forgotten_Story(){
}
