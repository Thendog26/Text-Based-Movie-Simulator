// popcorn testing main
#include <iostream>
#include <string>
#include <ctime>
#include "Player.h"
#include "popcorn.h"

using namespace std;

int main(){

	cout << "## Popcorn class testing ##" << endl;
	cout << endl;

	// Variable initiallising
	Player *a;
	a = new Player();
	srand(time(NULL)); //Sets inprogram time for rand() functions

	popcorn *popcorn_pointer;
	popcorn_pointer = new popcorn();

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

	// Base popcorn_pointer info
	cout << " ~ Popcorn generated information ~" << endl;
	cout << "Item: " << popcorn_pointer->GetName() << endl;
	cout << "Value: $" << popcorn_pointer->GetItemValue() << endl;
	cout << "Generated hunger restore value: " << popcorn_pointer->GetHungerRestore() << endl;
	cout << endl << endl;

	// Test 1 - ConsumePrint Message
 	cout << "Test 1 - Print Consumption Message" << endl;
	cout << "Original Consumption message: Crunch, crunch" << endl;
	cout << "Function Print attempt: "; popcorn_pointer->consumePrint();
	cout << endl;

	// Test 2 - Fill inventory through Get popcorn functions
	cout << "Test 2 - Fill player inventory through Get popcorn function (add 2 popcorns and attempt to eat 3)" << endl;
	// Buying
	cout << "Buying Phase ~" << endl;
	cout << "Original money balance: $" << a->GetMoney() << endl;
	a->AddFood(popcorn_pointer->GetName());  // Popcorn 1
	a->SetMoney(a->GetMoney()-popcorn_pointer->GetItemValue());
	cout << "After 1st popcorn money balance: $" << a->GetMoney() << endl;
	a->AddFood(popcorn_pointer->GetName());  // Popcorn 2
	a->SetMoney(a->GetMoney()-popcorn_pointer->GetItemValue());
	cout << "After 2nd popcorn money balance: $" << a->GetMoney() << endl;
	cout << endl;
	// Eating
	cout << "Eating Phase ~" << endl;
	cout << "Original Hunger: " << a->GetHunger() << endl;
	a->EatItem(popcorn_pointer->GetName(), popcorn_pointer->GetHungerRestore());
	cout << "Updated Hunger (1st popcorn): " << a->GetHunger() << endl;
	a->EatItem(popcorn_pointer->GetName(), popcorn_pointer->GetHungerRestore());
	cout << "Updated Hunger (2nd popcorn): " << a->GetHunger() << endl;
	cout << "Attempt to eat popcorn that isn't in inventory... " << endl;
	a->EatItem(popcorn_pointer->GetName(), popcorn_pointer->GetHungerRestore());
	cout << "Updated Hunger: " << a->GetHunger() << endl;
	cout << endl;

	// Test 3 - Item Hunger Generation test
	cout << "Test 3 - Item Hunger Generation test (should be only between -1 and 1)" << endl;
	for (int i = 0; i < 5; i++) {
		delete popcorn_pointer;
		popcorn *popcorn_pointer;
		popcorn_pointer = new popcorn();
		cout << "Loop count: " << i << endl;
		cout << "Hunger restoration value: " << popcorn_pointer->GetHungerRestore() << endl;
	}
	cout << endl;
	delete a, popcorn_pointer;
}
