
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Deck.h"

using namespace std;

/**
 * The constructor initializes the deck of Cards, which contains 81 cards
 * 3^4 = 81, since there are 4 attributes each with 3 possible values
 */
Deck::Deck(){

	index = 80;

	int count = 0;
	for(int a=0;a<3;a++){
		for(int b=0;b<3;b++){
			for(int c=0;c<3;c++){
				for(int d=0;d<3;d++){
					deck[count].set(a, b, c, d);
					count++;
				}
			}
		}
	}	

	blank.setTop("[           ]");
	blank.setMid("[           ]");
	blank.setBot("[           ]");

}

/**
 * Swap 2 cards, used for shuffling
 */
void Deck::swap(Card *c1, Card *c2){

	Card temp = *c1;
	*c1 = *c2;
	*c2 = temp;	

}

/**
 * Simulate shuffling by swapping 2 cards randomly 1000 times
 */
void Deck::shuffle(){

	int rands[1000];
	srand(time(0));

	for(int i=0;i<1000;i++)
		rands[i] = (rand() % 81);

	for(int j=0;j<998;j+=2){
		Card* c1 = &deck[rands[j]];
		Card* c2 = &deck[rands[j+1]];
		swap(c1, c2);
	}

}

bool Deck::isEmpty(){

	if(index == -1) 
		return true;
	return false;

}

/**
 * Pop from the top of the stack to simulate drawing from the deck
 * Return a blank card if stack is empty
 */
Card* Deck::draw(){

	if(index >= 0){
		Card* c = &deck[index];
		index--;
		return c;
	}
	else
		return &blank;

}

void Deck::print(){
	for(int i=0;i<=index;i++){
		cout << deck[i].getTop() << "\n" << deck[i].getMid() << "\n" << deck[i].getBot() << "\n\n";
	}
}
