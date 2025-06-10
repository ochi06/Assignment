//AJG23001 落合梓香 メンバ関数、データメンバに関する知識が曖昧なところを自分で調べながら実装したので、良い復習になった。

#include<stdlib.h>
#include<stdio.h>
#include <time.h>
#include "report-3_poker.h"

class PokerGame : public Poker{


public:
PokerGame();

void draw_cards(char [], int []);
void redraw(int i);

char* getMark(); 

int* getNumber();
};

