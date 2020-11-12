// Player class testing main
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <unistd.h>
#include "Player.h"

using namespace std;

int main() {
	cout << "## Player class testing ##" << endl;
	// Intialising object
	Player *a;
	a = new Player();
	srand(time(NULL)); //Sets inprogram time for rand() functions

	//Test 1 - Populating class and print function tests
	cout << "Test 1 ~ Populate" << endl;
	a->SetName("Jimmy");
	cout << "Name: " << a->GetName() << endl;
	a->SetAge(15);
	cout << "Age: " << a->GetAge() << endl;
	a->GenerateHunger();
	cout << "Hunger: " << a->GetHunger() << endl;
	a->GenerateMoney();
	cout << "Balance: " << a->GetMoney() << endl;
	cout << endl << endl;

	//Test 2 - Generation mechanics
	cout << "Test 2 ~ Generation Mechanics" << endl;
	cout << "Example 1 - Age 10 (between $10-$20)" << endl;
	a->SetAge(10);
	for (int i = 0; i < 3; i++) {
		cout << endl;
		cout << "Loop Cycle: " << i+1 << endl;
		a->GenerateHunger();
		cout << "Hunger: " << a->GetHunger() << endl;
		a->GenerateMoney();
		cout << "Balance: " << a->GetMoney() << endl;
		cout << endl;
		//sleep(1);
	}

	cout << "Example 2 - Age 16(between $20-$40)" << endl;
	a->SetAge(16);
	for (int i = 0; i < 3; i++) {
		cout << endl;
		cout << "Loop Cycle: " << i+1 << endl;
		a->GenerateHunger();
		cout << "Hunger: " << a->GetHunger() << endl;
		a->GenerateMoney();
		cout << "Balance: " << a->GetMoney() << endl;
		cout << endl;
		//sleep(1);
	}

	cout << "Example 3 - Age 21(between $40-$100)" << endl;
	a->SetAge(21);
	for (int i = 0; i < 3; i++) {
		cout << endl;
		cout << "Loop Cycle: " << i+1 << endl;
		a->GenerateHunger();
		cout << "Hunger: " << a->GetHunger() << endl;
		a->GenerateMoney();
		cout << "Balance: " << a->GetMoney() << endl;
		cout << endl;
		//sleep(1);
	}

	cout << "Example 4 - Age 30(between $1000-$5000)" << endl;
	a->SetAge(30);
	for (int i = 0; i < 3; i++) {
		cout << endl;
		cout << "Loop Cycle: " << i+1 << endl;
		a->GenerateHunger();
		cout << "Hunger: " << a->GetHunger() << endl;
		a->GenerateMoney();
		cout << "Balance: " << a->GetMoney() << endl;
		cout << endl;
		//sleep(1);
	}
	cout << endl << endl;

	//Test 3 - Ticket mechanics
	cout << "Test 3 ~ Ticket add and check function (Give 2 tickets, request to use 3)" << endl;
	a->AddTicket("Death blow");
	a->AddTicket("Death blow");
	a->AddTicket("Instantly Forgotten Story");
	a->AddTicket("Instantly Forgotten Story");
	cout << "Death blow status: " << a->TicketCheck("Death blow") << endl;
	cout << "Death blow status: " << a->TicketCheck("Death blow") << endl;
	cout << "Death blow status: " << a->TicketCheck("Death blow") << endl;
	cout << "Instantly Forgotten Story status: " << a->TicketCheck("Instantly Forgotten Story") << endl;
	cout << "Instantly Forgotten Story status: " << a->TicketCheck("Instantly Forgotten Story") << endl;
	cout << "Instantly Forgotten Story status: " << a->TicketCheck("Instantly Forgotten Story") << endl;
	cout << endl;

	//Test 4 - Food mechanics
	cout << "Test 4 ~ Food mechanics (Add one of each and eat them all)" << endl;
	cout << "Original Hunger: " << a->GetHunger() << endl;
	a->AddFood("Choc Top");
	a->AddFood("Chocolate Frog");
	a->AddFood("Popcorn");
	a->AddFood("Slushie");
	a->AddFood("Water");
	a->AddFood("Cola");
	a->EatItem("Choc Top", 2);
	cout << "Updated Hunger (Ate Choc Top): " << a->GetHunger() << endl;
	a->EatItem("Chocolate Frog", -2);
	cout << "Updated Hunger (Ate Choclate Frog): " << a->GetHunger() << endl;
	a->EatItem("Popcorn", 1);
	cout << "Updated Hunger(Ate Popcorn): " << a->GetHunger() << endl;
	a->EatItem("Slushie", 0);
	cout << "Updated Hunger (drank Slushie): " << a->GetHunger() << endl;
	a->EatItem("Water", 5);
	cout << "Updated Hunger (drank Water): " << a->GetHunger() << endl;
	a->EatItem("Cola", -2);
	cout << "Updated Hunger (drank Cola): " << a->GetHunger() << endl;
	cout << "Attempting to eat additional Choc Top not in inventory... " << endl;
	a->EatItem("Choc Top", 2);
	cout << "Hunger status?: " << a->GetHunger() << endl;
	cout << endl;

	delete a;
}
