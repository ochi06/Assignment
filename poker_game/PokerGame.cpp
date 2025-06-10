#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include"report-3-AJG23001_pokergame.h"

PokerGame::PokerGame() {
  for (int i = 0; i < 5; i++) {
    mark[i] = 'A';
    number[i] = 0;
  }
}

char*
PokerGame::getMark() {
  return mark;
} 
int*
PokerGame::getNumber() {
  return number;
}

void PokerGame::draw_cards(char mark[5], int number[5]){
  int i,k;
  srand((unsigned int)time(NULL));
  

  for(i=0;i<5;i++){
     
    number[i]=rand()%13+1;
    switch(rand()%4){
      case 0:
        mark[i]='S';
        break;
      case 1:
        mark[i]='H';
        break;
      case 2:
        mark[i]='D';
        break;
      case 3:
        mark[i]='C';
        break;
    }
   
    for(k=0;k<i;k++){
      if(mark[k]==mark[i] && number[k]==number[i]){
        i--;
      }
    }
  }
}


void PokerGame::redraw(int i){
  int k,l=0;
  char a;
  int b;


  b=rand()%13+1;
    switch(rand()%4){
      case 0:
        a='S';
        break;
      case 1:
        a='H';
        break;
      case 2:
        a='D';
        break;
      case 3:
        a='C';
        break;
    }

    for(k=0;k<5;k++){
      if(mark[k]==a && number[k]==b){
        l++;         
      }
    }
  if(l==0){
    mark[i]=a;
    number[i]=b;   
  }else{
    redraw(i);
  }
}



  




