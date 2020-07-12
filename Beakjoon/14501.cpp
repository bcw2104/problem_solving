#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int t;

	int** arr;
	int** dp;
	int idx;
	cin >> t;

	arr = new int* [t];

	for (int i = 0; i < t; i++) {
		arr[i] = new int[2]{ 0, };

		cin >> arr[i][0] >> arr[i][1];
	}

	dp = new int* [2];

	for (int i = 0; i < 2; i++) {
		dp[i] = new int[t + 2]{ 0, };
	}
	idx = 0;

	for (int i = 1; i < t + 1; i++) {
		for (int j = 1; j < t + 2; j++) {
			if (j == i + arr[i - 1][0]) {
				dp[idx][j] = max(dp[idx][i] + arr[i - 1][1], dp[idx ^ 1][j]);
			}
			else if (j > i + arr[i - 1][0]) {
				dp[idx][j] = max(dp[idx][i + arr[i - 1][0]], dp[idx ^ 1][j]);
			}
			else {
				dp[idx][j] = dp[idx ^ 1][j];
			}
		}
		idx ^= 1;
	}
	cout << dp[idx ^ 1][t + 1] << endl;
	return 0;
}