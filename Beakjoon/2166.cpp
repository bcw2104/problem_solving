#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

typedef long long ll;

ll cal(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
    ll rs = x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3;

    return rs;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int pos[10000][2];
    long double size = 0;
    int x, y;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> pos[i][0] >> pos[i][1];
    }

    x = pos[0][0];
    y = pos[0][1];

    for (int i = 2; i < n; i++)
    {
        size += cal(x, y, pos[i - 1][0], pos[i - 1][1], pos[i][0], pos[i][1]);
    }

    cout << fixed << setprecision(1) << abs(size) / 2 << "\n";

    return 0;
}
