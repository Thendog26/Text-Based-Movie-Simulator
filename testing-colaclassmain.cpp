// Cola testing main
#include <iostream>
#include <string>
#include <ctime>
#include "Player.h"
#include "Cola.h"

using namespace std;

int main(){

	cout << "## Cola class testing ##" << endl;
	cout << endl;

	// Variable initiallising
	Player *a;
	a = new Player();
	srand(time(NULL)); //Sets inprogram time for rand() functions

	Cola *cola;
	cola = new Cola();

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

	// Base cola info
	cout << " ~ Cola generated information ~" << endl;
	cout << "Item: " << cola->GetName() << endl;
	cout << "Value: $" << cola->GetItemValue() << endl;
	cout << "Generated hunger restore value: " << cola->GetHungerRestore() << endl;
	cout << endl << endl;

	// Test 1 - ConsumePrint Message
 	cout << "Test 1 - Print Consumption Message" << endl;
	cout << "Original Consumption message: Gulp, gulp, gulp" << endl;
	cout << "Function Print attempt: "; cola->consumePrint();
	cout << endl;

	// Test 2 - Fill inventory through Get cola functions
	cout << "Test 2 - Fill player inventory through Get cola function (add 2 colas and attempt to eat 3)" << endl;
	// Buying
	cout << "Buying Phase ~" << endl;
	cout << "Original money balance: $" << a->GetMoney() << endl;
	a->AddFood(cola->GetName());  // Cola 1
	a->SetMoney(a->GetMoney()-cola->GetItemValue());
	cout << "After 1st cola money balance: $" << a->GetMoney() << endl;
	a->AddFood(cola->GetName());  // Cola 2
	a->SetMoney(a->GetMoney()-cola->GetItemValue());
	cout << "After 2nd cola money balance: $" << a->GetMoney() << endl;
	cout << endl;
	// Drinking
	cout << "Drinking Phase ~" << endl;
	cout << "Original Hunger: " << a->GetHunger() << endl;
	a->EatItem(cola->GetName(), cola->GetHungerRestore());
	cout << "Updated Hunger (1st cola): " << a->GetHunger() << endl;
	a->EatItem(cola->GetName(), cola->GetHungerRestore());
	cout << "Updated Hunger (2nd cola): " << a->GetHunger() << endl;
	cout << "Attempt to drink cola that isn't in inventory... " << endl;
	a->EatItem(cola->GetName(), cola->GetHungerRestore());
	cout << "Updated Hunger: " << a->GetHunger() << endl;
	cout << endl;

	// Test 3 - Item Hunger Generation test
	cout << "Test 3 - Item Hunger Generation test (should be only between 0 and 2)" << endl;
	for (int i = 0; i < 5; i++) {
		delete cola;
		Cola *cola;
		cola = new Cola();
		cout << "Loop count: " << i << endl;
		cout << "Hunger restoration value: " << cola->GetHungerRestore() << endl;
	}
	cout << endl;
	delete a, cola;
}
