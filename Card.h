
#include <string>

using namespace std;

class Card{

	private:

		string card[3][13]; 		//String representation of the card
		string top;      		//Top string of card used for printing to console
		string mid;			//Middle string of card used for printing to console
		string bot;			//Bottom string of card used for printing to console

		int attributes[4];		//Attributes of a given card

		string textures[3];		//Symbols that make up the card's shape

		bool diamond[3][3];		//Diamond shape mapping
		bool cross[3][3];		//Cross shape mapping
		bool square[3][3];		//Square shape mapping

	public:

		Card();
		
		int* get();			//Return array of attributes
		void set(int, int, int, int); 	//Set card's 4 attributes: quantity, shape, color, and texture 

		string getTop();		//Get top string
		string getMid();		//Get middle string
		string getBot();		//Get bottom string

		void setTop(string);		//Set top string
		void setMid(string);		//Set middle string
		void setBot(string);		//Set bottom string

		void toString();
		void print();

};
