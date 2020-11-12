 // The_Instantly_Forgotten_Story testing main
#include <iostream>
#include <string>
#include <ctime>
#include "The_Instantly_Forgotten_Story.h"
using namespace std;
int main(){
	srand(time(NULL)); //Sets inprogram time for rand() functions

        cout << endl << "## The Instantly Forgotten Story class testing ##" << endl; //a message to show that it is a test report in the terminal
        cout << endl;
        // Variable initiallising
        The_Instantly_Forgotten_Story *Mov = new The_Instantly_Forgotten_Story; //creating a movie pointer and assignig a movie class to the location.

        int rating = Mov -> get_rating(); //setting the newmovies' rating to the default one.
        string genre = Mov -> get_genre(); //setting the newmovies' genre to the default one.
        string title = Mov -> get_title(); //setting the newmovies' title to the default one.
        double price = Mov -> get_price(); //setting the newmovies' price to the default one.
        bool availability = Mov -> get_availability(); //setting the newmovies' availability to alternate 20% of the time like the default one.
        string cute_answer;


        if( availability == true){
        	cute_answer = "yes";
        }else{
        	cute_answer = "nah, sorry";
        }

        cout<< "Age Rating: " <<rating << endl << "Genre: " << genre << endl << "Title: " << title << endl << "Price $" << price << endl << "Any Tickets left: " << cute_answer << endl << endl; // printing all the variables

        delete Mov; //deleting the pointer to prevent memory leaks
       
           return 0;  
        }
