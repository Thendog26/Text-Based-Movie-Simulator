// ############################################################################################
// OOP Major Prac 9-11 - 2020
// This main code is what brings together and creates the Cinema Simulator
// Description ~
// The main focus of our code is to create a simulation experience of going to the movies. The
// user will be able to purchase tickets, shop items, and experience a simulation of going to the
// cinemas, along with all the fun experiences of munching on all your snacks to spontaneously
// having to go to the bathroom!
// Creators: Adam Tolkin & Nathan Shepherd
// Date of creation: May 19th, 2020 => May 26th, 2020 
// ############################################################################################

// Import libraries and class files
// Standard
#include <cstdlib>
#include <ctime> 
#include <iostream>
#include <string>
#include <vector>
//Classes
#include "chocolateFrog.h"
#include "choc_top.h"
#include "Cola.h"
#include "Death_Blow.h"
#include "My_Dear_Why_Do_You_Cry_So.h"
#include "Player.h"
#include "popcorn.h"
#include "Slushie.h"
#include "The_Instantly_Forgotten_Story.h"
#include "Water.h"

using namespace std;


// ### Main loop for the code to complie in ###
int main(){
	
	// ###################################################################
	// ### Initialiation of variables and class objects for the Cinema ###
	srand(time(NULL));	// Program time setter (for random functionality)
	// Variables
	bool cinema = true, menu = true, watch = true;		// Loop control variables
	int TempAge = 0;									// Temp Age holder
	string TempName = "";								// Temp Name holder

	// User Input
	cout << "Welcome to Shepherd and Ward Cinemas, Adelaide" << endl;
	cout << "Before you go anywhere, we'll like you to sign up for our mandatory customer rewards program! :)" << endl;
	cout << "Please give us your name: ";
	while (!(cin >> TempName)) { 	// Verification that TempName has valid input
		cin.clear ();
		cin.ignore ( 100 , '\n' );  // Clears input stream
		cout << "\033[2J\033[1;1H"; // Speical character combonation that triggers c++ to clear the screen
		cout << "Invalid! Please give us your proper name: ";
	}
	cout << "\033[2J\033[1;1H";
	cout << "And your age?: ";
	while (!(cin >> TempAge) || TempAge < 0) { 	// Verification that TempAge has valid input
		cin.clear ();				
		cin.ignore ( 100 , '\n' );	// Clears input stream
		cout << "\033[2J\033[1;1H"; // Speical character combonation that triggers c++ to clear the screen
		cout << "Invalid! Please give us your proper age: ";   //Reprompts age
	}

	// Player object
	Player *user = new Player();										// User object
	user->SetName(TempName);											// Passes user's name into the player class pointer
	user->SetAge(TempAge);												// Passes user's age into the player class pointer
	user->GenerateHunger();												// Generates a random hunger for the user
	user->GenerateMoney();												// Generates a random amount of money for the user (for the sake of simulation)
	// Movie objects
	Movie *MyDear = new My_Dear_Why_Do_You_Cry_So();					// Movie Option 1
	MyDear->Generate_Availability();									// Generates avalibility randomly (for the sake of simulation)
	Movie *InstantForget = new The_Instantly_Forgotten_Story();			// Movie Option 2
	InstantForget->Generate_Availability();								// Generates avalibility randomly (for the sake of simulation)
	Movie *DeathBlow = new Death_Blow();								// Movie Option 3
	DeathBlow->Generate_Availability();									// Generates avalibility randomly (for the sake of simulation)	
	
	// Food Objects
	food *choctop = new choc_top();									// Candy Bar Option 1
	food *chocolatefrog = new chocolateFrog();						// Candy Bar Option 2
	food *cola = new Cola();										// Candy Bar Option 3
	food *Popcorn = new popcorn();									// Candy Bar Option 4
	food *slushie = new Slushie();									// Candy Bar Option 5
	food *water = new Water();										// Candy Bar Option 6
 
	// ###################################################################
	
	// ### Cinema Core Code Loop ### //
	while (cinema == true) {
	// ###################################################################
	// ### Menu loop ###
	while (menu == true) {

		menu = false;
	}
	menu = true; // If you break out of the watch loop, you will go back into the menu
	// ###################################################################

	// ###################################################################
	// ### Cinema watching loop ###
	while (watch == true) {

		
	watch = false;
	}
	// ###################################################################
	cinema = false;
	}

	//Deconstructor
	delete user;
	delete InstantForget;
	delete DeathBlow;
	delete choctop;
	delete chocolatefrog;
	delete cola;
	delete Popcorn;
	delete slushie;
	delete water; 
}
