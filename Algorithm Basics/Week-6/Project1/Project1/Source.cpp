#include <iostream>
#include <cstring>
using namespace std;

char grid[8][8];
bool flag[8];
int n;
int res;

void dfs(int row, int k) {
	if (k == 0) {
		res++;
		return;
	}
	if (row >= n) {
		return;
	}
	for (int col = 0; col < n; col++) {
		if (!flag[col] && grid[row][col] == '#') {
			flag[col] = 1;
			dfs(row + 1, k - 1);
			flag[col] = 0;
		}
	}
	dfs(row + 1, k);
}

int main() {
	int k;
	while (1) {
		cin >> n >> k;
		if (n == -1 && k == -1) {
			break;
		}
		memset(grid, '.', sizeof(grid));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> grid[i][j];
		memset(flag, 0, sizeof(flag));
		res = 0;
		dfs(0, k);
		cout << res << endl;
	}
	return 0;
}