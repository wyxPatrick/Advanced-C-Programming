#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 27;
bool map[MAX][MAX];
int dx[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };
char path[MAX * MAX * 2];
bool succ;
int p, q;
int steps;

void dfs(int x, int y) {
	if (succ) {
		return;
	}
	map[x][y] = true;
	path[steps++] = x + 'A' - 1;
	path[steps++] = y + '0';

	if (steps == p * q * 2) {
		succ = true;
		return;
	}

	for (int i = 0; i < 8; i++) {
		int newx = x + dx[i];
		int newy = y + dy[i];

		if ((newx > 0 && newx <= q && newy > 0 && newy <= p && !map[newx][newy]) && !succ) {
			dfs(newx, newy);
			steps -= 2;
			map[newx][newy] = false;
		}
	}
}

int main() {
	int cases, i = 0;
	cin >> cases;

	while (cases--) {
		cin >> p >> q;

		memset(map, false, sizeof(map));
		memset(path, 0, sizeof(path));
		steps = 0;
		succ = false;

		dfs(1, 1);

		cout << "Scenario #" << ++i << ":" << endl;
		if (succ) {
			cout << path << endl << endl;
		}
		else {
			cout << "impossible" << endl << endl;
		}
	}
	return 0;
}