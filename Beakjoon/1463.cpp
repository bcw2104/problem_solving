#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int num;
	int* dp;

	cin >> num;
	dp = new int[num + 1]{ 0, };


	for (int i = 2; i < num + 1; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0) {
			dp[i] = min(dp[i / 2] + 1, dp[i]);
		}
		if (i % 3 == 0) {
			dp[i] = min(dp[i / 3] + 1, dp[i]);
		}
	}

	cout << dp[num] << endl;
	return 0;
}