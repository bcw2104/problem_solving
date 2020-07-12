#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int t;

	int* arr;
	int** dp;
	int idx = 0;
	cin >> t;

	arr = new int[t] {0, };

	for (int i = 0; i < t; i++) {
		cin >> arr[i];
	}

	dp = new int* [2];

	for (int i = 0; i < 2; i++) {
		dp[i] = new int[t + 1]{ 0, };
	}

	for (int i = 1; i < t + 1; i++) {
		for (int j = 1; j < t + 1; j++) {
			if (j >= i) {
				dp[idx][j] = max(dp[idx ^ 1][j], dp[idx][j - i] + arr[i - 1]);
			}
			else {
				dp[idx][j] = dp[idx ^ 1][j];
			}
		}
		idx ^= 1;
	}


	cout << dp[idx ^ 1][t] << endl;
	return 0;
}