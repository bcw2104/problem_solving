#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAX 3000000000

int n;
int arr[5000];

int binary_search(int start, int end, long long k)
{
    int mid = (start + end) / 2;

    if (start < end)
    {
        if (arr[mid] < k)
        {
            return binary_search(mid + 1, end, k);
        }
        else
        {
            return binary_search(start, mid, k);
        }
    }
    else
    {
        return end;
    }
}

int main()
{

    int ans[3];
    long long sum = 0;
    long long rs = MAX;
    int x, y, z, z_idx;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for (int i = 0; i < n - 1; i++)
    {
        x = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            y = arr[j];
            sum = x + y;

            z_idx = binary_search(0, n - 1, -1 * sum);
            int temp = z_idx;

            while (arr[temp] == x || arr[temp] == y)
            {
                temp++;
            }

            if (temp < n)
            {
                z = arr[temp];
                sum += z;

                if (rs > abs(sum))
                {
                    rs = abs(sum);
                    ans[0] = x;
                    ans[1] = y;
                    ans[2] = z;
                }
            }

            sum -= z;

            if (z_idx > 0)
            {
                temp = z_idx - 1;
                if (temp >= 0 && (arr[temp] != x && arr[temp] != y))
                {
                    z = arr[temp];
                    sum += z;

                    if (rs > abs(sum))
                    {
                        rs = abs(sum);
                        ans[0] = x;
                        ans[1] = y;
                        ans[2] = z;
                    }
                }
            }
            sum = 0;
        }
    }

    sort(ans, ans + 3);

    cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";

    return 0;
}
