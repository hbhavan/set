
#include <iostream>
#include <string>
#include "Card.h"

/**
 * This constructor initializes the possible textures a card can take as well as the shape that displays on the card
 */
Card::Card(){

	textures[0] = "O", textures[1] = "|", textures[2] = "+";

	diamond[0][0] = 0, diamond[0][2] = 0, diamond[2][0] = 0, diamond[2][2] = 0;
	diamond[0][1] = 1, diamond[1][0] = 1, diamond[1][1] = 1, diamond[1][2] = 1, diamond[2][1] = 1;
	cross  [0][1] = 0, cross  [1][0] = 0, cross  [1][2] = 0, cross  [2][1] = 0;
	cross  [0][0] = 1, cross  [0][2] = 1, cross  [1][1] = 1, cross  [2][0] = 1, cross  [2][2] = 1;
	square [0][0] = 1, square [0][1] = 1, square [0][2] = 1, square [1][0] = 1,  
	square [1][1] = 1, square [1][2] = 1, square [2][0] = 1, square [2][1] = 1, square [2][2] = 1;

}

/**
 * Sets the card's 4 attributes
 */
void Card::set(int quantity, int shape, int color, int texture){

	attributes[0] = quantity;
	attributes[1] = shape;
	attributes[2] = color;
	attributes[3] = texture;

	toString();

}

/**
 * Return pointer to array containing Card's 4 attributes
 */
int *Card::get(){
	return attributes;
}

string Card::getTop(){ 
	return top; 
}
string Card::getMid(){ 
	return mid; 
}
string Card::getBot(){ 
	return bot; 
}

void Card::setTop(string str){
	top = str;
}
void Card::setMid(string str){
	mid = str;
}
void Card::setBot(string str){
	bot = str;
}


/**
 * Formats the string representation of the card based on its attributes
 */
