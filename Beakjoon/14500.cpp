#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int X[4] = {0, 1, 0, -1};
int Y[4] = {1, 0, -1, 0};

int ans = 0;
int n, m;
int arr[500][500];
bool visit[500][500];

void dfs(int x, int y, int t, int sum)
{
    visit[y][x] = 1;
    sum += arr[y][x];
    t--;

    if (t == 0)
    {
        if (ans < sum)
            ans = sum;
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            int nx = x + X[i];
            int ny = y + Y[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && visit[ny][nx] == 0)
            {
                dfs(nx, ny, t, sum);
            }
        }
    }

    visit[y][x] = 0;
}

void func(int x, int y)
{
    int sum = arr[y][x];
    int temp[4] = {0, 0, 0, 0};
    int cnt = 0;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + X[i];
        int ny = y + Y[i];

        if (nx >= 0 && nx < m && ny >= 0 && ny < n)
        {
            cnt++;
            temp[i] = arr[ny][nx];
        }
    }

    if (cnt >= 3)
    {
        sort(temp, temp + 4);

        for (int i = 3; i >= 1; i--)
        {
            sum += temp[i];
        }
    }

    if (ans < sum)
        ans = sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(visit, 0, sizeof(visit));
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dfs(j, i, 4, 0);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            func(j, i);
        }
    }

    cout << ans << "\n";

    return 0;
}
