#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b;
    int arr[101];
    int ans = 0;
    bool visit[101];
    queue<pair<int, int>> q;

    memset(arr, 0, sizeof(arr));
    memset(visit, 0, sizeof(visit));

    cin >> n >> m;

    for (int i = 0; i < n + m; i++)
    {
        cin >> a >> b;

        arr[a] = b;
    }

    q.push({1, 0});
    visit[1] = 1;

    while (!q.empty())
    {
        int cur = q.front().first;
        int time = q.front().second;
        q.pop();

        if (cur == 100)
        {
            ans = time;
            break;
        }

        for (int i = 1; i <= 6; i++)
        {
            int next = cur + i;
            if (next <= 100 && visit[next] == 0)
            {
                visit[next] = 1;
                if (arr[next] != 0)
                {
                    if (visit[arr[next]] == 0)
                    {
                        visit[arr[next]] = 1;
                        q.push({arr[next], time + 1});
                    }
                }
                else
                {
                    q.push({next, time + 1});
                }
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
