#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct POSE {
	int i, j, high;
	POSE() {
		i = 0; j = 0; high = 0;
	}
};

bool operator< (const POSE& p1, const POSE& p2) {
	return p1.high < p2.high;
}

int main() {
	POSE a[101 * 101];
	int high[101][101];
	int length[101][101];
	int row = 0, col = 0;
	cin >> row >> col;

	int t = 0;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			a[t].i = i;
			a[t].j = j;
			cin >> a[t].high;
			high[i][j] = a[t].high;
			length[i][j] = 1;
			t++;
		}
	}
	sort(a, a + row * col);

	for (int k = 0; k < row * col; k++) {
		int i = a[k].i;
		int j = a[k].j;
		int h = a[k].high;
		vector<int> len;
		if (i > 1 && high[i - 1][j] < h) {
			len.push_back(length[i - 1][j]);
		}
		if (i < row && high[i + 1][j] < h) {
			len.push_back(length[i + 1][j]);
		}
		if (j > 1 && high[i][j - 1] < h) {
			len.push_back(length[i][j - 1]);
		}
		if (j < col && high[i][j + 1] < h) {
			len.push_back(length[i][j + 1]);
		}
		if (!len.empty()) {
			sort(len.begin(), len.end());
			length[i][j] = len.at(len.size() - 1) + 1;
		}
	}
	int maxstep = 1;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			if (length[i][j] > maxstep) {
				maxstep = length[i][j];
			}
		}
	}
	cout << maxstep << endl;
	return 0;
}