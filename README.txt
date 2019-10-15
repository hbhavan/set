To compile:
	- Ensure that the following files are in the directory:
		Card.h, Card.cpp
		Deck.h, Deck.cpp
		Setgame.h, SetGame.cpp
		main.cpp
	- Type 'make'

To run:
	- Type './main <x> <y>'
	- x and y are the number of cards in a row and column,
	  respectively

HOW TO PLAY:

The game Set is played with a deck of 81 cards, each with 4 
different attributes: 
	1. The color of the card: cyan, magenta, yellow
	2. The symbols on the card: '0', '|', '+'
	3. The shape on the card that those symbols make up:
		Diamond:
		[     0     ]
		[    000    ]
		[     0     ]
		Cross:
		[    0 0    ]
		[     0     ]
		[    0 0    ]
		Square:
		[    000    ]
		[    000    ]
		[    000    ]		 
	4. The number of shapes on the card
		One diamond:
		[     +     ]
		[    +++    ]
		[     +     ]
		Two diamonds:
		[   +   +   ]
		[  +++ +++  ]
		[   +   +   ]
		Three diamonds:
		[ +   +   + ]
		[+++ +++ +++]
		[ +   +   + ]

Each card is unique, and has 4 possibilities for its 3
attributes, so there are 3^4, or 81, cards.

The game is played by drawing cards, typically 12, from the 
deck and placing them face up. Then, the player tries to find
as many sets of 3 cards from those on the table as possible,
removing the cards that form a set and replacing them by drawing
from the deck. This is continued until there are no more cards 
in the deck and/or there are no sets on the current board.

For 3 cards to be a set, they must, for each attribute, be all
the same in that attribute or all different in that attribute.
Some example sets:
	Same color, symbol, and shape; different number:
	[     +     ] [   +   +   ] [ +   +   + ]
	[    +++    ] [  +++ +++  ] [+++ +++ +++]
	[     +     ] [   +   +   ] [ +   +   + ]
	Same color; different symbol, shape, and number:
	[    |||    ] [   0   0   ] [+ + + + + +]
	[    |||    ] [  000 000  ] [ +   +   + ]
	[    |||    ] [   0   0   ] [+ + + + + +]
	Same color and shape; different symbol and number:
	[    +++    ] [  ||| |||  ] [000 000 000]
	[    +++    ] [  ||| |||  ] [000 000 000]
	[    +++    ] [  ||| |||  ] [000 000 000]
	Same color and number; different symbol and shape:
	[    0 0    ][     +++    ] [     |	]
	[     0     ][     +++    ] [    |||    ]
	[    0 0    ][     +++    ] [     |     ]

The cards on the board will be displayed in a grid, with the 
rows labeled alphabetically (A, B, C) and the columns labeled
numerically (1, 2, 3, 4). To select your 3 cards, type each
card's position on the board into console, separating each 
card with a space.
Example input:
	A1 B2 D3
	C3 A2 B1
	D3 A3 B1
The order of the cards inputted does not matter.

Upon entering a correct set, the 3 cards will automatically
be replaced with new ones (or left blank if the deck is empty)
and the score will increment. Continue playing, getting as
many sets as possible. Type lower case 'q' in the console to
quit the game.

NOTE:

- The board has a maximum size of 9 x 9 cards
- The board has a minimum size of 2 x 2 cards
- Only 3 cards can be input at a time
- The player must input 3 DIFFERENT cards 

