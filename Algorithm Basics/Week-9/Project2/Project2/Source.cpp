#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, s;
	cin >> n >> s;
	int c;
	int y;
	long long sum = 0;
	int minprice = 9999;
	for (int i = 0; i < n; i++) {
		cin >> c >> y;
		minprice = min(c, minprice + s);
		sum += minprice * y;
	}
	cout << sum << endl;
	return 0;
}