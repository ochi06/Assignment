//AJG23001 Asuka Ochiai
//構造体の参照私は過去に試したことがあるので、簡単にできると思っていた。しかし、忘れている部分が多々あり、復習しようと思った。

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;



class sum_n{
public:
int n[10000];
int num;


sum_n(int a[], int i){
  for(int k=0;k<i;k++){
    n[k]=a[k];
  }
  num=i;
};

public:
int sum_1(sum_n a){
  int i,sum_1=0;
  for(i=0;i<num;i++){
    sum_1+=a.n[i];
  }
  return sum_1;
};

int sum_2(sum_n &n){
  int i,sum_2=0;
  for(i=0;i<num;i++){
    sum_2+=n.n[i];
  }
  return sum_2;
};
};


int main(){
  int sum1, sum2, k, i, a[10000];
  clock_t start1, end1, start2, end2;
  double s1, s2;
  srand((unsigned int)time(NULL));


  sum_n n(a,i);

  for(k=0;k<1000;k++){
    n.n[k]=rand()%30000;
  }

  n.num=1000;
  
  start1=clock();
  sum1=n.sum_1(n);
  end1=clock();
  s1=(double)(end1-start1)/CLOCKS_PER_SEC;

  start2=clock();
  sum2=n.sum_2(n);
  end2=clock();
  s2=(double)(end2-start2)/CLOCKS_PER_SEC;

  cout << "sum1は構造体変数を仮引数とし,sum2は構造体の参照を仮引数として計算した.\ns1,s2はそれぞれsum1,sum2の処理にかかった時間である." << endl;

  cout << endl << "sum1 = " << sum1 << endl << "sum2 = "<< sum2 << endl;
  cout << "s1=" << s1 << endl << "s2=" << s2 << endl;

}