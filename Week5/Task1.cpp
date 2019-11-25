#include <iostream>
using namespace std;

int main(){
  int quantity, m, n;
  cin >> quantity;
  for (int q = 0; q < quantity; q++){
    cin >> m >> n;
    int a[m][n];
    int result = 0;
    for (int i = 0; i < m; i++){
      for (int j = 0; j < n; j++){
        cin >> a[i][j];
        if (i == 0 || i == m - 1 || j == 0 || j == n - 1){
          result = result + a[i][j];
        }
      }
    }
    cout << result << endl;
  }
  return 0;
}
