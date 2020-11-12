// This class serves as a player class for the user at the Cinema. Any player stats will be attatched to this class and some basic player interactions will be tied to this class
// 19/05/2020
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player
{
public:
	//Constructor
	Player();	// Blank constructor that gets populated through the main code
	//Funtions
	void SetName(string mName);		//Sets name from input to Player object
	void SetAge(int mAge);				//Sets age from input to Player object
	void SetMoney(double mMoney);		//Sets money from input to Player object
	string GetName();					//Returns name to main code
	int GetAge();						//Returns age to main code
	int GetHunger();					//Returns hunger to main code
	double GetMoney();					//Returns money to main code
	void AddFood(string mFood);  		//Sets food from input into Player object
	void AddTicket(string mTicket); 	//Sets ticket from input into Player object
	void GenerateHunger();				//Generate random hunger value and returns it to Player object
	void GenerateMoney();				//Generate random money value based on age and returns it to Player object
	bool TicketCheck(string name);	   //Function to check inventory for ticket and if true, remove it and return true
	bool EatItem(string item, int restore_value); //Function to eat a particular item and remove it from food inventory
	//Deconstructor
	~Player();

private:
	//Class Variables
	string Name;
	int Age;
	int HungerRating;
	double Money;
	vector<string> FoodInventory;
	vector<string> TicketInventory;
};

#endif // PLAYER_H_H
