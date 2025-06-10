#include <iostream>	// coutのため
#include <iomanip>	// setwのため
using namespace std;


class kuku_array {
// write here...
public:
int **array;
int size;

public:
kuku_array(){
  size=0;
}

kuku_array(int _size){
  size=_size;
  array=new int*[size];
  for(int i=0;i<size;i++){
    array[i]=new int[size];
  }
}

~kuku_array(){
  for(int i=0;i<size;i++){
    delete[] array[i];
  }
  delete[] array;
}

kuku_array(/*const*/kuku_array &obj1){
  size=obj1.size;
  array=new int*[size];
  for(int i=0;i<size;i++){
    array[i]=new int[size];
      for(int j=0;j<size;j++){
        array[i][j]=obj1.array[i][j];
      }
  }
}

void print() {
  cout << setw(3) << "|";
  for(int i=0;i<size;i++){
    cout << setw(3) << i+1<<" ";
  }
  cout <<endl << "---------------------------------------" << endl;
  for (int i = 0; i < size; i++) {
    cout << i+1 << " |";
    for (int j = 0; j < size; j++) {
      cout << setw(3) << array[i][j] << " ";
    }
    cout << endl;
  }
}
};

int main() {

  // 九九オブジェクトobj1の生成
  // write here...
  int i, size;
  size=9;
  kuku_array obj1(size);

  // 九九を計算して、obj1の配列に入れる
  // write here...
  for(i=0; i<size; i++){
    for(int j=0; j<size; j++){
      obj1.array[i][j]=(i+1)*(j+1);
    }
  }
  
  // 九九オブジェクトobj2にobj1の中身をコピーする
  // write here...
  kuku_array obj2(obj1);
  
  // obj2に保持されている九九を表示する
  // write here...
  obj2.print();

  return 0;
}
