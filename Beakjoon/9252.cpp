#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str1, str2;
    int s1, s2;
    int dp[1001][1001];
    stack<char> s;

    cin >> str1 >> str2;

    s1 = str1.size();
    s2 = str2.size();

    for (int i = 0; i < s2; i++)
    {
        for (int j = 0; j < s1; j++)
        {
            if (str2[i] == str1[j])
            {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else
            {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }

    cout << dp[s2][s1] << "\n";

    if (dp[s2][s1] > 0)
    {
        while (s1 != 0 && s2 != 0)
        {
            if (str1[s1 - 1] == str2[s2 - 1])
            {
                s.push(str1[s1 - 1]);
                s1--;
                s2--;
            }
            else if (dp[s2][s1 - 1] == dp[s2][s1])
            {
                s1--;
            }
            else if (dp[s2 - 1][s1] == dp[s2][s1])
            {
                s2--;
            }
        }
        while (!s.empty())
        {
            cout << s.top();
            s.pop();
        }
    }

    return 0;
}
