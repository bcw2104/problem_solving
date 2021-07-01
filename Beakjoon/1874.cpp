#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, num, next;
    bool fail = false;
    stack<int> s;
    queue<int> q;
    queue<char> ans;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> num;

        q.push(num);
    }

    num = 1;

    while (!q.empty())
    {
        next = q.front();

        if (s.empty() || s.top() < next)
        {
            ans.push('+');
            s.push(num);
            num++;
        }
        else if (s.top() == next)
        {
            ans.push('-');
            q.pop();
            s.pop();
        }
        else
        {
            while (!s.empty())
            {
                if (s.top() != next)
                {
                    s.pop();
                }
                else
                {
                    ans.push('-');
                    s.pop();
                    q.pop();
                    break;
                }
            }

            if (s.empty())
            {
                cout << "NO\n";
                fail = true;
                break;
            }
        }
    }

    if (!fail)
    {
        while (!ans.empty())
        {
            cout << ans.front() << "\n";
            ans.pop();
        }
    }
    return 0;
}1
