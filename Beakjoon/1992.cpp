#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int board[64][64];

void func(int x, int y, int size)
{
    int type = board[y][x];
    bool div = false;
    for (int i = y; i < y + size; i++)
    {
        for (int j = x; j < x + size; j++)
        {
            if (board[i][j] != type)
            {
                div = true;
                break;
            }
        }
        if (div)
        {
            break;
        }
    }

    if (div)
    {
        cout << "(";
        func(x, y, size / 2);
        func(x + size / 2, y, size / 2);
        func(x, y + size / 2, size / 2);
        func(x + size / 2, y + size / 2, size / 2);
        cout << ")";
    }
    else
    {
        cout << type;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string str;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> str;

        for (int j = 0; j < n; j++)
        {
            board[i][j] = str[j] - 48;
        }
    }

    func(0, 0, n);

    cout << "\n";

    return 0;
}
