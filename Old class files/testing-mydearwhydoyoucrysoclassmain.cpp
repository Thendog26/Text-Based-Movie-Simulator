 // My_Dear_Why_Do_You_Cry_So testing main
#include <iostream>
#include <string>
#include <ctime>
#include "My_Dear_Why_Do_You_Cry_So.h"

using namespace std;
int main(){

		srand(time(NULL)); //Sets inprogram time for rand() functions
        cout << endl << "## Child class testing ##" << endl; //a message to show that it is a test report in the terminal
        cout << endl;
        // Variable initiallising
        Movie *Mov = new My_Dear_Why_Do_You_Cry_So; //creating a movie pointer and assignig a movie class to the location.
		cout << "Test 1: Movie variable print" << endl;
		cout << "Name: " << Mov->get_title() << endl; // Displays movie name
        cout << "Age Rating: " << Mov->get_rating() << endl; // Display movie rating
        cout << "Genre: " << Mov -> get_genre() << endl; // Displays movie genre
        cout << "Price: " << Mov -> get_price() << endl; // Displays movie price
		Mov->Generate_Availability(); //setting the newmovies' avaliability to alternate 20% of the time like the default one.
        cout << "Avaliable?: ";
        if( Mov->get_availability() == true){
        	cout << "yes" << endl;
        } else {
        	cout << "nah, sorry" << endl;
        }
		
		cout << endl << "Test 2: Avaliability mechanic test (Testing for all movies)" << endl;
		for (int i = 0; i < 20; i++) {
			cout << "Loop count: " << i+1 << endl;
			Mov->Generate_Availability();
			cout << "Avaliable?: ";
        	if( Mov->get_availability() == true){
        		cout << "yes" << endl;
        	} else {
        		cout << "nah, sorry" << endl;
        	}
			cout << endl;
		}
		
        delete Mov; //deleting the pointer to prevent memory leaks
       
           return 0;  
        }
