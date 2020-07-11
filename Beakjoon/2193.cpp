#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int t;
	long long** dp;

	cin >> t;

	dp = new long long* [t];

	for (int i = 0; i < t; i++) {
		dp[i] = new long long[2]{ 0, };
	}

	for (int i = 0; i < t; i++) {
		if (i == 0) {
			dp[i][0] = 0;
			dp[i][1] = 1;
		}
		else {
			dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
			dp[i][1] = dp[i - 1][0];
		}
	}

	cout << dp[t - 1][0] + dp[t - 1][1] << endl;


	return 0;
}