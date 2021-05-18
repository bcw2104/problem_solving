#include <iostream>
#include <queue>
using namespace std;

#define maxnum 100001

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    int t = maxnum;
    queue<pair<int, int>> q;
    int visit[maxnum]{
        0,
    };

    cin >> x >> y;

    q.push(make_pair(x, 0));

    while (!q.empty())
    {
        int cur = q.front().first;
        int m = q.front().second;

        q.pop();
        if (cur == y && m < t)
        {
            t = m;
        }

        visit[cur] = 1;

        if (t > m)
        {
            if (cur - 1 >= 0 && visit[cur - 1] == 0)
                q.push(make_pair(cur - 1, m + 1));
            if (cur + 1 <= 100000 && visit[cur + 1] == 0)
                q.push(make_pair(cur + 1, m + 1));
            if (cur * 2 <= 100000 && visit[cur * 2] == 0)
                q.push(make_pair(cur * 2, m));
        }
    }

    cout << t << "\n";

    return 0;
}
