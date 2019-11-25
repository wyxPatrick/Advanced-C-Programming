#include <iostream>
using namespace std;

int main(){
  int m, n;
  cin >> m >> n;
  int a[m][n];
  for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
      cin >> a[i][j];
    }
  }

  int x = 0, y = 0;
  for (int i = 0; i < m + n - 1; i++){
    x = i > n-1 ? i-n+1 : 0;
    y = i-x;
    while (x <= m-1 && y >= 0){
      cout << a[x][y] << endl;
      x++;
      y--;
    }
  }
  return 0;
}
