#include<iostream>
using namespace std;

#define MOD 1000000000

int dp[101][10] = { 0, };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    long long ans = 0;

    cin >> n;

    for (int j = 1; j < 10; j++) {
        dp[1][j] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0)
                dp[i][j] = dp[i - 1][j + 1];
            else if (j == 9)
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
        }
    }

    for (int j = 0; j < 10; j++) {
        ans = (ans + dp[n][j]) % MOD;
    }

    cout << ans << "\n";
    return 0;
}
