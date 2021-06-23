#include <iostream>
#include <cmath>
using namespace std;

int t, n;
double result, sx, sy;
int pos[20][2];

void dfs(int idx, int p, int m)
{
    if (idx == n)
    {
        if (result == -1 || result > sqrt(sx * sx + sy * sy))
            result = sqrt(sx * sx + sy * sy);
    }
    else
    {
        if (p < n / 2)
        {
            sx += pos[idx][0];
            sy += pos[idx][1];
            dfs(idx + 1, p + 1, m);
            sx -= pos[idx][0];
            sy -= pos[idx][1];
        }
        if (m < n / 2)
        {
            sx -= pos[idx][0];
            sy -= pos[idx][1];
            dfs(idx + 1, p, m + 1);
            sx += pos[idx][0];
            sy += pos[idx][1];
        }
    }
}

int main()
{
    cin >> t;

    while (t > 0)
    {
        cin >> n;

        sx = 0;
        sy = 0;
        result = -1;

        for (int i = 0; i < n; i++)
            cin >> pos[i][0] >> pos[i][1];

        dfs(0, 0, 0);

        printf("%0.6lf\n", result);
        t--;
    }
    return 0;
}
