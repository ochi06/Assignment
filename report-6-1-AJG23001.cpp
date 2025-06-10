//AJG23001 Asuka Ochiai
//理解しやすかった

#include <stdio.h>
#include<iostream>
using namespace std;

void swap(int &a, int &b){
  int temp;
  temp = a;
  a = b;
  b = temp; 
}

int main(){
  int a=1,
      b=2;

  cout << a << " " << b << endl;
  swap(a,b);
  cout << a << " " << b << endl;
  
}