#include <iostream>
using namespace std;

class Student{
private:
  char name[10];
  int age;
  char ID[10];
  int grade[4];

public:
  void Init(){
    char c;
    cin.getline(name, 10, ',');
    cin >> age >> c;
    cin.getline(ID, 10, ',');
    for (int i = 0; i < 3; i++){
      cin >> grade[i] >> c;
    }
    cin >> grade[3];
  }
  void output(){
    int avg;
    avg = (grade[0] + grade[1] + grade[2] + grade[3]) / 4;
    cout << name << ',' << age << ',' << ID << ',' << avg << endl;
  }
};

int main(){
  Student s;
  s.Init();
  s.output();
  return 0;
}
