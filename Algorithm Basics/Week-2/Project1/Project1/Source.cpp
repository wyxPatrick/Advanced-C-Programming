#include <iostream>
using namespace std;
int wall[16][17], paint[16][17];

int guess(const int& wallSize) {
	for (int r = 1; r < wallSize; r++) {
		for (int c = 1; c < wallSize + 1; c++) {
			paint[r + 1][c] = (wall[r][c] + paint[r][c] + paint[r - 1][c] + paint[r][c - 1] + paint[r][c + 1]) % 2;
		}
	}
	for (int c = 1; c < wallSize + 1; c++) {
		if ((paint[wallSize][c - 1] + paint[wallSize][c] + paint[wallSize][c + 1] + paint[wallSize - 1][c]) % 2 != wall[wallSize][c]) {
			return 226;
		}
	}
	int steps = 0;
	for (int r = 1; r <= wallSize; r++) {
		for (int c = 1; c <= wallSize; c++) {
			if (paint[r][c] == 1) {
				steps++;
			}
		}	
	}
	return steps;
}

int enumerate(const int& wallSize) {
	int minStep = 226;
	int steps;
	int c;
	while (paint[1][wallSize + 1] == 0) {
		steps = guess(wallSize);
		if (steps < minStep) {
			minStep = steps;
		}
		paint[1][1]++;
		c = 1;
		while (paint[1][c] > 1) {
			paint[1][c] = 0;
			c++;
			paint[1][c]++;
		}
	}
	return minStep;
}

int main() {
	int t, n, minStep;
	char color;
	cin >> t;
	for (int i = 0; i < t; i++) {
		for (int r = 0; r < 16; r++) {
			for (int c = 0; c < 17; c++) {
				wall[r][c] = 0;
				paint[r][c] = 0;
			}
		}
		cin >> n;
		for (int j = 1; j < n+1; j++) {
			for (int k = 1; k < n+1; k++) {
				cin >> color;
				wall[j][k] = (color == 'y') ? 0 : 1;
			}
		}
		minStep = enumerate(n);
		if (minStep == 226) {
			cout << "inf" << endl;
		}
		else {
			cout << minStep << endl;
		}
	}
}