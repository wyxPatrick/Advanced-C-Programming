#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int num[7], tmp[7], len, mm, t, f;

int getlen(int x) {
	int cnt = 1;
	while (x) {
		x /= 10;
		cnt *= 10;
	}
	return cnt / 10;
}

void dfs(int rest, int sum, int site, int l, int p) {
	if (sum + rest <= t && sum + rest >= mm) {
		if (sum + rest == mm || p == 1) {
			f = 1;
			mm = sum + rest;
			return;
		}
		f = 0;
		mm = sum + rest;
		memcpy(num, tmp, sizeof(tmp));
		num[site++] = rest;
		len = site;
		return;
	}
	if (sum + rest < t && sum + rest < mm) return;
	for (int i = l; i >= 1; i /= 10) {
		tmp[site] = rest / i;
		if (i > 10 && rest % i / (i / 10) == 0) dfs(rest % i, sum + rest / i, site + 1, i / 100, 1);
		else dfs(rest % i, sum + rest / i, site + 1, i / 10, p);
	}
}

int main() {
	int n;
	while (~scanf("%d %d", &t, &n) && (t + n)) {
		f = 0;
		len = 0;
		mm = -1;
		dfs(n, 0, 0, getlen(n), 0);

		if (mm == -1) puts("error");
		else if (f) puts("rejected");
		else {
			printf("%d", mm);
			for (int i = 0; i < len; ++i) printf(" %d", num[i]);
			puts("");
		}
	}
	return 0;
}