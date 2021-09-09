#include<iostream>
#include<cstring>

using namespace std;

int arr[2001];
int dp[2001][2001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,m;

	memset(dp, 0, sizeof(dp));

	cin >> n; 

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= n-i; j++) {
			if (i==0)
				dp[j][j] = 1;
			else if(i == 1)
				dp[j][i + j] = (arr[j] == arr[i + j]);
			else {
				dp[j][i+j] = (arr[j] == arr[i + j] && dp[j+1][i + j-1]);
			}
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;

		cout << dp[s][e] << "\n";
	}
	return 0;
}
