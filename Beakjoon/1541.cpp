#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    string num = "";
    queue<char> oq;
    queue<int> nq;
    int ans = 0;
    bool m = false;

    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '-' || str[i] == '+')
        {
            oq.push(str[i]);
            nq.push(atoi(num.c_str()));
            num = "";
        }
        else
        {
            num += str[i];
        }
    }

    nq.push(atoi(num.c_str()));

    ans = nq.front();
    nq.pop();

    while (!nq.empty())
    {
        char op = oq.front();
        int n = nq.front();

        oq.pop();
        nq.pop();
        if (op == '-')
        {
            if (!m)
            {
                m = true;
            }
            ans -= n;
        }
        else
        {
            if (!m)
            {
                ans += n;
            }
            else
            {
                ans -= n;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
