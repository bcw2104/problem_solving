#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int row[9][10];
int col[9][10];
int squ[9][10];
int board[9][9];
bool fail = false;

void dfs()
{
    int i, j;
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            if (board[i][j] == 0)
            {
                break;
            }
        }
        if (j < 9)
            break;
    }

    if (i < 9 && j < 9)
    {
        for (int k = 1; k < 10; k++)
        {
            if (row[j][k] == 0 && col[i][k] == 0 && squ[3 * (i / 3) + (j / 3)][k] == 0)
            {
                board[i][j] = k;
                row[j][k] = 1;
                col[i][k] = 1;
                squ[3 * (i / 3) + (j / 3)][k] = 1;

                dfs();

                if (fail)
                {
                    fail = false;
                    board[i][j] = 0;
                    row[j][k] = 0;
                    col[i][k] = 0;
                    squ[3 * (i / 3) + (j / 3)][k] = 0;
                }
                else
                {
                    break;
                }
            }
        }

        if (board[i][j] == 0)
        {
            fail = true;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string list;
    int num;

    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    memset(squ, 0, sizeof(squ));

    for (int i = 0; i < 9; i++)
    {
        cin >> list;
        for (int j = 0; j < 9; j++)
        {
            num = list[j] - 48;

            if (num != 0)
            {
                row[j][num] = 1;
                col[i][num] = 1;
                squ[3 * (i / 3) + (j / 3)][num] = 1;
            }

            board[i][j] = num;
        }
    }
    dfs();

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j];
        }
        cout << "\n";
    }

    return 0;
}
