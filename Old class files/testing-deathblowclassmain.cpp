 // Death_Blow testing main
#include <iostream>
#include <string>
#include <ctime>
#include "Death_Blow.h"

using namespace std;
int main(){
    srand(time(NULL)); //Sets inprogram time for rand() functions

        cout << endl << "## Death Blow class testing ##" << endl; //a message to show that it is a test report in the terminal
        cout << endl;
        // Variable initiallising
        Movie *Mov = new Death_Blow; //creating a movie pointer and assignig a movie class to the location.

        int rating = Mov -> get_rating(); //setting the newmovies' rating to the default one.
        string genre = Mov -> get_genre(); //setting the newmovies' genre to the default one.
        string title = Mov -> get_title(); //setting the newmovies' title to the default one.
        double price = Mov -> get_price(); //setting the newmovies' price to the default one.
        bool avaliability = Mov -> get_availability(); //setting the newmovies' avaliability to alternate 20% of the time like the default one.
        string cute_answer;


        if( avaliability == true){
            cute_answer = "yes";
        }else{
            cute_answer = "nah, sorry";
        }

        cout<< "Age Rating: " <<rating << endl << "Genre: " << genre << endl << "Title: " << title << endl << "Price $" << price << endl << "Any Tickets left: " << cute_answer << endl << endl; // printing all the variables

        delete Mov; //deleting the pointer to prevent memory leaks
       
           return 0;  
        }
