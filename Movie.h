//20-5-20 Parent class of Movie
//base functionality for Movie objects shown in Cinema simulator
#ifndef MOVIE_H
#define MOVIE_H
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

class Movie {
	
private: 
// protected because they are needed for the subclasses to set their detiails but they aren't to be changed by the user
			
		// Variables //
		int rating;
		string genre;
		string title;
		int price;
		bool availability;

public:
		// Constructor
		Movie(string mtitle, string mgenre, int mrating, int mprice){
			rating = mrating; //the age required to enter this movie
        	genre = mgenre; //can be called to aid movie selection at the ticket desk, this film is meant to be the dud option
        	title = mtitle; //title of the movie as it will appear at the ticket desk
        	price = mprice; //the price of this movie at the ticket desk
			availability = true;
		}
	
		// Functions //
		//not need to set variables as they're pre-set
		//getters
		int get_rating(){
			return rating;
		} //returns the rating to determine is the user can enter the selected movie

		string get_genre (){
			return genre;
		} //returns the genre for user information, to aid movie selection

		string get_title(){
			return title;
		} //returns the title to the movie selection menu

		int get_price(){
			return price;
		} //returns the price to balance cash flow allowing cinema to charge for entry
		
		bool get_availability(){
			return availability;
		}
		
		//the random unavailability tool, simulates popularity of certain movies and session times by randomising a 20% sell out for the popular movies
		void Generate_Availability(){
			if (int(std::rand() % 5 + 1) > 1){
				availability = true;
			} 
			else{ 
				availability = false;
			}
		}
	
		// Deconstructor
		~Movie() {
		}

};
#endif
