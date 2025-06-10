#include <iostream>
using namespace std;

class Complex{
private:
  double real;
  double imag;

public:
Complex(){
  real = 0;
  imag = 0;
}
Complex(double r, double i){
  real = r;
  imag = i;
}

void print(){
  cout << real;
  if(imag>=0){
    cout << " + ";
  }
  cout<< imag << "i";
}

Complex operator+(Complex ob2);
Complex operator-(Complex ob2);
Complex operator/(Complex ob2);
Complex operator*(Complex ob2);
bool operator==(Complex ob2);
};


int main(){
  double x, y;
  Complex o1,o2,o3;
  o3=Complex(0,0);
  

  cout << "虚数を生成します.虚数Aの実部を入力してください.\n";
  cin >> x;
  cout << "虚数Aの虚部を入力してください.\n";
  cin >> y;
  o1 = Complex(x,y);

  cout << "虚数Bの実部を入力してください.\n";
  cin >> x;
  cout << "虚数Bの虚部を入力してください.\n";
  cin >> y;
  o2 = Complex(x,y);


  cout << "\n虚数A: ";
  o1.print();
  cout << "\n虚数B: ";
  o2.print();
  cout << endl << endl << endl;


  cout << "四則演算を行います.\n和: (";
  o1.print();
  cout << ") + (";
  o2.print();
  cout << ") = ";
  (o1+o2).print();
  
  cout << "\n差: (";
  o1.print();
  cout << ") - (";
  o2.print();
  cout << ") = ";
  (o1-o2).print();

  cout << "\n積: (";
  o1.print();
  cout << ") * (";
  o2.print();
  cout << ") = ";
  (o1*o2).print();

  if(o2 == o3){
    cout << "\n商:0で割ることはできません.\n";
  }else{
    cout << "\n商: (";
    o1.print();
    cout << ") / (";
    o2.print();
    cout << ") = ";
    (o1/o2).print();
  }

  cout << ("\n\n等価比較を行います.\n虚数Aと虚数Bは");
  if(o1==o2){
      cout << " 等しい " << endl;
    }else{
      cout << " 異なる " << endl;
    }
  }



Complex Complex::operator-(Complex ob2){
  Complex temp;
  temp.real = real - ob2.real;
  temp.imag = imag - ob2.imag;
  return temp;
};

Complex Complex::operator+(Complex ob2){
  Complex temp;
  temp.real = real + ob2.real;
  temp.imag = imag + ob2.imag;
  return temp;
};

Complex Complex::operator/(Complex ob2){
  Complex temp;
  Complex temp1(ob2.real,-ob2.imag);
  temp.real = operator*(temp1).real/(ob2.real * ob2.real + ob2.imag * ob2.imag); 
  temp.imag = operator*(temp1).imag/(ob2.real * ob2.real + ob2.imag * ob2.imag); 
  return temp;
};

Complex Complex::operator*(Complex ob2){
  Complex temp;
  temp.real = real * ob2.real + imag * ob2.imag * -1;
  temp.imag = imag * ob2.real+ real * ob2.imag;;
  return temp;
};

bool Complex::operator==(Complex ob2){
  return real==ob2.real && imag==ob2.imag;
};
