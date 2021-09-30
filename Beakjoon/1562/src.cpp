#include<iostream>
using namespace std;

#define MOD 1000000000

int dp[101][10][4] = { 0, };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    long long ans=0;

    cin >> n;

    for (int j = 1; j < 10; j++) {
        if(j==9)
            dp[1][j][2] = 1;
        else
            dp[1][j][0] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) {
                dp[i][j][1] = (dp[i - 1][j + 1][0] + dp[i - 1][j + 1][1]) % MOD;
                dp[i][j][3] = (dp[i - 1][j + 1][2] + dp[i - 1][j + 1][3]) % MOD;
            }
            else if (j == 9) {
                dp[i][j][2] = (dp[i - 1][j - 1][0] + dp[i - 1][j - 1][2]) % MOD;
                dp[i][j][3] = (dp[i - 1][j - 1][1] + dp[i - 1][j - 1][3]) % MOD;
            }
            else {
                for (int k = 0; k < 4; k++) {
                    dp[i][j][k] = (dp[i - 1][j - 1][k] + dp[i - 1][j + 1][k]) % MOD;
                }
            }
        }
    }

    for (int j = 0; j < 10; j++) {
        ans = (ans + dp[n][j][3]) % MOD;
    }

    cout << ans  << "\n";
    return 0;
}
