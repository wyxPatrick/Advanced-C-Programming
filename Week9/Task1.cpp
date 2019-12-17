#include <iostream>
using namespace std;

int main(){
  int m = 0, k = 0, count = 0;
  int a[5];
  cin >> m >> k;

  if (m % 19 == 0){
    a[0] = m % 10;
    a[1] = m % 100 / 10;
    a[2] = m % 1000 / 100;
    a[3] = m % 10000 / 1000;
    a[4] = m / 10000;

    for (int i = 0; i < 5; i++){
      if (a[i] == 3){
        count++;
      }
    }

    if (count == k){
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;
  return 0;
}
