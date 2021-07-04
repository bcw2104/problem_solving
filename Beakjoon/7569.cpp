#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int X[4] = {0, 1, 0, -1};
int Y[4] = {1, 0, -1, 0};
int Z[2] = {1, -1};

typedef struct NODE
{
    int h, y, x, d;
} node;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n, h;
    int arr[100][100][100];
    int day;
    int cnt = 0;
    queue<node> q;

    cin >> m >> n >> h;

    memset(arr, 0, sizeof(arr));

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                cin >> arr[i][j][k];

                if (arr[i][j][k] == 1)
                {
                    q.push({i, j, k, 0});
                }
                else if (arr[i][j][k] == 0)
                {
                    cnt++;
                }
            }
        }
    }

    while (!q.empty())
    {
        node t = q.front();
        q.pop();

        day = t.d;

        for (int i = 0; i < 2; i++)
        {
            int nh = t.h + Z[i];

            if (nh >= 0 && nh < h && arr[nh][t.y][t.x] == 0)
            {
                arr[nh][t.y][t.x] = 1;
                q.push({nh, t.y, t.x, t.d + 1});

                cnt--;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = t.x + X[i];
            int ny = t.y + Y[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && arr[t.h][ny][nx] == 0)
            {
                arr[t.h][ny][nx] = 1;
                q.push({t.h, ny, nx, t.d + 1});
                cnt--;
            }
        }
    }

    if (cnt == 0)
    {
        cout << day << "\n";
    }
    else
    {
        cout << "-1\n";
    }

    return 0;
}
