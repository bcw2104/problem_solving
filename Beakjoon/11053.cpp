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

	arr = new int[t];

	for (int i = 0; i < t; i++) {
		cin >> arr[i];
	}

	dp = new int* [2];

	for (int i = 0; i < 2; i++) {
		dp[i] = new int[1001]{ 0, };
	}

	for (int i = 0; i < t; i++) {
		for (int j = 1; j < 1001; j++) {
			if (j == arr[i]) {
				dp[idx][j] = dp[idx][j - 1] + 1;
			}
			else if (j > arr[i]) {
				dp[idx][j] = max(dp[idx][j - 1], dp[idx ^ 1][j]);
			}
			else {
				dp[idx][j] = dp[idx ^ 1][j];
			}
		}
		idx ^= 1;
	}

	cout << dp[idx ^ 1][1000] << endl;
	return 0;
}