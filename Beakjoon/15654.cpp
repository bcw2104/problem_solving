#include <iostream>
#include <algorithm>
using namespace std;

int visit[10001];
int temp[8];
int num[8];
int n, m;

void recursive(int level, int pre)
{
    if (level == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << temp[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (visit[num[i]] == 0)
            {
                visit[num[i]] = 1;
                temp[level] = num[i];
                recursive(level + 1, i + 1);
                visit[num[i]] = 0;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    sort(num, num + n);

    recursive(0, 0);
    return 0;
}
