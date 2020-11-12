// Choc Top testing main
#include <iostream>
#include <string>
#include <ctime>
#include "Player.h"
#include "choc_top.h"

using namespace std;

int main(){

	cout << "## Choc Top class testing ##" << endl;
	cout << endl;

	// Variable initiallising
	Player *a;
	a = new Player();
	srand(time(NULL)); //Sets inprogram time for rand() functions

	choc_top *choctop;
	choctop = new choc_top();

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

	// Base choc top info
	cout << " ~ Choc top generated information ~" << endl;
	cout << "Item: " << choctop->GetName() << endl;
	cout << "Value: $" << choctop->GetItemValue() << endl;
	cout << "Generated hunger restore value: " << choctop->GetHungerRestore() << endl;
	cout << endl << endl;

	// Test 1 - ConsumePrint Message
 	cout << "Test 1 - Print Consumption Message" << endl;
	cout << "Original Consumption message: nom nom nom" << endl;
	cout << "Function Print attempt: "; choctop->consumePrint();
	cout << endl;

	// Test 2 - Fill inventory through Get choctop functions
	cout << "Test 2 - Fill player inventory through Get choctop function (add 2 choctops and attempt to eat 3)" << endl;
	// Buying
	cout << "Buying Phase ~" << endl;
	cout << "Original money balance: $" << a->GetMoney() << endl;
	a->AddFood(choctop->GetName());  // Choc top 1
	a->SetMoney(a->GetMoney()-choctop->GetItemValue());
	cout << "After 1st choc top money balance: $" << a->GetMoney() << endl;
	a->AddFood(choctop->GetName());  // Choc top 2
	a->SetMoney(a->GetMoney()-choctop->GetItemValue());
	cout << "After 2nd choc top money balance: $" << a->GetMoney() << endl;
	cout << endl;
	// Eating
	cout << "Eating Phase ~" << endl;
	cout << "Original Hunger: " << a->GetHunger() << endl;
	a->EatItem(choctop->GetName(), choctop->GetHungerRestore());
	cout << "Updated Hunger (1st Choc Top): " << a->GetHunger() << endl;
	a->EatItem(choctop->GetName(), choctop->GetHungerRestore());
	cout << "Updated Hunger (2nd Choc Top): " << a->GetHunger() << endl;
	cout << "Attempt to eat choc top that isn't in inventory... " << endl;
	a->EatItem(choctop->GetName(), choctop->GetHungerRestore());
	cout << "Updated Hunger: " << a->GetHunger() << endl;
	cout << endl;

	// Test 3 - Item Hunger Generation test
	cout << "Test 3 - Item Hunger Generation test (should be only between 0 and 2)" << endl;
	for (int i = 0; i < 5; i++) {
		delete choctop;
		choc_top *choctop;
		choctop = new choc_top();
		cout << "Loop count: " << i << endl;
		cout << "Hunger restoration value: " << choctop->GetHungerRestore() << endl;
	}
	cout << endl;
	delete a, choctop;
}
