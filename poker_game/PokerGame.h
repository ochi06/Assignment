#include<stdlib.h>
#include<stdio.h>
#include <time.h>
#include "Poker.h"

class PokerGame : public Poker{


public:
PokerGame();

void draw_cards(char [], int []);
void redraw(int i);

char* getMark(); 

int* getNumber();
};

