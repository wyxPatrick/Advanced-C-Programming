#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  int m, temp1;
  float a = 0, temp2 = 0;
  cin >> m >> a;
  int index[m] = {};
  float sev[m] = {};

  for (int i = 0; i < m; i++){
    cin >> index[i] >> sev[i];
  }

  for (int i = 0; i < m-1; i++){
    for (int j = 0; j < m-1-i; j++){
      if (sev[j] < sev[j+1]){
        temp2 = sev[j];
        sev[j] = sev[j+1];
        sev[j+1] = temp2;

        temp1 = index[j];
        index[j] = index[j+1];
        index[j+1] = temp1;
      }
    }
  }

  int count = 0;

  for (int i = 0; i < m; i++){
    if (sev[i] >= a){
      cout << setw(3) << setfill('0') << index[i] << " ";
      cout << fixed << setprecision(1) << sev[i] << endl;
      count++;
    }
  }

  if (count == 0){
    cout << "None." << endl;
  }

  return 0;
}
