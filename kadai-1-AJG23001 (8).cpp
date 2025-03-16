#include <iostream>
using namespace std;

class Time{
private:
  int hour;
  int minute;
  int second;

public:
void in_hour(int new_hour){
  hour=new_hour;
}
void in_minute(int new_minute){
  minute=new_minute;
}
void in_second(int new_second){
  second=new_second;
}

string get(){
  return to_string(hour)+":"+to_string(minute)+":"+to_string(second);
}

Time add(Time current_Time, Time new_Time){
  Time *added_Time;
  added_Time = new Time();
  int m=0,h=0;

  added_Time->second = (current_Time.second)+(new_Time.second);
  if(added_Time->second>=60){
    m=1;
    added_Time->second=added_Time->second-60;
  }
  added_Time->minute = (current_Time.minute)+(new_Time.minute)+m;
  if(added_Time->minute>=60){
    h=1;
    added_Time->minute = added_Time->minute-60;
  }
  added_Time->hour = (current_Time.hour)+(new_Time.hour)+h;
  
  
  return *added_Time;
}

};

int main() {
  int hour, minute, second;
  
  Time *Time1, *Time2;
  Time1 = new Time();
  Time2 = new Time();

  cout << "Set Time1" << endl;
  cout << "hour: ";
  cin >> hour;
  cout << "minute: ";
  cin >> minute;
  cout << "second: ";
  cin >> second;
  
  Time1->in_hour(hour);
  Time1->in_minute(minute);
  Time1->in_second(second);
  
  cout << endl << "Set Time2" << endl;
  cout << "hour: ";
  cin >> hour;
  cout << "minute: ";
  cin >> minute;
  cout << "second: ";
  cin >> second;
  
  Time2->in_hour(hour);
  Time2->in_minute(minute);
  Time2->in_second(second);


  
  cout << endl << "Time1: "<< Time1->get() << endl;
  cout << "Time2: "<< Time2->get() << endl;
  cout << "Time1(Time2 is added): " << Time1->add(*Time1, *Time2).get() << endl;
}