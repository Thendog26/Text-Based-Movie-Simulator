// Water testing main
#include <iostream>
#include <string>
#include <ctime>
#include "Player.h"
#include "Water.h"

using namespace std;

int main(){

	cout << "## Water class testing ##" << endl;
	cout << endl;

	// Variable initiallising
	Player *a;
	a = new Player();
	srand(time(NULL)); //Sets inprogram time for rand() functions

	Water *water;
	water = new Water();

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

	// Base Water info
	cout << " ~ Water generated information ~" << endl;
	cout << "Item: " << water->GetName() << endl;
	cout << "Value: $" << water->GetItemValue() << endl;
	cout << "Generated hunger restore value: " << water->GetHungerRestore() << endl;
	cout << endl << endl;

	// Test 1 - ConsumePrint Message
 	cout << "Test 1 - Print Consumption Message" << endl;
	cout << "Original Consumption message: Gulp, gulp, gulp" << endl;
	cout << "Function Print attempt: "; water->consumePrint();
	cout << endl;

	// Test 2 - Fill inventory through Get Water functions
	cout << "Test 2 - Fill player inventory through Get Water function (add 2 Waters and attempt to eat 3)" << endl;
	// Buying
	cout << "Buying Phase ~" << endl;
	cout << "Original money balance: $" << a->GetMoney() << endl;
	a->AddFood(water->GetName());  // Water 1
	a->SetMoney(a->GetMoney()-water->GetItemValue());
	cout << "After 1st Water money balance: $" << a->GetMoney() << endl;
	a->AddFood(water->GetName());  // Water 2
	a->SetMoney(a->GetMoney()-water->GetItemValue());
	cout << "After 2nd Water money balance: $" << a->GetMoney() << endl;
	cout << endl;
	// Drinking
	cout << "Drinking Phase ~" << endl;
	cout << "Original Hunger: " << a->GetHunger() << endl;
	a->EatItem(water->GetName(), water->GetHungerRestore());
	cout << "Updated Hunger (1st Water): " << a->GetHunger() << endl;
	a->EatItem(water->GetName(), water->GetHungerRestore());
	cout << "Updated Hunger (2nd Water): " << a->GetHunger() << endl;
	cout << "Attempt to drink Water that isn't in inventory... " << endl;
	a->EatItem(water->GetName(), water->GetHungerRestore());
	cout << "Updated Hunger: " << a->GetHunger() << endl;
	cout << endl;

	// Test 3 - Item Hunger Generation test
	cout << "Test 3 - Item Hunger Generation test (should be only between 2 and 5)" << endl;
	for (int i = 0; i < 5; i++) {
		delete water;
		Water *water;
		water = new Water();
		cout << "Loop count: " << i << endl;
		cout << "Hunger restoration value: " << water->GetHungerRestore() << endl;
	}
	cout << endl;
	delete a, water;
}
