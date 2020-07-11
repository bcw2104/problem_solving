#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int t;
	int** arr;
	int** dp;
	int idx;
	int result;

	cin >> t;

	arr = new int* [t];

	for (int i = 0; i < t; i++) {
		arr[i] = new int[i + 1];
		for (int j = 0; j < i + 1; j++) {
			cin >> arr[i][j];
		}
	}

	dp = new int* [2];

	for (int i = 0; i < 2; i++) {
		dp[i] = new int[t] { 0, };
	}

	idx = 0;
	for (int i = 0; i < t; i++) {
		for (int j = 0; j <= i; j++) {
			if (i == 0) {
				dp[idx][j] = arr[i][j];
			}
			else {
				if (j == 0) {
					dp[idx][j] = dp[idx ^ 1][j] + arr[i][j];
				}
				else if (j == i) {
					dp[idx][j] = dp[idx ^ 1][j - 1] + arr[i][j];
				}
				else {
					dp[idx][j] = max(dp[idx ^ 1][j - 1] + arr[i][j], dp[idx ^ 1][j] + arr[i][j]);
				}
			}
		}
		idx ^= 1;
	}

	result = 0;
	for (int i = 0; i < t; i++) {
		result = max(result, dp[idx ^ 1][i]);
	}
	cout << result << endl;
	return 0;
}