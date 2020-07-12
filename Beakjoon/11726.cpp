#include<iostream>
#include<string>
#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int num;
	int* dp;

	cin >> num;
	dp = new int[num + 1]{ 0, };

	for (int i = 1; i < num + 1; i++) {
		if (i == 1) {
			dp[i] = 1;
		}
		else if (i == 2) {
			dp[i] = 2;
		}
		else {
			dp[i] = dp[i - 1] + dp[i - 2];
			if (dp[i] >= 10007) {
				dp[i] = dp[i] % 10007;
			}
		}
	}

	cout << dp[num] << endl;
	return 0;
}