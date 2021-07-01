#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int k, n, len[10000];
int ans = 0;

bool check(long long key)
{
    long long count = 0;

    for (int i = 0; i < k; i++)
    {
        count += (long long)len[i] / key;
    }

    return count >= n;
}
void find(long long start, long long end)
{
    long long mid = (long long)(start + end) / 2;

    if (start <= end)
    {
        if (check(mid))
        {
            if (ans < mid)
                ans = mid;

            find(mid + 1, end);
        }
        else
        {
            find(start, mid - 1);
        }
    }
}
int main()
{

    cin >> k >> n;

    for (int i = 0; i < k; i++)
    {
        cin >> len[i];
    }

    sort(len, len + k);

    find(1, len[k - 1]);

    cout << ans << "\n";
    return 0;
}
