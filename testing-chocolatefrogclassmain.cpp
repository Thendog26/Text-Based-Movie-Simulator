// chocolatefrog testing main
#include <iostream>
#include <string>
#include <ctime>
#include "Player.h"
#include "chocolateFrog.h"

using namespace std;

int main(){

	cout << "## Chocolate Frog class testing ##" << endl;
	cout << endl;

	// Variable initiallising
	Player *a;
	a = new Player();
	srand(time(NULL)); //Sets inprogram time for rand() functions

	chocolateFrog *chocolatefrog;
	chocolatefrog = new chocolateFrog();

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

	// Base chocolatefrog info
	cout << " ~ Chocolatefrog generated information ~" << endl;
	cout << "Item: " << chocolatefrog->GetName() << endl;
	cout << "Value: $" << chocolatefrog->GetItemValue() << endl;
	cout << "Generated hunger restore value: " << chocolatefrog->GetHungerRestore() << endl;
	cout << endl << endl;

	// Test 1 - ConsumePrint Message
 	cout << "Test 1 - Print Consumption Message" << endl;
	cout << "Original Consumption message: damn that's good... I need more!!" << endl;
	cout << "Function Print attempt: "; chocolatefrog->consumePrint();
	cout << endl;

	// Test 2 - Fill inventory through Get chocolatefrog functions
	cout << "Test 2 - Fill player inventory through Get chocolatefrog function (add 2 chocolatefrogs and attempt to eat 3)" << endl;
	// Buying
	cout << "Buying Phase ~" << endl;
	cout << "Original money balance: $" << a->GetMoney() << endl;
	a->AddFood(chocolatefrog->GetName());  // Chocolate frog 1
	a->SetMoney(a->GetMoney()-chocolatefrog->GetItemValue());
	cout << "After 1st chocolatefrog money balance: $" << a->GetMoney() << endl;
	a->AddFood(chocolatefrog->GetName());  // Chocolatefrog 2
	a->SetMoney(a->GetMoney()-chocolatefrog->GetItemValue());
	cout << "After 2nd chocolatefrog money balance: $" << a->GetMoney() << endl;
	cout << endl;
	// Eating
	cout << "Eating Phase ~" << endl;
	cout << "Original Hunger: " << a->GetHunger() << endl;
	a->EatItem(chocolatefrog->GetName(), chocolatefrog->GetHungerRestore());
	cout << "Updated Hunger (1st chocolatefrog): " << a->GetHunger() << endl;
	a->EatItem(chocolatefrog->GetName(), chocolatefrog->GetHungerRestore());
	cout << "Updated Hunger (2nd chocolatefrog): " << a->GetHunger() << endl;
	cout << "Attempt to eat chocolatefrog that isn't in inventory... " << endl;
	a->EatItem(chocolatefrog->GetName(), chocolatefrog->GetHungerRestore());
	cout << "Updated Hunger: " << a->GetHunger() << endl;
	cout << endl;

	// Test 3 - Item Hunger Generation test
	cout << "Test 3 - Item Hunger Generation test (should be only between 0 and -2)" << endl;
	for (int i = 0; i < 5; i++) {
		delete chocolatefrog;
		chocolateFrog *chocolatefrog;
		chocolatefrog = new chocolateFrog();
		cout << "Loop count: " << i << endl;
		cout << "Hunger restoration value: " << chocolatefrog->GetHungerRestore() << endl;
	}
	cout << endl;
	delete a, chocolatefrog;
}
