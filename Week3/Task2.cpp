#include <iostream>
using namespace std;

int rec(int n){
  if (n == 1){
    cout << "End" << endl;
    return 0;
  }
  else {
    if (n % 2 != 0){
      cout << n << "*3+1=" << n*3+1 << endl;
      n = n * 3 + 1;
      rec(n);
    }
    else{
      cout << n << "/2=" << n/2 << endl;
      n = n / 2;
      rec(n);
    }
  }
}

int main() {
  int n;
  cin >> n;
  rec(n);
  return 0;
}
