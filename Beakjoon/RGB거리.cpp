#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int t;
	int** arr;
	int** dp;

	cin >> t;

	arr = new int* [t];

	for (int i = 0; i < t; i++) {
		arr[i] = new int[3];
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}

	dp = new int* [t + 1];
	for (int i = 0; i < t + 1; i++) {
		dp[i] = new int[3]{ 0, };
	}

	for (int i = 1; i < t + 1; i++) {
		if (i == 1) {
			dp[i][0] = arr[i - 1][0];
			dp[i][1] = arr[i - 1][1];
			dp[i][2] = arr[i - 1][2];
		}
		else {
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i - 1][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i - 1][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i - 1][2];
		}
	}

	cout << min(min(dp[t][0], dp[t][1]), dp[t][2]) << endl;
	return 0;
}