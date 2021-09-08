#include<iostream>
#include<cstring>

using namespace std;

int mem[100], cost[100], dp[2][10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, idx = 0, answer = 0;

	memset(dp, 0, sizeof(dp));

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> mem[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= 10000; j++) {
			if (j >= cost[i])
				dp[idx][j] = max(dp[idx ^ 1][j], dp[idx ^ 1][j - cost[i]] + mem[i]);
			else
				dp[idx][j] = dp[idx ^ 1][j];
		}
		idx ^= 1;
	}

	for (int i = 0; i <= 10000; i++) {
		if (dp[idx ^ 1][i] >= m) {
			answer = i;
			break;
		}
	}

	cout << answer << "\n";
	return 0;
}
