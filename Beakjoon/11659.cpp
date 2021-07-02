#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, num;
    int a, b;
    int dp[100001];
    int sum = 0;

    memset(dp, 0, sizeof(dp));

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> num;
        sum += num;
        dp[i] = sum;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;

        cout << dp[b] - dp[a - 1] << "\n";
    }
    return 0;
}
