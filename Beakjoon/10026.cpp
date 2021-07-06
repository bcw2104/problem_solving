#include <iostream>
#include <cstring>
using namespace std;

int X[4] = {0, 1, 0, -1};
int Y[4] = {1, 0, -1, 0};

int n;
char c;
char arr[100][100];
bool visit[100][100];

void func(int x, int y, bool flag)
{
    visit[y][x] = 1;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + X[i];
        int ny = y + Y[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < n && visit[ny][nx] == 0)
        {
            if (arr[ny][nx] == c)
            {
                func(nx, ny, flag);
            }
            else if (flag && ((c == 'R' && arr[ny][nx] == 'G') || (c == 'G' && arr[ny][nx] == 'R')))
            {
                func(nx, ny, flag);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ans1, ans2;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    memset(visit, 0, sizeof(visit));

    ans1 = 0;
    ans2 = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visit[i][j])
            {
                ans1++;
                c = arr[i][j];
                func(j, i, false);
            }
        }
    }

    memset(visit, 0, sizeof(visit));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visit[i][j])
            {
                ans2++;
                c = arr[i][j];
                func(j, i, true);
            }
        }
    }

    cout << ans1 << " " << ans2 << "\n";

    return 0;
}
