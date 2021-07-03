#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[10];
    int n, k, ans = 0;

    cin >> n >> k;

    for (int i = n - 1; i >= 0; i--)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (k == 0)
        {
            break;
        }
        else
        {
            int c = k / arr[i];
            if (c > 0)
            {
                k -= arr[i] * c;
                ans += c;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
