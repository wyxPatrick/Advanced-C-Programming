#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

int N, C;
int l, r, mid;
vector<int> stalls;

bool check(int ans) {
	int count = 0;
	int next_place = stalls[0];
	for (int i = 0; i < stalls.size(); i++) {
		if (stalls[i] >= next_place) {
			count++;
			next_place = stalls[i] + ans;
		}
	}
	if (count >= C)
		return true;
	else
		return false;
}

int main() {
	cin >> N >> C;
	int s;
	for (int i = 0; i < N; i++) {
		scanf("%d", &s);
		stalls.push_back(s);
	}
	sort(stalls.begin(), stalls.end());
	int l = 1;
	int r = (stalls[stalls.size() - 1] - stalls[0]) / (C - 1);
	int mid = 0;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid))
			l = mid + 1;
		else
			r = mid - 1;
	}
	cout << r << endl;
	return 0;
}