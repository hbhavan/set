
#include "Deck.h"

class SetGame{

	private:

		Card** board; 				//Dynamic 2D array that represents the cards on the board
		Deck d;					//Deck of cards

		int sets;				//Number of sets the player has found
		int rows;				//Rows on board
		int cols;				//Columns on board

	public:		

		SetGame(int, int);	

		Card* getCard(int, int);		//Get a card on the board at a given index
		void setCard(int, int);			//Set a new card on the board from the deck

		bool check(Card*, Card*, Card*); 	//Check if 3 cards form a set
		int getSets();				//Return set counter
		void addSets();				//Increment set counter

		void display();				//Display the board to the console

};

