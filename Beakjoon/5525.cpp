#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    bool flag = true;
    int mem[1000001];
    int cnt = 0;
    string str;

    cin >> n >> m;

    cin >> str;

    memset(mem, 0, sizeof(mem));

    for (int i = 0; i < m; i++)
    {

        if (str[i] == 'I' && flag)
        {
            flag = false;
            cnt++;
        }
        else if (str[i] == 'O' && !flag)
        {
            flag = true;
            cnt++;
        }
        else
        {
            if (cnt >= 3 && cnt % 2 == 0)
            {
                cnt--;
            }
            if (cnt >= 3)
                mem[cnt]++;

            cnt = 0;
            flag = true;

            if (str[i] == 'I' && flag)
            {
                flag = false;
                cnt++;
            }
        }
    }

    if (cnt >= 3)
    {
        if (cnt % 2 == 0)
            cnt--;

        mem[cnt]++;
    }

    cnt = 0;

    for (int i = 2 * n + 1; i <= m; i += 2)
    {
        if (mem[i] > 0)
        {
            cnt += ((i - (2 * n + 1)) / 2 + 1) * mem[i];
        }
    }

    cout << cnt << "\n";

    return 0;
}
