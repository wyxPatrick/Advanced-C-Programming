#include <iostream>
using namespace std;

int fun(int n) {
	int last = 0;
	while (1) {
		last++;
		int cur = last * n + 1;
		for (int i = n - 1; i >= 1; i--) {
			if (cur % (n - 1)) {
				break;
			}
			else {
				cur = cur / (n - 1) * n + 1;
			}
			if (i == 1) {
				return cur;
			}
		}
	}
}

int main() {
	int n;
	while (cin >> n && n != 0) {
		cout << fun(n) << endl;
	}
	return 0;
}