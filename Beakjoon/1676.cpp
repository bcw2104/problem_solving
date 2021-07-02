#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int cnt2 = 0, cnt5 = 0;

    cin >> n;

    for (int i = 2; i <= n; i++)
    {
        int t = i;
        while (t % 2 == 0 || t % 5 == 0)
        {
            if (t % 2 == 0)
            {
                cnt2++;
                t /= 2;
            }
            else if (t % 5 == 0)
            {
                cnt5++;
                t /= 5;
            }
        }
    }

    int ans = min(cnt2, cnt5);

    cout << ans << "\n";

    return 0;
}
