#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long a, b;
    int ans = -1;

    queue<pair<long long, int>> q;

    cin >> a >> b;

    q.push(make_pair(a, 1));
    while (!q.empty())
    {
        long long n = q.front().first;
        int cnt = q.front().second;

        q.pop();

        if (n == b)
        {
            ans = cnt;
            break;
        }
        else
        {
            if (n * 2 <= b)
            {
                q.push(make_pair(n * 2, cnt + 1));
            }
            if (n * 10 + 1 <= b)
            {
                q.push(make_pair(n * 10 + 1, cnt + 1));
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
