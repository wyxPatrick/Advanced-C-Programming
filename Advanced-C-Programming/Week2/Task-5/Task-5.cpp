#include <iostream>
using namespace std;

int main(){
  int n;
  int id[100];
  int rate[100];

  cin >> n;
  for (int i = 0; i < n; i++) {
    int start, end;
    cin >> id[i] >> start >> end;
    rate[i] = (double)end / start;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (rate[j + 1] > rate[j]) {
        int tmpID = id[j];
        id [j] = id[j + 1];
        id[j + 1] = tmpID;
        double tmpRate = rate[j];
        rate[j] = rate[j + 1];
        rate[j + 1] = tmpRate;
      }
    }
  }

  double maxDiff = 0;
  int maxDiffIndex = 0;
  for (int i = 0; i < n - 1; i++) {
    double diff = rate[i] - rate[i + 1];
    if (maxDiff < diff) {
      maxDiff = diff;
      maxDiffIndex = i;
    }
  }

  cout << maxDiffIndex + 1 << endl;
  for (int i = maxDiffIndex; i >= 0; i--) {
    cout << id[i] << endl;
  }

  cout << n - maxDiffIndex - 1 << endl;
  for (int i = n - 1; i >= maxDiffIndex + 1; i--) {
    cout << id[i] << endl;
  }

  return 0;
}