void Card::toString(){

	string output[3][13];	
	for(int i=0;i<3;i++){
		output[i][0] = "[";
		for(int j=1;j<12;j++)
			output[i][j] = " ";

		output[i][12] = "]";
	}

	//Quantity 1
	if(attributes[0] == 0){
		for(int i=0;i<3;i++){
	     		for(int j=0;j<3;j++){
				//Shape
				if(attributes[1] == 0){
					if(diamond[i][j] == 1){
						//Color & Textures
						if(attributes[2] == 0){
							output[i][j+5] = "\033[1;33m" + textures[attributes[3]] + "\033[0m";
						}
						if(attributes[2] == 1){
							output[i][j+5] = "\033[1;35m" + textures[attributes[3]] + "\033[0m";
						}
						if(attributes[2] == 2){
							output[i][j+5] = "\033[1;36m" + textures[attributes[3]] + "\033[0m";
						}
					}	
					
				}
				if(attributes[1] == 1){
					if(cross[i][j] == 1){
						//Color & Textures
						if(attributes[2] == 0){
							output[i][j+5] = "\033[1;33m" + textures[attributes[3]] + "\033[0m";
						}
						if(attributes[2] == 1){
							output[i][j+5] = "\033[1;35m" + textures[attributes[3]] + "\033[0m";
						}
						if(attributes[2] == 2){
							output[i][j+5] = "\033[1;36m" + textures[attributes[3]] + "\033[0m";
						}
					}
				}				
				if(attributes[1] == 2){
					if(square[i][j] == 1){
						//Color & Textures
						if(attributes[2] == 0){
							output[i][j+5] = "\033[1;33m" + textures[attributes[3]] + "\033[0m";
						}
						if(attributes[2] == 1){
							output[i][j+5] = "\033[1;35m" + textures[attributes[3]] + "\033[0m";
						}
						if(attributes[2] == 2){
							output[i][j+5] = "\033[1;36m" + textures[attributes[3]] + "\033[0m";
						}
					}
				}
			}
		}
	}
	//Quantity 2
	if(attributes[0] == 1){
		for(int i=0;i<3;i++){
	     		for(int j=0;j<3;j++){
				//Shape
				if(attributes[1] == 0){
					if(diamond[i][j] == 1){
						//Color & Textures
						if(attributes[2] == 0){
							output[i][j+3] = "\033[1;33m" + textures[attributes[3]] + "\033[0m";
							output[i][j+7] = "\033[1;33m" + textures[attributes[3]] + "\033[0m";

						}
						if(attributes[2] == 1){
							output[i][j+3] = "\033[1;35m" + textures[attributes[3]] + "\033[0m";	
							output[i][j+7] = "\033[1;35m" + textures[attributes[3]] + "\033[0m";
						}
						if(attributes[2] == 2){
							output[i][j+3] = "\033[1;36m" + textures[attributes[3]] + "\033[0m";					
							output[i][j+7] = "\033[1;36m" + textures[attributes[3]] + "\033[0m";
						}
					}
				}
				if(attributes[1] == 1){
					if(cross[i][j] == 1){
						//Color & Textures
						if(attributes[2] == 0){
							output[i][j+3] = "\033[1;33m" + textures[attributes[3]] + "\033[0m";	
							output[i][j+7] = "\033[1;33m" + textures[attributes[3]] + "\033[0m";

						}
						if(attributes[2] == 1){
							output[i][j+3] = "\033[1;35m" + textures[attributes[3]] + "\033[0m";
							output[i][j+7] = "\033[1;35m" + textures[attributes[3]] + "\033[0m";

						}
						if(attributes[2] == 2){
							output[i][j+3] = "\033[1;36m" + textures[attributes[3]] + "\033[0m";
							output[i][j+7] = "\033[1;36m" + textures[attributes[3]] + "\033[0m";
						}
					}
				}				
				if(attributes[1] == 2){
					if(square[i][j] == 1){
						//Color & Textures
						if(attributes[2] == 0){
							output[i][j+3] = "\033[1;33m" + textures[attributes[3]] + "\033[0m";
							output[i][j+7] = "\033[1;33m" + textures[attributes[3]] + "\033[0m";
						}
						if(attributes[2] == 1){
							output[i][j+3] = "\033[1;35m" + textures[attributes[3]] + "\033[0m";
							output[i][j+7] = "\033[1;35m" + textures[attributes[3]] + "\033[0m";
						}
						if(attributes[2] == 2){
							output[i][j+3] = "\033[1;36m" + textures[attributes[3]] + "\033[0m";
							output[i][j+7] = "\033[1;36m" + textures[attributes[3]] + "\033[0m";
						}
					}
				}
			}
		}
	}
	//Quantity =====3
	if(attributes[0] == 2){
		for(int i=0;i<3;i++){
	     		for(int j=0;j<3;j++){
				//Shape
				if(attributes[1] == 0){
					if(diamond[i][j] == 1){
						//Color & Textures
						if(attributes[2] == 0){
							output[i][j+1] = "\033[1;33m" + textures[attributes[3]] + "\033[0m";
							output[i][j+5] = "\033[1;33m" + textures[attributes[3]] + "\033[0m";
							output[i][j+9] = "\033[1;33m" + textures[attributes[3]] + "\033[0m";

						}
						if(attributes[2] == 1){
							output[i][j+1] = "\033[1;35m" + textures[attributes[3]] + "\033[0m";	
							output[i][j+5] = "\033[1;35m" + textures[attributes[3]] + "\033[0m";
							output[i][j+9] = "\033[1;35m" + textures[attributes[3]] + "\033[0m";
						}
						if(attributes[2] == 2){
							output[i][j+1] = "\033[1;36m" + textures[attributes[3]] + "\033[0m";					
							output[i][j+5] = "\033[1;36m" + textures[attributes[3]] + "\033[0m";
							output[i][j+9] = "\033[1;36m" + textures[attributes[3]] + "\033[0m";
						}
					}
				}
				if(attributes[1] == 1){
					if(cross[i][j] == 1){
						//Color & Textures
						if(attributes[2] == 0){
							output[i][j+1] = "\033[1;33m" + textures[attributes[3]] + "\033[0m";	
							output[i][j+5] = "\033[1;33m" + textures[attributes[3]] + "\033[0m";
							output[i][j+9] = "\033[1;33m" + textures[attributes[3]] + "\033[0m";

						}
						if(attributes[2] == 1){
							output[i][j+1] = "\033[1;35m" + textures[attributes[3]] + "\033[0m";
							output[i][j+5] = "\033[1;35m" + textures[attributes[3]] + "\033[0m";
							output[i][j+9] = "\033[1;35m" + textures[attributes[3]] + "\033[0m";

						}
						if(attributes[2] == 2){
							output[i][j+1] = "\033[1;36m" + textures[attributes[3]] + "\033[0m";
							output[i][j+5] = "\033[1;36m" + textures[attributes[3]] + "\033[0m";
							output[i][j+9] = "\033[1;36m" + textures[attributes[3]] + "\033[0m";
						}
					}
				}				
				if(attributes[1] == 2){
					if(square[i][j] == 1){
						//Color & Textures
						if(attributes[2] == 0){
							output[i][j+1] = "\033[1;33m" + textures[attributes[3]] + "\033[0m";
							output[i][j+5] = "\033[1;33m" + textures[attributes[3]] + "\033[0m";
							output[i][j+9] = "\033[1;33m" + textures[attributes[3]] + "\033[0m";
						}
						if(attributes[2] == 1){
							output[i][j+1] = "\033[1;35m" + textures[attributes[3]] + "\033[0m";
							output[i][j+5] = "\033[1;35m" + textures[attributes[3]] + "\033[0m";
							output[i][j+9] = "\033[1;35m" + textures[attributes[3]] + "\033[0m";
						}
						if(attributes[2] == 2){
							output[i][j+1] = "\033[1;36m" + textures[attributes[3]] + "\033[0m";
							output[i][j+5] = "\033[1;36m" + textures[attributes[3]] + "\033[0m";
							output[i][j+9] = "\033[1;36m" + textures[attributes[3]] + "\033[0m";
						}
					}
				}
			}

		}
	}

	for(int a=0;a<13;a++){

		top += output[0][a];
		mid += output[1][a];
		bot += output[2][a];

	}

}

void Card::print(){

	cout << top << "\n" << mid << "\n" << bot << "\n\n";

}

