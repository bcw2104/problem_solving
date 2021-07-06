#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int X[4] = {0, -1, 0, 1};
int Y[4] = {-1, 0, 1, 0};

typedef struct Info
{
    int x, y, size, cnt, time;
} info;

struct compare
{
    bool operator()(info a, info b)
    {
        if (a.time == b.time)
        {
            if (a.y == b.y)
                return a.x > b.x;

            return a.y > b.y;
        }
        return a.time > b.time;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int arr[20][20];
    bool visit[20][20];
    int ans;
    queue<info> q;
    priority_queue<info, vector<info>, compare> pq;

    memset(visit, 0, sizeof(visit));

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 9)
            {
                q.push({j, i, 2, 0, 0});
                visit[i][j] = 1;
                arr[i][j] = 0;
            }
        }
    }

    while (!q.empty())
    {
        info t = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = t.x + X[i];
            int ny = t.y + Y[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && visit[ny][nx] == 0 && arr[ny][nx] <= t.size)
            {
                if (arr[ny][nx] == t.size || arr[ny][nx] == 0)
                {
                    if (pq.empty() || (!pq.empty() && pq.top().time > t.time + 1))
                    {
                        q.push({nx, ny, t.size, t.cnt, t.time + 1});
                        visit[ny][nx] = 1;
                    }
                }
                else
                {
                    ans = t.time + 1;

                    int cnt = t.cnt + 1;
                    if (t.size == cnt)
                    {
                        pq.push({nx, ny, t.size + 1, 0, ans});
                    }
                    else
                    {
                        pq.push({nx, ny, t.size, cnt, ans});
                    }

                    visit[ny][nx] = 1;
                }
            }
        }

        if (q.empty() && !pq.empty())
        {
            q.push(pq.top());
            arr[pq.top().y][pq.top().x] = 0;

            memset(visit, 0, sizeof(visit));

            while (!pq.empty())
            {
                pq.pop();
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
