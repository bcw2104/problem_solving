#include<iostream>
#include<cstring>

using namespace std;

int dp[500][500];
int p[501];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;

	memset(dp, -1, sizeof(dp));

	cin >> n; 

	for (int i = 0; i < n; i++) {
		cin >> p[i] >> p[i+1];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-i; j++) {
			if (i == 0)
				dp[j][i + j] = 0;
			else if (i == 1)
				dp[j][i + j] = p[j] * p[i + j] * p[i + j + 1];
			else {
				for (int k = j; k < i + j; k++) {
					if (dp[j][i + j] == -1)
						dp[j][i + j] = dp[j][k] + dp[k + 1][i + j] + p[j] * p[k + 1] * p[i + j + 1];
					else
						dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + p[j] * p[k + 1] * p[i + j + 1]);

				}
			}
		}
	}

	cout << dp[0][n - 1] << "\n";

	return 0;
}
