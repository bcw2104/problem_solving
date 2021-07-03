#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int X[4] = {1, 0, -1, 0};
int Y[4] = {0, 1, 0, -1};

typedef struct Node
{
    int x;
    int y;
    int dist;
} node;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, ans = 0;
    string str;
    bool visit[100][100];
    int map[100][100];
    queue<node> q;

    memset(visit, 0, sizeof(visit));

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            map[i][j] = str[j] - 48;
        }
    }

    q.push({0, 0, 1});

    while (!q.empty())
    {
        node cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.x + X[i];
            int ny = cur.y + Y[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && map[ny][nx] == 1 && visit[ny][nx] == 0)
            {
                if (nx == m - 1 && ny == n - 1)
                {
                    ans = cur.dist + 1;
                    break;
                }
                else
                {
                    q.push({nx, ny, cur.dist + 1});
                    visit[ny][nx] = 1;
                }
            }
        }

        if (ans > 0)
        {
            break;
        }
    }

    cout << ans << "\n";
    return 0;
}
