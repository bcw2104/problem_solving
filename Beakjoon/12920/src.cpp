#include<iostream>
#include<vector>
using namespace std;

#define MAX 10001

int dp[2][MAX] = { 0, };
vector<pair<int,int>> item;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, idx=0, v, c, k;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> v >> c >> k;

		int x = 1;

		while (k > 0) {
			int t = min(x, k);
			item.push_back({ v * t,c * t });
			k -= x;
			x <<= 1;
		}
	}

	for (int i = 0; i < item.size(); i++) {
		for (int j = 1; j <= m; j++) {
			if (j < item[i].first) {
				dp[idx][j] = dp[idx ^ 1][j];
			}
			else {
				dp[idx][j] = max(dp[idx ^ 1][j],dp[idx^1][j- item[i].first] + item[i].second);
			}

		}
		idx ^= 1;
	}

	cout << dp[idx ^ 1][m] << "\n";
	return 0;
}
