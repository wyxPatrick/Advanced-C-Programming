#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;

const int N = 50 + 5;
int dp[N][N], dp1[N], dp2[N];

int main() {
	for (int n, k; scanf("%d%d", &n, &k) == 2;) {
		memset(dp, 0, sizeof(dp));
		memset(dp1, 0, sizeof(dp1));
		memset(dp2, 0, sizeof(dp2));
		dp[0][0] = 1;
		for (int i = 1; i <= n; i++)
			for (int j = i; j <= n; j++)
				for (int q = k; q >= 1; q--)
					dp[j][q] += dp[j - i][q - 1];
		printf("%d\n", dp[n][k]);
		dp1[0] = 1;
		for (int i = 1; i <= n; i++)
			for (int j = n; j >= i; j--)
				dp1[j] += dp1[j - i];
		printf("%d\n", dp1[n]);
		dp2[0] = 1;
		for (int i = 1; i <= n; i += 2)
			for (int j = i; j <= n; j++)
				dp2[j] += dp2[j - i];
		printf("%d\n", dp2[n]);
	}
	return 0;
}