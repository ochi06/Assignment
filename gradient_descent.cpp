#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

double grad(double x); //勾配を求める関数2*x+1
double y(double x); //関数f(x)を求める関数x^2+x+1

double grad(double x){
  return 2*x+1;
}

double y(double x){
  double y;
  y=x*x+x+1;
  return y;  
}


int main(void){

  int n;//最大反復回数 何回下るか
  double a; //学習率　一回下るにつきどれくらい下るか　小さすぎると時間がかかる、大きすぎると谷を見逃す
  double x; //初期値　勾配の収束判定に使うので小さいほうが良い
  double eps; //微小な数


  //事前設定
  n = 500;
  a=0.1;
  eps=0.0001;


  //step1
  x=2.0;
  
  ofstream outputfile("report-4-1-AJG23001.txt");
  outputfile << "f(x)=x^2+x+1\n終了条件：勾配の絶対値＜eps=0.0001\n最大反復回数：n=500\n学習率：a=0.1\n初期値：x=2.0\nただし小数点第6位までとする.\n" << endl;


  //step2~4
  for(int i=0;i<n;i++){

    outputfile << setw(3) << i << "     x = " << setw(9) << fixed << x << "     f(x) = " /*<< setw(9) << fixed*/ << y(x) << "     grad = ";
    outputfile << grad(x) << endl;

    if((grad(x)>0 && grad(x)<eps) || (grad(x)<0 && -grad(x)<eps)){
      break;
    }
    x=x-a*grad(x);
  }
  outputfile.close();
}
