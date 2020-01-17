#include <iostream>
using namespace std;

int main() {
	int n = 0, index = 0, temp = 0;
	int x[100] = { 0 }, y[100] = { 0 };
	int x_out[100] = { 0 }, y_out[100] = { 0 };

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}

	for (int i = 0; i < n; i++) {
		bool flag = true;
		for (int j = 0; j < n; j++) {
			if (i == j) {
				continue;
			}
			if (x[j] >= x[i] && y[j] >= y[i]) {
				flag = false;
				break;
			}
		}
		if (flag == true) {
			x_out[index] = x[i];
			y_out[index] = y[i];
			index++;
		}
	}

	for (int i = 0; i < index; i++) {
		for (int j = i + 1; j < index; j++) {
			if (x_out[i] > x_out[j]) {
				temp = x_out[i];
				x_out[i] = x_out[j];
				x_out[j] = temp;

				temp = y_out[i];
				y_out[i] = y_out[j];
				y_out[j] = temp;
			}
		}
	}

	for (int i = 0; i < index - 1; i++) {
		cout << "(" << x_out[i] << "," << y_out[i] << "),";
	}
	cout << "(" << x_out[index-1] << "," << y_out[index-1] << ")" << endl;

	return 0;
}