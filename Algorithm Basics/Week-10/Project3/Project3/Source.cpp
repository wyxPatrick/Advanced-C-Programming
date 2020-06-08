#include <iostream>
#include <vector>
using namespace std;

int fun(int& num) {
    vector<vector<int> > dp(num + 1, vector<int>(num + 1, 0));
    for (int n = 0; n <= num; n++) {
        for (int k = 0; k <= num; k++) {
            if (k > n / 2 && k <= n) {
                dp[n][k] = 1;
            }
        }
    }
    for (int n = 1; n <= num; n++) {
        for (int k = n / 2; k >= 1; k--) {
            dp[n][k] = dp[n - k][k] + dp[n][k + 1];
        }
    }
    return dp[num][1];
}

int main() {
    int num;
    while (cin >> num) {
        cout << fun(num) << endl;
    }
    return 0;
}