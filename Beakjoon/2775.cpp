#include<iostream>
using namespace std;

int main(void)
{
	int t;
	int k, n, idx;
	int** dp;

	cin >> t;
	while (t > 0) {
		cin >> k >> n;

		dp = new int* [2];
		idx = 0;
		for (int i = 0; i < 2; i++) {
			dp[i] = new int[n + 1]{ 0, };
		}

		for (int i = 1; i < n + 1; i++) {
			dp[idx ^ 1][i] = i;
		}

		for (int i = 0; i < k; i++) {
			for (int j = 1; j < n + 1; j++) {
				dp[idx][j] = dp[idx ^ 1][j] + dp[idx][j - 1];
			}
			idx ^= 1;
		}

		cout << dp[idx ^ 1][n] << endl;

		t--;
	}
	return 0;
}