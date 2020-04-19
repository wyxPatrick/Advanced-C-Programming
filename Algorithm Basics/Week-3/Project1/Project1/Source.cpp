#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n != -1) {
        if (n % 2)
            cout << 0 << endl;
        else if (n == 0)
            cout << 1 << endl;
        else {
            long long last = 0, last_sum = 0, cur = 3;
            for (int i = 4; i <= n; i = i + 2) {
                last = cur;
                last_sum += last;
                cur = 2 * last_sum + last + 2;
            }
            cout << cur << endl;
        }
        cin >> n;
    }
    return 0;
}