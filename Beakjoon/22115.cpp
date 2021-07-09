#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    int idx = 1;
    int ans;
    int arr[100];
    int dp[2][1000001];

    memset(dp, 0, sizeof(dp));

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (j < arr[i])
            {
                dp[idx][j] = dp[idx ^ 1][j];
            }
            else if (arr[i] == j)
            {
                dp[idx][j] = 1;
            }
            else
            {
                if (dp[idx ^ 1][j - arr[i]] != 0)
                {
                    if (dp[idx ^ 1][j] != 0)
                    {
                        dp[idx][j] = min(dp[idx ^ 1][j], dp[idx ^ 1][j - arr[i]] + 1);
                    }
                    else
                    {
                        dp[idx][j] = dp[idx ^ 1][j - arr[i]] + 1;
                    }
                }
                else
                {
                    dp[idx][j] = dp[idx][j] = dp[idx ^ 1][j];
                }
            }
        }

        idx ^= 1;
    }

    if (k > 0 && dp[idx ^ 1][k] == 0)
    {
        ans = -1;
    }
    else
    {
        ans = dp[idx ^ 1][k];
    }

    cout << ans << "\n";

    return 0;
}
