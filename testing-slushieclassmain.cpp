// Slushie testing main
#include <iostream>
#include <string>
#include <ctime>
#include "Player.h"
#include "Slushie.h"

using namespace std;

int main(){

	cout << "## Slushie class testing ##" << endl;
	cout << endl;

	// Variable initiallising
	Player *a;
	a = new Player();
	srand(time(NULL)); //Sets inprogram time for rand() functions

	Slushie *slushie;
	slushie = new Slushie();

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

	// Base Slushie info
	cout << " ~ Slushie generated information ~" << endl;
	cout << "Item: " << slushie->GetName() << endl;
	cout << "Value: $" << slushie->GetItemValue() << endl;
	cout << "Generated hunger restore value: " << slushie->GetHungerRestore() << endl;
	cout << endl << endl;

	// Test 1 - ConsumePrint Message
 	cout << "Test 1 - Print Consumption Message" << endl;
	cout << "Original Consumption message: Slurp!" << endl;
	cout << "Function Print attempt: "; slushie->consumePrint();
	cout << endl;

	// Test 2 - Fill inventory through Get Slushie functions
	cout << "Test 2 - Fill player inventory through Get Slushie function (add 2 Slushies and attempt to eat 3)" << endl;
	// Buying
	cout << "Buying Phase ~" << endl;
	cout << "Original money balance: $" << a->GetMoney() << endl;
	a->AddFood(slushie->GetName());  // Slushie 1
	a->SetMoney(a->GetMoney()-slushie->GetItemValue());
	cout << "After 1st Slushie money balance: $" << a->GetMoney() << endl;
	a->AddFood(slushie->GetName());  // Slushie 2
	a->SetMoney(a->GetMoney()-slushie->GetItemValue());
	cout << "After 2nd Slushie money balance: $" << a->GetMoney() << endl;
	cout << endl;
	// Drinking
	cout << "Drinking Phase ~" << endl;
	cout << "Original Hunger: " << a->GetHunger() << endl;
	a->EatItem(slushie->GetName(), slushie->GetHungerRestore());
	cout << "Updated Hunger (1st Slushie): " << a->GetHunger() << endl;
	a->EatItem(slushie->GetName(), slushie->GetHungerRestore());
	cout << "Updated Hunger (2nd Slushie): " << a->GetHunger() << endl;
	cout << "Attempt to drink Slushie that isn't in inventory... " << endl;
	a->EatItem(slushie->GetName(), slushie->GetHungerRestore());
	cout << "Updated Hunger: " << a->GetHunger() << endl;
	cout << endl;

	// Test 3 - Item Hunger Generation test
	cout << "Test 3 - Item Hunger Generation test (should be only between -1 and 3)" << endl;
	for (int i = 0; i < 5; i++) {
		delete slushie;
		Slushie *slushie;
		slushie = new Slushie();
		cout << "Loop count: " << i << endl;
		cout << "Hunger restoration value: " << slushie->GetHungerRestore() << endl;
	}
	cout << endl;
	delete a, slushie;
}
