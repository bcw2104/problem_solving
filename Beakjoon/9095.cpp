#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int t;
	int num;
	int* dp;

	cin >> t;

	while (t > 0) {
		cin >> num;

		dp = new int[num + 1]{ 0, };

		for (int i = 1; i < num + 1; i++) {
			if (i == 1) {
				dp[i] = 1;
			}
			else if (i == 2) {
				dp[i] = dp[i - 1] + 1;
			}
			else if (i == 3) {
				dp[i] = dp[i - 1] + dp[i - 2] + 1;
			}
			else {
				dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
			}
		}
		cout << dp[num] << endl;
		t--;
	}
	return 0;
}