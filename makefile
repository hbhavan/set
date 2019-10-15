OBJS = main.o Card.o Deck.o SetGame.o
COMPILE = g++ -g -c -std=gnu++0x -o $@

main: $(OBJS)
	g++ -o $@ $(OBJS)

main.o: main.cpp
	$(COMPILE) main.cpp

Card.o: Card.h Card.cpp
	$(COMPILE) Card.cpp

Deck.o: Deck.h Deck.cpp
	$(COMPILE) Deck.cpp

SetGame.o: SetGame.h SetGame.cpp
	$(COMPILE) SetGame.cpp

clean:
	$(RM) $(OBJS)

