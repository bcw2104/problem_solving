#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;

    cin >> t;

    while (t > 0)
    {
        cin >> n;

        int arr[100000][2];
        int dp[100001][2];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i][0];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i][1];
        }

        dp[1][0] = arr[0][0];
        dp[1][1] = arr[0][1];

        for (int i = 2; i <= n; i++)
        {
            dp[i][0] = max(dp[i - 1][1], dp[i - 2][1]) + arr[i - 1][0];
            dp[i][1] = max(dp[i - 1][0], dp[i - 2][0]) + arr[i - 1][1];
        }

        cout << max(dp[n][0], dp[n][1]) << "\n";

        t--;
    }
    return 0;
}
