#include <iostream>
using namespace std;

int main(){
  int m = 0, n = 0;
  cin >> m >> n;
  int land[22][22] = {0};

  for (int i = 1; i < m+1; i++){
    for (int j = 1; j < n+1; j++){
      cin >> land[i][j];
    }
  }

  for (int i = 1; i < m+1; i++){
    for (int j = 1; j < n+1; j++){
      if (land[i][j] >= land[i-1][j] && land[i][j] >= land[i+1][j] && land[i][j] >= land[i][j-1] && land[i][j] >= land[i][j+1]){
        cout << i-1 << " " << j-1 << endl;
      }
    }
  }
  return 0;
}
