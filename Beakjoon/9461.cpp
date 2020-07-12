#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int t;
	int len;
	long long* dp;
	cin >> t;

	while (t > 0) {
		cin >> len;

		dp = new long long[len] {0, };

		if (len <= 3) {
			cout << 1 << endl;
		}
		else if (len <= 5) {
			cout << 2 << endl;
		}
		else {
			dp[0] = 1;
			dp[1] = 1;
			dp[2] = 1;
			dp[3] = 2;
			dp[4] = 2;

			for (int i = 5; i < len; i++) {
				dp[i] = dp[i - 1] + dp[i - 5];
			}
			cout << dp[len - 1] << endl;
		}
		t--;
	}
	return 0;
}