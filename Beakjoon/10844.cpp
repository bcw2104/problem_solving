#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int t;
	int** dp;
	int idx = 0;
	int result = 0;
	cin >> t;

	if (t == 1) {
		result = 9;
	}
	else {
		dp = new int* [2];
		for (int i = 0; i < 2; i++) {
			dp[i] = new int[10]{ 0, };
		}

		for (int i = 1; i < t + 1; i++) {
			for (int j = 0; j <= 9; j++) {
				if (i == 1) {
					if (j == 0) {
						dp[idx][j] = 0;
					}
					else {
						dp[idx][j] = 1;
					}
				}
				else {
					if (j == 0) {
						dp[idx][j] = dp[idx ^ 1][1];
					}
					else if (j == 9) {
						dp[idx][j] = dp[idx ^ 1][8];
					}
					else {
						dp[idx][j] = (dp[idx ^ 1][j - 1] + dp[idx ^ 1][j + 1]) % 1000000000;
					}
				}
			}
			idx ^= 1;
		}
		for (int i = 0; i <= 9; i++) {
			result += dp[idx ^ 1][i];
			result = result % 1000000000;
		}
	}

	cout << result << endl;
	return 0;
}