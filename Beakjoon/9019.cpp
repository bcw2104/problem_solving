#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int D(int n)
{
    return (n * 2) % 10000;
}

int S(int n)
{
    return (n == 0 ? 9999 : n - 1);
}

int L(int n)
{
    int front = n / 1000;
    n %= 1000;
    n *= 10;
    n += front;

    return n;
}

int R(int n)
{
    int rear = n % 10;
    n /= 10;
    n += rear * 1000;

    return n;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, m;

    cin >> t;

    while (t--)
    {
        queue<pair<int, string>> q;
        bool visit[10000];

        cin >> n >> m;

        memset(visit, 0, sizeof(visit));

        q.push(make_pair(n, ""));
        visit[n] = 1;

        while (!q.empty())
        {
            int k = q.front().first;
            string ans = q.front().second;

            if (k == m)
            {
                cout << ans << "\n";
                break;
            }
            q.pop();

            int d = D(k);
            int s = S(k);
            int l = L(k);
            int r = R(k);

            if (!visit[d])
            {
                string copy = ans;
                q.push(make_pair(d, copy += 'D'));
                visit[d] = 1;
            }
            if (!visit[s])
            {
                string copy = ans;
                q.push(make_pair(s, copy += 'S'));
                visit[s] = 1;
            }
            if (!visit[l])
            {
                string copy = ans;
                q.push(make_pair(l, copy += 'L'));
                visit[l] = 1;
            }
            if (!visit[r])
            {
                string copy = ans;
                q.push(make_pair(r, copy += 'R'));
                visit[r] = 1;
            }
        }
    }

    return 0;
}
