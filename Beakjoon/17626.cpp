#include <iostream>
#include <cmath>
using namespace std;

int ans = 50001;

void dfs(int k, int cnt)
{
    int s = (int)sqrt(k);

    for (int i = s; i > 0; i--)
    {
        k -= pow(i, 2);
        if (k > 0 && ans > cnt + 1)
        {
            dfs(k, cnt + 1);
        }
        else if (k == 0)
        {

            if (ans > cnt)
            {
                ans = cnt;
            }
        }
        k += pow(i, 2);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int n;

    cin >> n;

    dfs(n, 1);

    cout << ans << "\n";
    return 0;
}
