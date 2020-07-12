#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int c, w, idx;
	int** item;
	int** dp;

	cin >> c >> w;

	item = new int* [c];

	for (int i = 0; i < c; i++) {
		item[i] = new int[2];
		cin >> item[i][0] >> item[i][1];
	}

	dp = new int* [2];

	for (int i = 0; i < 2; i++) {
		dp[i] = new int[w + 1]{ 0, };
	}

	idx = 0;
	for (int i = 0; i < c; i++) {
		for (int j = 1; j < w + 1; j++) {
			if (item[i][0] > j) {
				dp[idx][j] = dp[idx ^ 1][j];
			}
			else {
				dp[idx][j] = max(dp[idx ^ 1][j], item[i][1] + dp[idx ^ 1][j - item[i][0]]);
			}
		}
		idx ^= 1;
	}

	cout << dp[idx ^ 1][w] << endl;
	return 0;
}