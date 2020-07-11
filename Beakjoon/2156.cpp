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

	dp = new int* [t];

	for (int i = 0; i < t; i++) {
		dp[i] = new int[2]{ 0, };
	}


	for (int i = 0; i < t; i++) {
		if (i == 0) {
			dp[i][0] = 0;
			dp[i][1] = arr[i];
		}
		else if (i == 1) {
			dp[i][0] = dp[i - 1][1];
			dp[i][1] = arr[i] + dp[i - 1][1];
		}
		else {
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
			if (arr[i] == 0) {
				dp[i][1] = 0;
			}
			else {
				dp[i][1] = max(dp[i - 2][0] + arr[i - 1] + arr[i], dp[i - 1][0] + arr[i]);
			}
		}
	}

	cout << max(dp[t - 1][0], dp[t - 1][1]) << endl;
	return 0;
}