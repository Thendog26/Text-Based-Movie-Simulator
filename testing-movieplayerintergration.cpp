// movie and player integration testing main
#include <iostream>
#include <string>
#include <ctime>
#include "Player.h"
#include "Movie.h"

using namespace std;

int main() {


	cout << "## Movie and Player integration testing ##" << endl;
	cout << endl;

	// Variable initiallising
	Player *a;
	a = new Player();
	srand(time(NULL)); //Sets inprogram time for rand() functions

	Movie *Mov1 = new Movie("The Instantly Forgotten Story", "Well, my little sister liked it.", 2, 9); //creating a movie pointer and assignig a movie class to the location.
	Mov1->Generate_Availability();
    Movie *Mov2 = new Movie("My Dear Why Do You Cry So?", "My girlfriend took me to see that, it's surprisingly poignant", 14, 13); //creating a movie pointer and assignig a movie class to the location.
	Mov2->Generate_Availability();
    Movie *Mov3 = new Movie("Death Blow", "Dude, it's totally awesome!", 18, 14); //creating a movie pointer and assignig a movie class to the location.
	Mov3->Generate_Availability();



    // Base player info
	cout << " ~ Player generated information ~" << endl;
	a->SetName("Jimmy");
	cout << "Name: " << a->GetName() << endl;
	a->SetAge(21);
	cout << "Age: " << a->GetAge() << endl;
	a->GenerateHunger();
	cout << "Hunger: " << a->GetHunger() << endl;
	a->GenerateMoney();
	cout << "Balance: $" << a->GetMoney() << endl;
	cout << endl << endl;

	cout << "~Example movie information~" << endl;
	cout << "Name: " << Mov1->get_title() << endl;
	cout << "Price: $" << Mov1->get_price() << endl;
	cout << "Genre: " << Mov1->get_genre () << endl;
	cout << "Rating: " << Mov1->get_rating() << "+" << endl;
	cout << "Avalible?: " << Mov1->get_availability() << endl << endl;

	//the movies already have their values, nothing needs to be set
	//try to buy two tickets
	//Buying tickets Instantly Forgotten Story
	cout << "Buying Phase ~" << endl;
	cout << "Original money balance: $" << a->GetMoney() << endl;
	a->AddTicket(Mov1->get_title());  // Instantly Forgotten Story ticket 1
	a->SetMoney(a->GetMoney()-Mov1->get_price());
	cout << "After 1st ticket money balance: $" << a->GetMoney() << endl;
	a->AddTicket(Mov1->get_title());  // Instantly Forgotten Story ticket 2
	a->SetMoney(a->GetMoney()-Mov1->get_price());
	cout << "After 2nd ticket money balance: $" << a->GetMoney() << endl; //Money being deducted, what is the new balance?
	//is the ticket in the inventory?
	bool availability = a -> TicketCheck(Mov1->get_title()); //setting the newmovies' availability to alternate 20% of the time like the default one.
    string cute_answer;

        if( availability == true){
        	cute_answer = "Here's my ticket";
        }else{
        	cute_answer = "Oh man, where is my ticket?";
        }
    cout << endl << "Tickets please? " << endl << endl << cute_answer << endl;
	cout << endl; 

	//have you got the second ticket? 
	
	bool availability2 = a -> TicketCheck(Mov1->get_title()); //setting the newmovies' availability to alternate 20% of the time like the default one.
		if( availability2 == true){
        	cute_answer = "Here's my ticket";
        }else{
        	cute_answer = "Oh man, where is my ticket?";
        }
	cout << endl << "Tickets please? " << endl << endl << cute_answer << endl;
	cout << endl; 
	

	//Can the money got negative


	//the movies already have their values, nothing needs to be set
	//try to buy two tickets
	//Buying tickets My_Dear_Why_Do_You_Cry_So
	cout << "Buying Phase ~" << endl;
	cout << "Original money balance: $" << a->GetMoney() << endl;
	a->AddTicket(Mov2->get_title());  // My_Dear_Why_Do_You_Cry_So ticket 1
	a->SetMoney(a->GetMoney()-Mov2->get_price());
	cout << "After 1st ticket money balance: $" << a->GetMoney() << endl;
	a->AddTicket(Mov2->get_title());  // My_Dear_Why_Do_You_Cry_So Story ticket 2
	a->SetMoney(a->GetMoney()-Mov2->get_price());
	cout << "After 2nd ticket money balance: $" << a->GetMoney() << endl; //Money being deducted, what is the new balance?
	//is the ticket in the inventory?
	bool availability5 = a -> TicketCheck(Mov2->get_title()); //setting the newmovies' availability to alternate 20% of the time like the default one.
    

        if( availability5 == true){
        	cute_answer = "Here's my ticket";
        }else{
        	cute_answer = "Oh man, where is my ticket?";
        }
    cout << endl << "Tickets please? " << endl << endl << cute_answer << endl;
	cout << endl; 

	//have you got the second ticket? 
	
	bool availability6 = a -> TicketCheck(Mov2->get_title()); //setting the newmovies' availability to alternate 20% of the time like the default one.

		if( availability6 == true){
        	cute_answer = "Here's my ticket";
        }else{
        	cute_answer = "Oh man, where is my ticket?";
        }
	cout << endl << "Tickets please? " << endl << endl << cute_answer << endl;
	cout << endl; 


	//the movies already have their values, nothing needs to be set
	//try to buy two tickets
	//Buying tickets Death Blow
	cout << "Buying Phase ~" << endl;
	cout << "Original money balance: $" << a->GetMoney() << endl;
	a->AddTicket(Mov3->get_title());  // Death Blow ticket 1
	a->SetMoney(a->GetMoney()-Mov3->get_price());
	cout << "After 1st ticket money balance: $" << a->GetMoney() << endl;
	a->AddTicket(Mov3->get_title());  // Death Blow Story ticket 2
	a->SetMoney(a->GetMoney()-Mov3->get_price());
	cout << "After 2nd ticket money balance: $" << a->GetMoney() << endl; //Money being deducted, what is the new balance?
	//is the ticket in the inventory?
	bool availability3 = a -> TicketCheck(Mov3->get_title()); //setting the newmovies' availability to alternate 20% of the time like the default one.
    

        if( availability3 == true){
        	cute_answer = "Here's my ticket";
        }else{
        	cute_answer = "Oh man, where is my ticket?";
        }
    cout << endl << "Tickets please? " << endl << endl << cute_answer << endl;
	cout << endl; 

	//have you got the second ticket? 
	
	bool availability4 = a -> TicketCheck(Mov3->get_title()); //setting the newmovies' availability to alternate 20% of the time like the default one.

		if( availability4 == true){
        	cute_answer = "Here's my ticket";
        }else{
        	cute_answer = "Oh man, where is my ticket?";
        }
	cout << endl << "Tickets please? " << endl << endl << cute_answer << endl;
	cout << endl; 

	cout<<endl;
    delete a;
    delete Mov1;
    delete Mov2;
    delete Mov3;

	return 0;
}
