#include <iostream>
using namespace std;

int from[1000001];

void print(int idx)
{
    cout << idx << " ";
    if (from[idx] != 0)
    {
        print(from[idx]);
    }
}
int main()
{
    ios::sync_with_stdio(false);

    int n;
    int dp[1000001];

    cin >> n;

    for (int i = 2; i < n + 1; i++)
    {
        dp[i] = dp[i - 1] + 1;
        from[i] = i - 1;
        if (i % 2 == 0)
        {
            if (dp[i / 2] + 1 < dp[i])
            {
                dp[i] = dp[i / 2] + 1;
                from[i] = i / 2;
            }
        }
        if (i % 3 == 0)
        {
            if (dp[i / 3] + 1 < dp[i])
            {
                dp[i] = dp[i / 3] + 1;
                from[i] = i / 3;
            }
        }
    }

    cout << dp[n] << "\n";

    print(n);
    return 0;
}
