#include <iostream>
#include <cstring>
using namespace std;

#define MAX 10000

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b;
    int dp[101][101];

    memset(dp, MAX, sizeof(dp));

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;

        dp[a][b] = 1;
        dp[b][a] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int dist = dp[i][j];

            if (dist != MAX && dist != 0)
            {
                for (int k = 1; k <= n; k++)
                {
                    dp[j][k] = min(dp[j][k], dp[i][k] + dist);
                }
            }
        }
    }

    int sum, ans, msum = MAX;

    for (int i = 1; i <= n; i++)
    {
        sum = 0;
        for (int j = 1; j <= n; j++)
        {
            sum += dp[i][j];
        }

        if (sum < msum)
        {
            msum = sum;
            ans = i;
        }
    }

    cout << ans << "\n";

    return 0;
}
