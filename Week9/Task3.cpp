#include <iostream>
using namespace std;

int main(){
  int a = 0, b = 0, c = 0;
  char result;
  cin >> a;
  cin.get();
  cin >> b;
  cin.get();
  cin >> c;

  if (a + b == c){
    cout << '+' << endl;
  }
  else if (a - b == c){
    cout << '-' << endl;
  }
  else if (a * b == c){
    cout << '*' << endl;
  }
  else if (a / b == c){
    cout << '/' << endl;
  }
  else if (a % b == c){
    cout << '%' << endl;
  }
  else{
    cout << "error" << endl;
  }
}
