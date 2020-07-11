#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(void)
{
	int dp[2][1001]{ 0, };
	int x, y;
	string* board;
	int idx = 0;
	int max_v = 0;

	cin >> x >> y;
	board = new string[x];

	for (int i = 0; i < x; i++) {
		cin >> board[i];
	}

	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			if (board[i - 1][j - 1] != '0') {
				if (dp[idx][j - 1] == dp[idx ^ 1][j - 1] && dp[idx ^ 1][j] == dp[idx ^ 1][j - 1]) {
					dp[idx][j] = dp[idx ^ 1][j - 1] + 1;
				}
				else {
					dp[idx][j] = min(dp[idx][j - 1], min(dp[idx ^ 1][j - 1], dp[idx ^ 1][j])) + 1;
				}

				if (max_v < dp[idx][j]) {
					max_v = dp[idx][j];
				}
			}
			else {
				dp[idx][j] = 0;
			}
		}
		idx ^= 1;
	}

	cout << max_v * max_v << endl;

	return 0;
}