#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, b;
    int h = 0, t = 2100000000;
    int mh = 0;
    int arr[250000];
    int h_arr[257];

    cin >> n >> m >> b;

    memset(arr, 0, sizeof(arr));
    memset(h_arr, 0, sizeof(h_arr));

    for (int i = 0; i < n * m; i++)
    {
        cin >> arr[i];

        h_arr[arr[i]]++;
        if (mh < arr[i])
        {
            mh = arr[i];
        }
    }

    for (int i = 0; i <= mh; i++)
    {
        int p = 0;
        int m = 0;
        int nb = b;

        for (int j = mh - i + 1; j <= mh; j++)
        {
            m += h_arr[j] * (j - (mh - i));
        }

        nb += m;

        for (int j = 0; j < mh - i; j++)
        {
            p += h_arr[j] * (mh - i - j);
        }

        if (t > p + m * 2 && p <= nb)
        {
            t = p + m * 2;
            h = mh - i;
        }
    }

    cout << t << " " << h << "\n";

    return 0;
}
