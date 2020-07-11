#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int t;
	int* arr;
	int** dp;

	cin >> t;

	arr = new int[t];

	for (int i = 0; i < t; i++) {
		cin >> arr[i];
	}

	dp = new int* [t + 1];

	for (int i = 0; i < t + 1; i++) {
		dp[i] = new int[2]{ 0, };
	}

	for (int i = 1; i < t + 1; i++) {
		if (i == 1) {
			dp[i][0] = arr[i - 1];
		}
		else if (i == 2) {
			dp[i][0] = arr[i - 1];
			dp[i][1] = dp[i - 1][0] + arr[i - 1];
		}
		else {
			dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + arr[i - 1];
			dp[i][1] = dp[i - 1][0] + arr[i - 1];
		}
	}

	cout << max(dp[t][0], dp[t][1]) << endl;

	return 0;
}