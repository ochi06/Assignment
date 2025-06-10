#include <iostream>
#include <string>
using namespace std;

class Account { //基本クラス
protected:
  string name; // 名前
  int balance; // 円残高（単位：円）

public:
  // コンストラクタ  
  Account(string _name, int _balance) {
    name = _name;       // 名前を初期化
    balance = _balance; // 円残高を初期化
  }
  // 名前を調べる
  string get_name() {
    return name;
  }
  // 円残高を調べる
  int get_balance() {
    return balance;
  }
  // 預ける
  void deposit(int amnt) {
    balance += amnt;
  }
  // おろす
  void withdraw(int amnt) {
    balance -= amnt;
  }
};

class AccountFx : public Account { //派生クラス
public:
int balance_cent; //米セントの残高を管理する変数
double ex_rate; //為替レートを管理する変数

AccountFx(string _name, int _yen_balance, int _cent_balance, double _ex_rate): Account(_name, _yen_balance){
  name = _name;
  _yen_balance = _yen_balance;
  _cent_balance = _cent_balance;
  ex_rate = _ex_rate; 
};

void ex_to_cent(int yen){
  withdraw(yen);
  balance_cent += yen/ex_rate;
}
void ex_to_yen(int cent){
  balance_cent -= cent;
  deposit(cent*ex_rate);
}
int get_balance_cent(){
  return balance_cent;
}
void update_ex_rate(double _ex_rate){
  ex_rate = _ex_rate;
}

};

int main(){
  string name;
  int balance;
  char choice = '5';
  int yen;
  int cent;


  AccountFx a("Suzuki",10000, 0, 0.95);

  while(true){
   switch(choice) {
     
     case '0':
       cout << "終了します." << endl;
       return 0;
       break;
     
     case '1':
       cout << "セントへ両替する金額を入力してください" << endl;
       cin >> yen;
       a.ex_to_cent(yen);
       cout << yen << "円が" << (int)(yen/a.ex_rate) << "セントに両替されました." << endl << endl;
       choice = '5';
       break;

     case '2':
       cout << "円へ両替する金額を入力してください." << endl;
       cin >> cent;
       a.ex_to_yen(cent);
       cout << cent << "セントが" << (int)(cent*a.ex_rate) << "円に両替されました." << endl << endl;
       choice = '5';
       break;
     
     case '3':
       cout << "米セント残高は" << a.get_balance_cent() << "セントです." << endl << endl;
       choice = '5';
       break;
     
     case '4':
       cout << "為替レートを更新します." << endl;
       cin >> a.ex_rate;
       cout << "為替レートが" << a.ex_rate << "円/セントに更新されました." << endl << endl;
       choice = '5';
       break;
     
     case '5':
       cout << endl << "現在の口座状況です." << endl << endl << "名前：" << a.get_name() << endl << "円残高：" << a.get_balance() << endl << "米セント残高：" << a.get_balance_cent() << endl << "為替レート：" << a.ex_rate << "円/セント" << endl << endl << endl;
       cout << "選択してください." << endl << endl;
     cout  << "0.終了" << endl <<"1.円をセントへ両替" << endl <<"2.セントを円へ両替"<< endl << "3.米セント残高を確認" << endl << "4.為替レートの更新" << endl << endl;
       cin >> choice;
        break;
   }
  }
}
