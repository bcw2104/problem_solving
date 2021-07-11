#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 100001

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, ans = -1, cnt = 0;
    bool visit[MAX];
    queue<pair<int, int>> q;

    cin >> a >> b;

    memset(visit, 0, sizeof(visit));

    q.push(make_pair(a, 0));
    visit[a] = 1;

    while (!q.empty())
    {
        int x = q.front().first;
        int t = q.front().second;

        visit[x] = 1;

        q.pop();

        if (ans == -1 && x == b)
        {
            ans = t;
        }

        if (t == ans && x == b)
        {
            cnt++;
        }

        if (x - 1 >= 0 && visit[x - 1] == 0)
        {
            q.push(make_pair(x - 1, t + 1));
        }
        if (x + 1 < MAX && visit[x + 1] == 0)
        {
            q.push(make_pair(x + 1, t + 1));
        }
        if (x * 2 < MAX && visit[x * 2] == 0)
        {
            q.push(make_pair(x * 2, t + 1));
        }
    }

    cout << ans << "\n";
    cout << cnt << "\n";
    return 0;
}
