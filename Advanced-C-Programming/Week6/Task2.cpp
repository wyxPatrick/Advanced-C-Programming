#include <iostream>
using namespace std;

int main(){
  int n = 0;
  cin >> n;

  char in_strings[1000][256] = {}, out_strings[1000][256] = {};
  for (int i = 0; i < n; i++){
    cin >> in_strings[i];
    for (int j = 0; j < 256; j++){
      if (in_strings[i][j] == 'A'){
        out_strings[i][j] = 'T';
      }
      else if (in_strings[i][j] == 'T'){
        out_strings[i][j] = 'A';
      }
      else if (in_strings[i][j] == 'C'){
        out_strings[i][j] = 'G';
      }
      else if (in_strings[i][j] == 'G'){
        out_strings[i][j] = 'C';
      }
      else if (in_strings[i][j] == '\n'){
        out_strings[i][j] = '\n';
      }
    }
  }

  for (int i = 0; i < n; i++){
    cout << out_strings[i] << endl;
  }
  return 0;
}
