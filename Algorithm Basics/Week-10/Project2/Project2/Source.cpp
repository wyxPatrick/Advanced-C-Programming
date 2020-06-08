#include <iostream>
using namespace std;

int fun(int& a, int& b) {
	int temp;
	while (b) {
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int main() {
	int a, b;
	while (cin >> a >> b) {
		if (a > b) {
			cout << fun(a, b) << endl;
		}
		else {
			cout << fun(b, a) << endl;
		}
	}
	return 0;
}