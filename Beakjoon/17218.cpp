#include <iostream>
#include <cstring>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int dp[41][41];
    string str1, str2;
    int size1, size2;
    stack<char> ans;

    memset(dp, 0, sizeof(dp));

    cin >> str1 >> str2;

    size1 = str1.length();
    size2 = str2.length();

    for (int i = 1; i <= size2; i++)
    {
        for (int j = 1; j <= size1; j++)
        {
            if (str1[j - 1] == str2[i - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int x = size2;
    int y = size1;
    while (dp[x][y])
    {
        if (dp[x][y] == dp[x - 1][y])
        {
            x--;
        }
        else if (dp[x][y] == dp[x][y - 1])
        {
            y--;
        }
        else if (dp[x][y] == dp[x - 1][y - 1] + 1)
        {
            ans.push(str2[x - 1]);
            x--;
            y--;
        }
    }

    while (!ans.empty())
    {
        cout << ans.top();
        ans.pop();
    }

    cout << "\n";

    return 0;
}
