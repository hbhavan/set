
#include <iostream>
#include "SetGame.h"

/**
 * The constructor creates a set game of any specified number of rows and columns
 * as long as 0 < rows < 10 and 0 < cols < 10
 * Shuffles the deck and sets up the board as well
 */
SetGame::SetGame(int x, int y){

	rows = x;
	cols = y;

	board = new Card*[x];
	for(int i=0;i<x;i++)
		board[i] = new Card[y];

	sets = 0;	
	d.shuffle();	
	
	for(int i=0;i<x;i++)
		for(int j=0;j<y;j++)
			board[i][j] = *d.draw();
	
}

/**
 * Returns a card on the board at the specified index
 */
Card* SetGame::getCard(int x, int y){
	return &board[x][y];
}

/**
 * Set a card on the board by drawing a new one from the deck
 */
void SetGame::setCard(int x, int y){
	board[x][y] = *d.draw();
}

/**
 * Returns true if all 3 cards are the same in an attribute or different in
 * an attribute for all 4 attributes, false if otherwise
 */
bool SetGame::check(Card* c1, Card* c2, Card* c3){

	int *a = c1->get();
	int *b = c2->get();
	int *c = c3->get();

	if( ( a[0] == b[0] && b[0] == c[0] ) || ( a[0] != b[0] && a[0] != c[0] && b[0] != c[0] ) )	
		if( ( a[1] == b[1] && b[1] == c[1] ) || ( a[1] != b[1] && a[1] != c[1] && b[1] != c[1] ) )
			if( ( a[2] == b[2] && b[2] == c[2] ) || ( a[2] != b[2] && a[2] != c[2] && b[2] != c[2] ) )
				if( ( a[3] == b[3] && a[3] == c[3] ) || ( a[3] != b[3] && a[3] != c[3] && b[3] != c[3] ) )
					return true;	

 	return false;

}

int SetGame::getSets(){ 
	return sets;
}

void SetGame::addSets(){ 
	sets++; 
}

/**
 * Print board to console
 */
void SetGame::display(){

	cout << "       ";
	for(int i=0;i<cols;i++)
		cout << i+1 << "             ";

	cout << endl;

	for(int i=0;i<rows;i++){
		
		cout << " ";
		for(int j=0;j<cols;j++)
			cout << board[i][j].getTop() << " ";

		cout << endl << (char) (i+65);
		for(int j=0;j<cols;j++)
			cout << board[i][j].getMid() << " ";
		
		cout << endl << " ";
		for(int j=0;j<cols;j++)
			cout << board[i][j].getBot() << " ";
		
		cout << endl << endl;
	
	}

}
