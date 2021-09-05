#include <iostream>

using namespace std;

#define MAX 1001

int cost[1000][3];
int dp[1000][3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,answer = MAX*MAX;
 
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    dp[0][0] = cost[0][0];
    dp[0][1] = cost[0][1];
    dp[0][2] = cost[0][2];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j)
                dp[1][j] = MAX * MAX;
            else
                dp[1][j] = cost[1][j] + dp[0][i];
        }

        if (n > 2) {
            for (int j = 2; j < n - 1; j++) {
                for (int k = 0; k < 3; k++) {
                    dp[j][k] = cost[j][k] + min(dp[j - 1][(k + 1) % 3], dp[j - 1][(k + 2) % 3]);
                }
            }

            for (int j = 0; j < 3; j++) {
                if (i == j)
                    dp[n - 1][j] = MAX * MAX;
                else {
                    dp[n - 1][j] = cost[n - 1][j] + min(dp[n - 2][(j + 1) % 3], dp[n - 2][(j + 2) % 3]);
                }
            }
        }

        for (int j = 0; j < 3; j++) {
            answer = (answer > dp[n - 1][j] ? dp[n - 1][j] : answer);
        }
    }

    cout << answer << "\n";

    return 0;
}
