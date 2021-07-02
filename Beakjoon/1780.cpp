#include <iostream>
using namespace std;

int ans[3] = {0, 0, 0};
int board[2187][2187];

void func(int x, int y, int size)
{
    int type = board[y][x];
    bool divide = false;
    if (size > 1)
    {
        for (int i = y; i < y + size; i++)
        {
            for (int j = x; j < x + size; j++)
            {
                if (type != board[i][j])
                {
                    divide = true;
                    break;
                }
            }
            if (divide)
            {
                break;
            }
        }

        if (divide)
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    func(x + (size / 3) * j, y + (size / 3) * i, size / 3);
                }
            }
        }
        else
        {
            if (type == -1)
            {
                ans[0]++;
            }
            else if (type == 0)
            {
                ans[1]++;
            }
            else
            {
                ans[2]++;
            }
        }
    }
    else
    {
        if (type == -1)
        {
            ans[0]++;
        }
        else if (type == 0)
        {
            ans[1]++;
        }
        else
        {
            ans[2]++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    func(0, 0, n);

    for (int i = 0; i < 3; i++)
    {
        cout << ans[i] << "\n";
    }

    return 0;
}
