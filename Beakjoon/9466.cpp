#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    int arr[100001];
    int visit[100001];
    int size, count;
    bool flag = false;

    stack<int> s;

    cin >> t;

    while (t > 0)
    {
        cin >> n;

        count = 0;
        memset(visit, 0, sizeof(visit));

        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 1; i <= n; i++)
        {
            if (visit[i] == 0)
            {
                s.push(i);
                visit[i] = 1;
                while (1)
                {
                    int next = arr[s.top()];
                    s.push(next);
                    if (visit[next] == 0)
                    {
                        visit[next] = 1;
                    }
                    else
                    {
                        break;
                    }
                }

                int end = s.top();
                s.pop();

                size = s.size();

                while (!s.empty())
                {
                    if (flag == true)
                    {
                        s.pop();
                        count++;
                        continue;
                    }

                    if (s.top() == end)
                    {
                        flag = true;
                    }
                    s.pop();
                }

                if (!flag)
                {
                    count += size;
                }

                flag = false;
            }
        }

        cout << count << "\n";

        t--;
    }
    return 0;
}
