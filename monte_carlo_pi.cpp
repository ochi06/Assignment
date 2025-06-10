#include <iostream>
#include <stdlib.h> // rand関数のため
using namespace std;

class random_number {
// write here...
public:
double x;
double y;

#include <time.h>

random_number(){
  x=(double)rand()*2/RAND_MAX;
  y=(double)rand()*2/RAND_MAX;
}

};

// 2x2の正方形と直径2の円を考える。円の中心は原点とする。
int main() {
  // write here...
  int i,inside=0,trial=0;
  srand((unsigned int) time(NULL));

  cout << "Input the number of trials: ";
  cin >> trial;

  for(i=0;i<trial;i++){
    random_number point;
    point=random_number();
    if((point.x-1)*(point.x-1)+(point.y-1)*(point.y-1)<=1){
      inside++;
    }
  }
  
  cout << "trial = " << trial << endl;
  cout << "inside = " << inside << endl;
  cout << "A estimate of pi is " << (double)inside/trial*4 << endl;

  return 0;
}
