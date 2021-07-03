#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int X[4] = {1, 0, -1, 0};
int Y[4] = {0, 1, 0, -1};

int n;
int cnt = 0;
int map[25][25];
vector<int> ans;

int func(int x, int y)
{
    int rs = 1;
    map[y][x] = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + X[i];
        int ny = y + Y[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < n && map[ny][nx] == 1)
        {
            rs += func(nx, ny);
        }
    }

    return rs;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> str;
        for (int j = 0; j < n; j++)
        {
            map[i][j] = str[j] - 48;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 1)
            {
                ans.push_back(func(j, i));
                cnt++;
            }
        }
    }

    sort(ans.begin(), ans.end());

    cout << cnt << "\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "\n";
    }
    return 0;
}
