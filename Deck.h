
#include <cstdlib>
#include <string>
#include "Card.h"

class Deck{

	private:

		int index;			//Index of the top of the deck
		Card deck[81];			//Array-representation of stack data structure used for deck	

		void swap(Card*, Card*);	//Swap 2 cards in the deck

	public:

		Card blank;			//Blank card for printing out once deck is empty

		Deck();

		void shuffle();			//Shuffle the deck

		bool isEmpty();			//Check if stack is empty

		Card* draw();			//Pop the top of the stack by drawing from the deck
		
		void print();

};

