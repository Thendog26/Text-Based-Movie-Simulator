// ############################################################################################
// OOP Major Prac 9-11 - 2020
// This main code is what brings together and creates the Cinema Simulator
// Description ~
// The main focus of our code is to create a simulation experience of going to the movies. The
// user will be able to purchase tickets, shop items, and experience a simulation of going to the
// cinemas, along with all the fun experiences of munching on all your snacks to spontaneously
// having to go to the bathroom!
// Creators: Adam Tolkin & Nathan Shepherd
// Date of creation: May 19th, 2020 => May 27th, 2020 
// ############################################################################################

// Import libraries and class files
// Libaraies
#include <cstdlib>
#include <ctime> 
#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
// Classes
#include "chocolateFrog.h"
#include "choc_top.h"
#include "Cola.h"
#include "Movie.h"
#include "Player.h"
#include "popcorn.h"
#include "Slushie.h"
#include "Water.h"

using namespace std;

// Pausing function (Pauses and return after the user presses enter)
void Pause() {
	string pause;
	cout << "Press any key and enter to continue...";
	cin >> pause; // dud variable for pausingm
	return;
}

// ############################################
// ### Main loop for the code to complie in ###
// ############################################
int main(){
	
	// ###################################################################
	// ### Initialiation of variables and class objects for the Cinema ###
	// ###################################################################
	srand(time(NULL));	// Program time setter (for random functionality)
	// Variables
	bool cinema = true, menu = true, watch = true, ticketMenu = false, candyMenu = false;		// Loop control variables
	int TempAge = 0;									// Temp Age holder
	string TempName = "", pause = "";								// Temp Name holder
	int input; 											// Generic variable to handle int input
	string sinput;										// Generic variable to handle string input
	string watchmoviecurrent = "";  // To import option into watch while loop

	// User Input
	cout << "\033[2J\033[1;1H"; // Screen Clear
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

	// ### Player object ### //
	Player *user = new Player();									// User object
	user->SetName(TempName);										// Passes user's name into the player class pointer
	user->SetAge(TempAge);											// Passes user's age into the player class pointer
	user->GenerateHunger();											// Generates a random hunger for the user
	user->GenerateMoney();		// Generates a random amount of money for the user (for the sake of simulation)

	// ### Movie objects ### //
	// Movie Option 1
	Movie *MyDear = new Movie("My Dear Why Do You Cry So?", "My girlfriend took me to see that, it's surprisingly poignant", 14, 13);	
	MyDear->Generate_Availability();            // Generates avalibility randomly (for the sake of simulation)
	// Movie Option 2
	Movie *InstantForget = new Movie("The Instantly Forgotten Story", "Well, my little sister liked it.", 2, 9);	
	InstantForget->Generate_Availability();		// Generates avalibility randomly (for the sake of simulation)
	// Movie Option 3
	Movie *DeathBlow = new Movie("Death Blow", "Dude, it's totally awesome!", 18, 14);			
	DeathBlow->Generate_Availability();			// Generates avalibility randomly (for the sake of simulation)	
	
	// Food Objects
	food *choctop = new choc_top();									// Candy Bar Option 1
	food *chocolatefrog = new chocolateFrog();						// Candy Bar Option 2
	food *cola = new Cola();										// Candy Bar Option 3
	food *Popcorn = new popcorn();									// Candy Bar Option 4
	food *slushie = new Slushie();									// Candy Bar Option 5
	food *water = new Water();										// Candy Bar Option 6
 
	// #############################
	// ### Cinema Core Code Loop ###
	// #############################
	while (cinema == true) {

	// #################
	// ### Menu loop ###
	// #################
	while (menu == true) {

		// Main Menu Options as displayed
		cout << "\033[2J\033[1;1H"; // Screen Clear
		cout << "Yo bro, welcome to the cinema! *coughs* What can I help you with?" << endl; 
		cout << "Select the number for the option you want" << endl;
		cout << "1. Ticket" << endl << "2. Candy Bar" << endl << "3. Go to the Theatre" << endl << "4. Leave" << endl << endl;
		cout << "What would you like to do?: ";

		// Menu user input selection
		while (!(cin >> input) || (input < 1 && input > 4)) { 	// Verification that the user inputs a valid number into the 
			cin.clear ();
			cin.ignore ( 100 , '\n' );  // Clears input stream
			cout << "\033[2J\033[1;1H"; // Speical character combonation that triggers c++ to clear the screen
			cout << "Yo bro, welcome to the cinema! *coughs* What can I help you with?" << endl; 
			cout << "Select the number for the option you want" << endl;
			cout << "1. Ticket" << endl << "2. Candy Bar" << endl << "3. Go to the Theatre" << endl << "4. Leave" << endl << endl;
			cout << "Invalid! Please select a number from 1 - 4! ";
		}
		cout << "\033[2J\033[1;1H"; // Screen Clear

		//  ## Ticket menu ## //
		if (input == 1) {

			bool ticketMenu = true; // sets ticket menu to true

			// Ticket Menu Loop
			while (ticketMenu == true){ // Printed ticket options on men

				// Ticket Menu Options
				cout << "\033[2J\033[1;1H"; // Clears screen
				cout << "Alright, what do you wanna see?" << endl;
				cout << "Select the number for the option you want (1-5)" << endl;
				cout << "1.Death Blow" << endl; 
				cout << "2.My Dear Why Do You Cry So?" << endl;
				cout << "3.The Instantly Forgotten Story" << endl;
				cout << "4.Not sure (Movie Descriptions)" << endl;
				cout << "5.I think I'm good thanks (leave ticket menu)" << endl << ": ";

				// User Ticket Menu input
				while (!(cin >> input) || (input <= 0 && input >= 6)) { 	// Verification that the user inputs a valid number into the 
					cin.clear ();
					cin.ignore (100,'\n'); // Clears input stream
					cout << "\033[2J\033[1;1H"; // Special character combonation that triggers c++ to clear the screen

					// Reprints menu
					cout << "Alright, what do you wanna see?" << endl;
					cout << "Select the number for the option you want" << endl;
					cout << "1.Death Blow" << endl; 
					cout << "2.My Dear Why Do You Cry So?" << endl;
					cout << "3.The Instantly Forgotten Story" << endl;
					cout << "4.Not sure (Movie Descriptions)" << endl;
					cout << "5.I think I'm good thanks (leave ticket menu)" << endl;
					cout << "Invalid! Please select a number from 1 - 5: ";
				}
				cout << "\033[2J\033[1;1H"; // Clears screen
				// The functionality to buy tickets 
				// ### Death Blow ### // (Option #1)
				if (input == 1 && user->GetAge() >= 18){ // If Death Blow and old enough

					if (DeathBlow->get_availability() || user->GetMoney() >= DeathBlow->get_price()){
						cout << "DeathBlow price: $" << DeathBlow->get_price() << endl;
						cout << "Original money balance: $" << user->GetMoney() << endl;
						user->AddTicket(DeathBlow->get_title());  // Buying the ticket
						user->SetMoney(user->GetMoney()-DeathBlow->get_price());
						cout << "New money balance: $" << user->GetMoney() << endl;
						cout << "'Okay, 1 for Death Blow'" << endl;
						Pause();
						cout << "\033[2J\033[1;1H";
					}
					else{
						cout << "Oh, no can do, it's full, or it's too expensive, whatever stop bugging me." << endl;	
						Pause();
						cout << "\033[2J\033[1;1H";
					}
				}
				// if user is too young to watch Death Blow
				else if (input == 1 && user->GetAge() < 18){
					cout << "Oh, no can do. It appears you're too young. Sorry buddy!" << endl;	
					Pause();
					cout << "\033[2J\033[1;1H";
				}

				// ### My Dear Why You So Cry ### // (Option #2)
				else if (input == 2 && user->GetAge() >= 14) { // If My Dear Why You So Cry and old enough
					if (MyDear->get_availability() || user->GetMoney() >= MyDear->get_price()){
						cout << "My Dear Why You So Cry price: $" << MyDear->get_price() << endl;
						cout << "Original money balance: $" << user->GetMoney() << endl;
						user->AddTicket(MyDear->get_title());  // Buying the ticket
						user->SetMoney(user->GetMoney()-MyDear->get_price());
						cout << "New money balance: $" << user->GetMoney() << endl;
						cout << "Okay, 1 for My Dear Why You So Cry" << endl;
						Pause();
						cout << "\033[2J\033[1;1H";
					}
					else {
						cout << "Oh, no can do, it's full, or it's too expensive, whatever stop bugging me." << endl;
						Pause();
						cout << "\033[2J\033[1;1H";
					}
				}
				// if user is too young to watch My Dear Why You So Cry
				else if (input == 2 && user->GetAge() < 14) {
					cout << "Oh, no can do. It appears you're too young. Sorry buddy!" << endl;	
					Pause();
					cout << "\033[2J\033[1;1H";
				}

				// ### The Instantly Forgotten Story ### // (Option #3)
				else if(input == 3){ // The Instantly Forgotten Story
					if (InstantForget->get_availability() || user->GetMoney() >= InstantForget->get_price()){
						cout << "The Instantly Forgotten Story price: $" << InstantForget->get_price() << endl;
						cout << "Original money balance: $" << user->GetMoney() << endl;
						user->AddTicket(InstantForget->get_title());  // Buying the ticket
						user->SetMoney(user->GetMoney()-InstantForget->get_price());
						cout << "New money balance: $" << user->GetMoney() << endl;
						cout << "Okay, 1 for The Instantly Forgotten Story" << endl;
						Pause();
						cout << "\033[2J\033[1;1H";
					}
					else {
						cout << "Oh, no can do, it's full, or it's too expensive, whatever stop bugging me." << endl;	
						Pause();
						cout << "\033[2J\033[1;1H";	
					}
				}

				// ### Chosing to be told about the movie information ### // (Option #4)
				else if (input == 4){
					bool details = true;

					// ## Movie Detail display while loop ## //
					while (details == true) {
					cout << "\033[2J\033[1;1H"; // Screen Clear
					cout << "Which movie do you want to hear about?" << endl;
					cout << "Select the number for the option you want" << endl;
					cout << "1.Death Blow" << endl; 
					cout << "2.My Dear Why Do You Cry So?" << endl;
					cout << "3.The Instantly Forgotten Story" << endl;

					// User Description input
					while (!(cin >> input) || (input < 1 && input > 3)) { 	// Verification that the user inputs a valid number into the 
						cin.clear ();
						cin.ignore (100,'\n'); // Clears input stream
						cout << "\033[2J\033[1;1H"; // Speical character combonation that triggers c++ to clear the screen

						// Reprints menu
						cout << "Which movie do you want to hear about?" << endl;
						cout << "Select the number for the option you want" << endl;
						cout << "1.Death Blow" << endl; 
						cout << "2.My Dear Why Do You Cry So?" << endl;
						cout << "3.The Instantly Forgotten Story" << endl;;
						cout << "Invalid! Please select a number from 1 - 3: ";
					}
					cout << "\033[2J\033[1;1H"; // Clears screen

					// ## Death Blow Information ## //
					if (input == 1) {
						cout << DeathBlow -> get_title() << endl; //setting the newmovies' title to the default one.
        				cout << "Genre: " << DeathBlow -> get_genre() << endl; //setting the newmovies' genre to the default one.
						cout << "Rating: " << DeathBlow -> get_rating() << "+" << endl; //setting the newmovies' rating to the default one.
        				cout << "Price: $" << DeathBlow -> get_price() << endl; //setting the newmovies' price to the default one.
						if(DeathBlow->get_availability() == true){ // Avalibility check
            				cout << "Avaliabilable?: Yes!" << endl; // The inferface for the user when the tickets aren't sold out
        				}
						else {
            				cout << "Avaliabilable?: Nah, sorry" << endl; // The inferface for the user when the tickets are sold out
        				}
						cout << endl;
						Pause();
						details = false;	
        			}

					// ## My Dear Why You So Cry Information ## //
					else if (input == 2) {
						cout << MyDear -> get_title() << endl; //setting the newmovies' title to the default one.
        				cout << "Genre: " << MyDear -> get_genre() << endl; //setting the newmovies' genre to the default one.
						cout << "Rating: " << MyDear -> get_rating() << "+" << endl; //setting the newmovies' rating to the default one.
        				cout << "Price: $" << MyDear -> get_price() << endl; //setting the newmovies' price to the default one.
						if(MyDear->get_availability() == true){ // Avalibility check
            				cout << "Avaliabilable?: Yes!" << endl; // The inferface for the user when the tickets aren't sold out
        				}
						else {
            				cout << "Avaliabilable?: Nah, sorry" << endl; // The inferface for the user when the tickets are sold out
        				}
						cout << endl;
						Pause();
						details = false;	
        			}

					// ## The Instantly Forgotten Story ## //
					else {
						cout << InstantForget -> get_title() << endl; //setting the newmovies' title to the default one.
        				cout << "Genre: " << InstantForget -> get_genre() << endl; //setting the newmovies' genre to the default one.
						cout << "Rating: " << InstantForget -> get_rating() << "+" << endl; //setting the newmovies' rating to the default one.
        				cout << "Price: $" << InstantForget -> get_price() << endl; //setting the newmovies' price to the default one.
						if(InstantForget->get_availability() == true){ // Avalibility check
            				cout << "Avaliabilable?: Yes!" << endl; // The inferface for the user when the tickets aren't sold out
        				}
						else {
            				cout << "Avaliabilable?: Nah, sorry" << endl; // The inferface for the user when the tickets are sold out
        				}
						cout << endl;
						Pause();
						details = false;	
					}
					}
				}				
				// Leaving Ticket Menu (Option #5)
				else {
					ticketMenu = false;
				}
			input = 0;
			}
		}
		// ## Candy Bar Menu ## //
		if (input == 2){
			
			candyMenu = true; // sets candy bar menu to true

			 // Opens Candy bar menu
			while (candyMenu == true){ // Printed Candy Bar options on menu
				cout << "\033[2J\033[1;1H"; // Clears screen
				
				// Shop menu
				cout << "Welcome to Candy-lation" << endl;
				cout << "Select the number for the option you want" << endl;
				cout << "1.Slushie" << endl; 
				cout << "2.Cola" << endl;
				cout << "3.Popcorn" << endl;
				cout << "4.Choc Top" << endl;
				cout << "5.Chocolate Frog" << endl;
				cout << "6.Water" << endl;
				cout << "7.Leave" << endl << ": ";

				// User Candy Shop input
				while (!(cin >> input) || (input < 1 && input > 7)) { 	// Verification that the user inputs a valid number into the 
					cin.clear ();
					cin.ignore (100,'\n'); // Clears input stream
					cout << "\033[2J\033[1;1H"; // Special character combonation that triggers c++ to clear the screen

					// Reprints menu
					cout << "Welcome to Candy-lation" << endl;
					cout << "Select the number for the option you want" << endl;
					cout << "1.Slushie" << endl; 
					cout << "2.Cola" << endl;
					cout << "3.Popcorn" << endl;
					cout << "4.Choc Top" << endl;
					cout << "5.Chocolate Frog" << endl;
					cout << "6.Water" << endl;
					cout << "7.Leave" << endl;
					cout << "Invalid! Please select a number from 1 - 7: ";
				}
				cout << "\033[2J\033[1;1H"; // Clears screen
				// ## Food Menu Options (Based on user input) ## //
				switch (input) {
					case 1:	// Buying Slushie (Option #1)
						if (user->GetMoney() >= slushie->GetItemValue()){
							cout << "Slushie Price: $" << slushie->GetItemValue() << endl;
							cout << "Original money balance: $" << user->GetMoney() << endl;
							user->AddFood(slushie->GetName());  								// Buying the food (adds to inventory)
							user->SetMoney(user->GetMoney()-slushie->GetItemValue());			// Deducts user's money
							cout << "New money balance: $" << user->GetMoney() << endl;
							cout << "Okay, 1 slushie" << endl << endl;
						}
						else {
							cout << "Dude, that's outta your price range..." << endl; // When the user can't afford it
						}
						Pause();
						break;
					case 2: // Buying Cola (Option #2)
						if (user->GetMoney() >= cola->GetItemValue()){
							cout << "Cola Price: $" << cola->GetItemValue() << endl;
							cout << "Original money balance: $" << user->GetMoney() << endl;
							user->AddFood(cola->GetName());  								// Buying the food (adds to inventory)
							user->SetMoney(user->GetMoney()-cola->GetItemValue());			// Deducts user's money
							cout << "New money balance: $" << user->GetMoney() << endl;
							cout << "Okay, 1 cola" << endl << endl;
						}
						else {
							cout << "Dude, that's outta your price range..." << endl << endl; // When the user can't afford it
						}
						Pause();
						break;
					case 3: // Buying Popcorn (Option #3)
						if (user->GetMoney() >= Popcorn->GetItemValue()){
							cout << "Popcorn Price: $" << Popcorn->GetItemValue() << endl;
							cout << "Original money balance: $" << user->GetMoney() << endl;
							user->AddFood(Popcorn->GetName());  								// Buying the food (adds to inventory)
							user->SetMoney(user->GetMoney()-Popcorn->GetItemValue());			// Deducts user's money
							cout << "New money balance: $" << user->GetMoney() << endl;
							cout << "Okay, 1 popcorn" << endl << endl;
						}
						else {
							cout << "Dude, that's outta your price range" << endl << endl; // When the user can't afford it	
						}
						Pause();
						break;
					case 4: // Buying Choc Top (Option #4)
						if (user->GetMoney() >= choctop->GetItemValue()){
							cout << "Choc Top Price: $" << choctop->GetItemValue() << endl;
							cout << "Original money balance: $" << user->GetMoney() << endl;
							user->AddFood(choctop->GetName());  								// Buying the food (adds to inventory)
							user->SetMoney(user->GetMoney()-choctop->GetItemValue());			// Deducts user's money
							cout << "New money balance: $" << user->GetMoney() << endl;
							cout << "Okay, 1 choc top" << endl << endl;
						}
						else {
							cout << "Dude, that's outta your price range" << endl << endl;	 // When the user can't afford it	
						}
						Pause();
						break;
					case 5: // Buying Chocolate Frogs (Option #5)
						if (user->GetMoney() >= chocolatefrog->GetItemValue()){
							cout << "Chocolate Frog Price: $" << chocolatefrog->GetItemValue() << endl;
							cout << "Original money balance: $" << user->GetMoney() << endl;
							user->AddFood(chocolatefrog->GetName());  								// Buying the food (adds to inventory)
							user->SetMoney(user->GetMoney()-chocolatefrog->GetItemValue());			// Deducts user's money
							cout << "New money balance: $" << user->GetMoney() << endl;
							cout << "Okay, 1 chocolate frog" << endl << endl;
						}
						else {
							cout << "Dude, that's outta your price range" << endl << endl;	 // When the user can't afford it	
						}
						Pause();
						break;
					case 6: // Buying Water (Option #6)
						if (user->GetMoney() >= water->GetItemValue()){
							cout << "Water Price: $" << water->GetItemValue() << endl;
							cout << "Original money balance: $" << user->GetMoney() << endl;
							user->AddFood(water->GetName());  								// Buying the food (adds to inventory)
							user->SetMoney(user->GetMoney()-water->GetItemValue());			// Deducts user's money
							cout << "New money balance: $" << user->GetMoney() << endl;
							cout << "Okay, 1 water" << endl << endl;
						}
						else {
							cout << "Dude, that's outta your price range" << endl << endl;	 // When the user can't afford it
						}
						Pause();
						break;
					case 7: // Leave menu (Option #7)
						candyMenu = false; // sets candy bar menu to true
				}
				cout << "\033[2J\033[1;1H"; // Clears screen
				input = 0;
			}
		}
		// ###### Sends  user to theatre (watch sequence) ############
		if (input == 3){ // Checks for ticket and if it exists, removes it and enters Movie watching sequence 
			cout << "\033[2J\033[1;1H"; // Speical character combonation that triggers c++ to clear the screen

			bool check = false; // Check variable for the ticket in inventory check

			// ### Movie ticket check while loop ### //
			while(check == false){
			
			cout << "\033[2J\033[1;1H"; // Special character combonation that triggers c++ to clear the scree
			// Movie ticket request menu
				cout << "Tickets please, which movie are you seeing?" << endl;
				cout << "Select the number from the options" << endl;
				cout << "1.Death Blow" << endl; 
				cout << "2.My Dear Why Do You Cry So?" << endl;
				cout << "3.The Instantly Forgotten Story" << endl;
				cout << "4.Leave" << endl << ": ";

			// User input to get with movie they want to see
			while (!(cin >> input) || (input < 1 && input > 4)) { 	// Verification that the user inputs a valid number
				cin.clear ();
				cin.ignore (100,'\n'); // Clears input stream
				cout << "\033[2J\033[1;1H"; // Special character combonation that triggers c++ to clear the screen

				// Movie ticket request menu (reprints)
				cout << "Tickets please, which movie are you seeing?" << endl;
				cout << "Select the number from the options" << endl;
				cout << "1.Death Blow" << endl; 
				cout << "2.My Dear Why Do You Cry So?" << endl;
				cout << "3.The Instantly Forgotten Story" << endl;
				cout << "4.Leave" << endl << ": ";
			}
			cout << "\033[2J\033[1;1H"; // Special character combonation that triggers c++ to clear the scree
			switch(input){
				case 1: // Death Blow ticket check (Option #1)
					// If the user has a ticket
					if(user -> TicketCheck(DeathBlow->get_title()) == true) {
						watchmoviecurrent = DeathBlow->get_title(); 
		    			cout << "*hands over ticket and enters the cinema*..." << endl;
						sleep(1);
						watch = true;
		    			check = true;
						menu = false;
						break;
						// => To watch movie loop
		    		}
					// If the user doesn't have a ticket
					else {
		    			cout << "Oh man, where is my ticket?..." << endl;
						Pause();
						break;
						// => Back to watch movie menu
		    		}
				case 2: // My Dear Why Do You Cry So ticket check (Option #2)
					// If the user has a ticket
					if(user -> TicketCheck(MyDear->get_title()) == true) {
						watchmoviecurrent = MyDear->get_title();
		    			cout << "*hands over ticket and enters the cinema*..." << endl;
						sleep(1);
						watch = true;
		    			check = true;
						menu = false;
						break;
						// => To watch movie loop
		    		}
					// If the user doesn't have a ticket
					else {
		    			cout << "Oh man, where is my ticket?..." << endl;
						Pause();
						break;
						// => Back to watch movie menu
		    		}

				case 3: // The Instantly Forgotten Story ticket check (Option #3)
					// If the user has a ticket
					if(user -> TicketCheck(InstantForget->get_title()) == true) {
						watchmoviecurrent = InstantForget->get_title();
		    			cout << "*hands over ticket and enters the cinema*..." << endl;
						sleep(1);
						watch = true;
		    			check = true;
						menu = false;
						break;
						// => To watch movie loop
		    		}
					// If the user doesn't have a ticket
					else {
		    			cout << "Oh man, where is my ticket?..." << endl;
						Pause();
						break;
		    		}
				case 4: // Leave option (Option #4)
					cout << "\033[2J\033[1;1H"; // Speical character combonation that triggers c++ to clear the screen
					watch = false;
					check = true;
					break;
					// => Back to cinema main menu

				default: // Filters out anything that isn't 1-4
					cout << "Invalid ticket! Please enter a number!: " << endl;
					cin.clear ();
					cin.ignore ( 200 , '\n' );  // Clears input stream
				}
			}
		input = 0;
		}
		// ###### Leaves the cinema and menu ############## 
		if (input == 4){
			cinema = false;
			menu = false;
		}

	}
	menu = true; // If you break out of the watch loop, you will go back into the menu
	// ###################################################################


	// ########################
	// ### Movie watch loop ###
	// ########################
	while (watch == true) {
	
		// Movie dialogue
		cout << "Watches ads..." << endl;
		sleep(2); // Sleeps for a given amount of seconds
		cout << endl << "*The title '" << watchmoviecurrent << "' appears on the screen*" << endl;
		sleep(2);
		cout << "*Laughing noises*" << endl;
		sleep(2);
		cout << "*Munching noises from behind*..." << endl;
		sleep(2);
		if ((user->GetHunger()) < 6) {
			cout << "*grumble noises*..." << endl;
		}

		// ######## EATING! #################
		bool check = false; // Checker for loops

		// Food dialogue
		cout << "All that munching makes you hungry";
		cout << endl << "You go to eat items..." << endl;
		sleep(1);

		while (user->EatItem(choctop->GetName(), choctop->GetHungerRestore())== true){	// Eats all choc tops from inventory
			choctop -> consumePrint();
			sleep(1);
			check = true;
		}
		while (user->EatItem(chocolatefrog->GetName(), chocolatefrog->GetHungerRestore())==true){
			chocolatefrog -> consumePrint();
			sleep(1);
			check = true;
		}
		while (user->EatItem(cola->GetName(), cola->GetHungerRestore())==true){
			cola -> consumePrint();
			sleep(1);
			check = true;
		}
		while (user->EatItem(Popcorn->GetName(), Popcorn->GetHungerRestore())==true){
			Popcorn -> consumePrint();
			sleep(1);
			check = true;
		}
		while (user->EatItem(slushie->GetName(), slushie->GetHungerRestore())==true){
			slushie -> consumePrint();
			sleep(1);
			check = true;
		}
		while (user->EatItem(water->GetName(), water->GetHungerRestore())==true){
			water -> consumePrint();
			sleep(1);
			check = true;
		}

		if(check == false){
			cout << "...but you have no food :(" << endl;
		}
		else {
			cout << "...All that food was good! :D" << endl;
			sleep(2);
		}
		

		sleep(2); // delay after eating

		// ############## Intermission ################n
		check = false;

		// Intemission while loop
		while (check == false) {
		cout << "\033[2J\033[1;1H";
		cin.clear ();
		// Intermission options
		cout << "It's half way through, do you want to go to the toilet or the Candy Bar?" << endl;
		cout << "Select the number from the options" << endl;
		cout << "1.More Food!" << endl; 
		cout << "2.Toilet!" << endl;
		cout << "3.Back to the movie!" << endl;

		// User input filter for Intermission Menu
		while (!(cin >> input) || (input < 1 && input > 3)) { 	// Verification that the user inputs a valid number into the 
			cin.clear ();
			cin.ignore (100,'\n'); // Clears input stream
			cout << "\033[2J\033[1;1H"; // Special character combonation that triggers c++ to clear the screen
			cout << "It's half way through, do you want to go to the toilet or the Candy Bar?" << endl;
			cout << "Select the number from the options" << endl;
			cout << "1.More Food!" << endl; 
			cout << "2.Toilet!" << endl;				
			cout << "3.Back to the movie!" << endl << ": " << endl;
		}
	
		// Intermission switch statement to acts based on user input
		switch (input) {
			case 1:  // Brings user to the candy bar (Option #1)
				candyMenu = true; // sets candy bar menu to true

				 // Opens Candy bar menu
				while (candyMenu == true){ // Printed Candy Bar options on menu
				cout << "\033[2J\033[1;1H"; // Clears screen
				
				// Shop menu
				cout << "Welcome to Candy-lation" << endl;
				cout << "Select the number for the option you want" << endl;
				cout << "1.Slushie" << endl; 
				cout << "2.Cola" << endl;
				cout << "3.Popcorn" << endl;
				cout << "4.Choc Top" << endl;
				cout << "5.Chocolate Frog" << endl;
				cout << "6.Water" << endl;
				cout << "7.Leave" << endl << ": ";

				// User Candy Shop input
				while (!(cin >> input) || (input < 1 && input > 7)) { 	// Verification that the user inputs a valid number into the 
					cin.clear ();
					cin.ignore (100,'\n'); // Clears input stream
					cout << "\033[2J\033[1;1H"; // Special character combonation that triggers c++ to clear the screen

					// Reprints menu
					cout << "Welcome to Candy-lation" << endl;
					cout << "Select the number for the option you want" << endl;
					cout << "1.Slushie" << endl; 
					cout << "2.Cola" << endl;
					cout << "3.Popcorn" << endl;
					cout << "4.Choc Top" << endl;
					cout << "5.Chocolate Frog" << endl;
					cout << "6.Water" << endl;
					cout << "7.Leave" << endl;
					cout << "Invalid! Please select a number from 1 - 7: ";
				}
				cout << "\033[2J\033[1;1H"; // Clears screen
				// ## Food Menu Options (Based on user input) ## //
				switch (input) {
					case 1:	// Buying Slushie (Option #1)
						if (user->GetMoney() >= slushie->GetItemValue()){
							cout << "Slushie Price: $" << slushie->GetItemValue() << endl;
							cout << "Original money balance: $" << user->GetMoney() << endl;
							user->AddFood(slushie->GetName());  								// Buying the food (adds to inventory)
							user->SetMoney(user->GetMoney()-slushie->GetItemValue());			// Deducts user's money
							cout << "New money balance: $" << user->GetMoney() << endl;
							cout << "Okay, 1 slushie" << endl << endl;
						}
						else {
							cout << "Dude, that's outta your price range..." << endl; // When the user can't afford it
						}
						Pause();
						break;
					case 2: // Buying Cola (Option #2)
						if (user->GetMoney() >= cola->GetItemValue()){
							cout << "Cola Price: $" << cola->GetItemValue() << endl;
							cout << "Original money balance: $" << user->GetMoney() << endl;
							user->AddFood(cola->GetName());  								// Buying the food (adds to inventory)
							user->SetMoney(user->GetMoney()-cola->GetItemValue());			// Deducts user's money
							cout << "New money balance: $" << user->GetMoney() << endl;
							cout << "Okay, 1 cola" << endl << endl;
						}
						else {
							cout << "Dude, that's outta your price range..." << endl << endl; // When the user can't afford it
						}
						Pause();
						break;
					case 3: // Buying Popcorn (Option #3)
						if (user->GetMoney() >= Popcorn->GetItemValue()){
							cout << "Popcorn Price: $" << Popcorn->GetItemValue() << endl;
							cout << "Original money balance: $" << user->GetMoney() << endl;
							user->AddFood(Popcorn->GetName());  								// Buying the food (adds to inventory)
							user->SetMoney(user->GetMoney()-Popcorn->GetItemValue());			// Deducts user's money
							cout << "New money balance: $" << user->GetMoney() << endl;
							cout << "Okay, 1 popcorn" << endl << endl;
						}
						else {
							cout << "Dude, that's outta your price range" << endl << endl; // When the user can't afford it	
						}
						Pause();
						break;
					case 4: // Buying Choc Top (Option #4)
						if (user->GetMoney() >= choctop->GetItemValue()){
							cout << "Choc Top Price: $" << choctop->GetItemValue() << endl;
							cout << "Original money balance: $" << user->GetMoney() << endl;
							user->AddFood(choctop->GetName());  								// Buying the food (adds to inventory)
							user->SetMoney(user->GetMoney()-choctop->GetItemValue());			// Deducts user's money
							cout << "New money balance: $" << user->GetMoney() << endl;
							cout << "Okay, 1 choc top" << endl << endl;
						}
						else {
							cout << "Dude, that's outta your price range" << endl << endl;	 // When the user can't afford it	
						}
						Pause();
						break;
					case 5: // Buying Chocolate Frogs (Option #5)
						if (user->GetMoney() >= chocolatefrog->GetItemValue()){
							cout << "Chocolate Frog Price: $" << chocolatefrog->GetItemValue() << endl;
							cout << "Original money balance: $" << user->GetMoney() << endl;
							user->AddFood(chocolatefrog->GetName());  								// Buying the food (adds to inventory)
							user->SetMoney(user->GetMoney()-chocolatefrog->GetItemValue());			// Deducts user's money
							cout << "New money balance: $" << user->GetMoney() << endl;
							cout << "Okay, 1 chocolate frog" << endl << endl;
						}
						else {
							cout << "Dude, that's outta your price range" << endl << endl;	 // When the user can't afford it	
						}
						Pause();
						break;
					case 6: // Buying Water (Option #6)
						if (user->GetMoney() >= water->GetItemValue()){
							cout << "Water Price: $" << water->GetItemValue() << endl;
							cout << "Original money balance: $" << user->GetMoney() << endl;
							user->AddFood(water->GetName());  								// Buying the food (adds to inventory)
							user->SetMoney(user->GetMoney()-water->GetItemValue());			// Deducts user's money
							cout << "New money balance: $" << user->GetMoney() << endl;
							cout << "Okay, 1 water" << endl << endl;
						}
						else {
							cout << "Dude, that's outta your price range" << endl << endl;	 // When the user can't afford it
						}
						Pause();
						break;
					case 7: // Leave menu (Option #7)
						input = 0;
						cout << "\033[2J\033[1;1H"; // Clears screen
						candyMenu = false; // sets candy bar menu to true
						break;
				}
				cout << "\033[2J\033[1;1H"; // Clears screen
				}
				break;
			case 2: // User goes to the toilet (Option #2)
				cout << "\033[2J\033[1;1H"; // Clears screen
				cout << "MhhhhhhhmmmmmmmmmmmmmmmmmmmmmmmMMMMMM..." << endl;
				sleep(2);
				cout << "ahhhhhhhhhhhhhhhh!" << endl;
				sleep(2);
				cout << "That felt good..." << endl;
				sleep(2);
				cout << ":)" << endl;
				sleep(2);
				cout << "\033[2J\033[1;1H"; // Clears screen
				break;
			case 3: // User goes back to the movie! (Option #3)
				cout << "\033[2J\033[1;1H"; // Clears screen
				cout << "Back to the movie then!..." << endl;
				sleep(2);
				check = true;
				break;
		}
		}


		// ########### Second eating phase #############		(Eat items you bought in intermission)
		check = false; // Resetting check for second phase
		cout << "You go to eat items..." << endl;
		sleep(2);
		while (user->EatItem(choctop->GetName(), choctop->GetHungerRestore())==true){
			choctop -> consumePrint();
			sleep(1);
			check = true;
		}
		while (user->EatItem(chocolatefrog->GetName(), chocolatefrog->GetHungerRestore())==true){
			chocolatefrog -> consumePrint();
			sleep(1);
			check = true;
		}
		while (user->EatItem(cola->GetName(), cola->GetHungerRestore())==true){
			cola -> consumePrint();
			sleep(1);
			check = true;
		}
		while (user->EatItem(Popcorn->GetName(), Popcorn->GetHungerRestore())==true){
			Popcorn -> consumePrint();
			sleep(1);
			check = true;
		}
		while (user->EatItem(slushie->GetName(), slushie->GetHungerRestore())==true){
			slushie -> consumePrint();
			sleep(1);
			check = true;
		}
		while (user->EatItem(water->GetName(), water->GetHungerRestore())==true){
			water -> consumePrint();
			sleep(1);
			check = true;
		}

		if(check == false){
			cout << "...But you have no food :(" << endl;
			sleep(3);
		}
		else {
			cout << "All that food was good! :D" << endl;
			sleep(3);
		}

		// More movie dialogue
		cout << "*action noises*" << endl;
		sleep(2);
		cout << "*credits rolling*..." << endl;
		sleep(2);

		// ##### Post Movie Options #### //
		cout << "\033[2J\033[1;1H"; // Speical character combonation that triggers c++ to clear the screen

		// Post movie menu options
		cout << "Well, that was hours of my life I'll never get back haha!" << endl;
		cout << "Select the number from the options" << endl;
		cout << "1.More movies! To the Movie Desk!" << endl; 
		cout << "2.Leave all of this, I hate this place" << endl << ": ";

		// Post movie input
		while (!(cin >> input) || (input < 1 && input > 2)) { 	// Verification that the user inputs a valid number into the 
			cin.clear ();
			cin.ignore (100,'\n'); // Clears input stream
			cout << "\033[2J\033[1;1H"; // Special character combonation that triggers c++ to clear the screen
			cout << "Well, that was hours of my life I'll never get back haha!" << endl;
			cout << "Select the number from the options" << endl;
			cout << "1.More movies! To the Movie Desk!" << endl; 
			cout << "2.Leave all of this, I hate this place" << endl << ": ";
		}

		if (input == 1){
			watch = false;
			menu = true;
			// => Goes back to Cinema Main Menu
		}

		if (input == 2){
			watch = false;
			menu = false;
			cinema = false;
			// => Quits the code
		}	
	}
	// ########################
	}

	//Deconstructor (Prevents memory leak after code ends)
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
