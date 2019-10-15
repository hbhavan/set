
#include <iostream>
#include <string>
#include "SetGame.h"

using namespace std;

int rows;
int cols;

/**
 * Get row input from user and check if it is in bounds
 */
int convertX(char ch){
	
	int myX = ch - 65;
	if(myX < rows)
		return myX;
	else
		return -1;

}

/**
 * Get column input from user and check if it is in bounds
 */
int convertY(char ch){
	
	int myY = ch - 49;
	if(myY < cols)
		return myY;
	else
		return -1;

}

/**
 * Game loop, takes board's dimensions as parameter
 */
void play(int x, int y){

	bool loop = true;

	SetGame s(x, y);									//Creates set game using dimensions

	while(loop){

		string str;									//User input string
				
		s.display();

		cout << "Sets: " << s.getSets() << endl;		
		cout << "Choose three cards that form a set: "; 

		getline(cin, str);								//Get user input
	
		//Quit the game
		if(str.compare("q") == 0){
			loop = false;
			cout << "Exiting\n";
			exit(0);
		}
		
		if(str.length() == 8){								//Check if input is valid

			int coords[6] = { convertX(str.at(0)), convertY(str.at(1)),		//Coordinates of cards
					  convertX(str.at(3)), convertY(str.at(4)),
					  convertX(str.at(6)), convertY(str.at(7)) };

			bool cont = true;							//Check if all input coordinates are valid
			for(int i=0;i<6;i++)
			       if(coords[i] == -1)
				       cont = false;
			   
			if(cont){
			
				Card* c1 = s.getCard(coords[0], coords[1]); 
				Card* c2 = s.getCard(coords[2], coords[3]);
				Card* c3 = s.getCard(coords[4], coords[5]);

				if(s.check(c1, c2, c3)){					//Check if the 3 user-selected cards form a set

					s.setCard(coords[0], coords[1]);	
					s.setCard(coords[2], coords[3]);	
					s.setCard(coords[4], coords[5]);	

					s.addSets();

				}

			}	

		}

		cout << endl;
	
	}
	
}

int main(int argc, char** argv){

	if(argc != 3){
		cout << "INVALID FORMAT\nUSAGE: <./main [x] [y]\n";
		exit(0);
	}


	rows = *argv[1] - 48;
	cols = *argv[2] - 48;

	if(rows > 9 || cols > 9){
		cout << "INVALID BOUNDS\n";
		exit(0);
	}
	if(rows < 3 && cols < 3){
		cout << "INVALID BOUNDS\n";
		exit(0);
	}
	if(rows < 0 || cols < 0){
		cout << "INVALID BOUNDS\n";
		exit(0);
	}

	play(rows, cols);

	return 0;

}
