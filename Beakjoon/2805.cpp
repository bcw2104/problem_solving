#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, idx, c;
    long long sum, ans;
    int tree[1000001];

    cin >> n >> m;

    tree[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> tree[i];
    }

    sort(tree, tree + n + 1);

    idx = n;
    c = 1;
    sum = 0;
    ans = tree[idx];

    while (1)
    {
        if (idx >= 1 && tree[idx] != tree[idx - 1])
        {
            sum += (long long)(tree[idx] - tree[idx - 1]) * c;
            ans -= tree[idx] - tree[idx - 1];
        }

        if (sum > m)
        {
            ans += (sum - m) / c;
            break;
        }
        else if (sum == m)
        {
            break;
        }

        if (idx > 1)
        {
            idx--;
            c++;
        }
    }

    cout << ans << "\n";

    return 0;
}
