//Extension of Player class
//19/05/2020
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Player.h"

using namespace std;

// Default Player Constructor
Player::Player() 
{
	string Name = "?";
	int Age;
	int HungerRating;
	double Money;
	vector<string> FoodInventory[1];
	vector<string> TicketInventory[1];
}

// Function that returns Name to Player object
void Player::SetName(string mName)
{
	Name = mName;
}

// Function that returns Age to Player object
void Player::SetAge(int mAge)
{
	Age = mAge;
}

// Function that changes the money value of Player
void Player::SetMoney(double mMoney)
{
	Money = mMoney;
}
 
// Function that returns Name to main code
string Player::GetName()
{
	return Name;
}

// Function that returns Age to main code
int Player::GetAge()
{
	return Age;
}

// Function that returns Hunger to main code
int Player::GetHunger()
{
	return HungerRating;
}

// Function that returns Money to main code
double Player::GetMoney()
{
	return Money;
}

// Function that returns food into Player object inventory
void Player::AddFood(string mFood)
{
	FoodInventory.push_back(mFood);
}

// Function that returns food into Player object inventory
void Player::AddTicket(string mTicket)
{
	TicketInventory.push_back(mTicket);
}

// Function that generates random hunger level for the user and returns that to the Player object
void Player::GenerateHunger()
{
	int randomnum = rand() % 10 + 1; //random number generator between 1 and 10
	HungerRating = randomnum;
}

// Function that generates a rnadom amount of money for the user depending on their age
void Player::GenerateMoney()
{
	double randomnum = 0;
	// Generates money for ages less than 15 ($10-$20)
	if (Age < 15) {
		// Prevents number from being generated equalling less than 10
		while (randomnum < 10) {
			randomnum = rand() % 20 + 1;
		}
		Money = randomnum;
		return;
	}
	// Generates money for ages between 15 and 18 ($20-$40)
	else if (Age >= 15 && Age <=18) {
		// Prevents number from being generated equalling less than 20
		while (randomnum < 20) {
			randomnum = rand() % 40 + 1;
		}
		Money = randomnum;
		return;
	}
	// Generates money for ages between 19 and 25 ($40-$100)
	else if (Age >= 19 && Age <=25) {
		// Prevents number from being generated equalling less than 20
		while (randomnum < 40) {
			randomnum = rand() % 100 + 1;
		}
		Money = randomnum;
		return;
	}
	// Generates money for ages older than 25 ($1000-$5000)
	else {
		// Prevents number from being generated equalling less than 1000
		while (randomnum < 1000) {
			randomnum = rand() % 5000 + 1;
		}
		Money = randomnum;
		return;
	}
}

// Function that checks for ticket in TicketInventory vector and if found, removes it and returns true
bool Player::TicketCheck(string name) {
	for (int i = 0; i < TicketInventory.size(); i++) {
		if (TicketInventory[i] == name) {
			TicketInventory.erase (TicketInventory.begin()+i);
			return true;
		}
	}
	return false;
}

// Function that is called whenever the user east a particular item. This will remove it from their inventory
bool Player::EatItem(string item, int restore_value) {
	for (int i = 0; i < FoodInventory.size(); i++) {
		if (FoodInventory[i] == item) {
			HungerRating = HungerRating + restore_value;
			FoodInventory.erase (FoodInventory.begin()+i);
			return true;
		}
	}
	// printf("That item is not in your inventory!\n");
	return false;
}

Player::~Player() 
{
}





