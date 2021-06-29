#include <iostream>
#include <set>
#include <cmath>
using namespace std;

#define MAX 2147483647

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, p, pre = MAX;
    pair<int, int> ans;
    multiset<int> s;
    multiset<int>::iterator iter, target;
    int x, y;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> p;
        s.insert(p);
    }

    iter = s.begin();

    for (int i = 0; i < n; i++)
    {
        x = *(iter);
        target = s.lower_bound(-1 * x);
        if (target == s.end())
        {
            target--;
            y = *(target);

            if (x == y)
            {
                y = *(--target);
            }
        }
        else
        {
            y = *(target);

            if (target != s.begin())
            {
                int t1, t2;

                t1 = *(target);
                t2 = *(--target);
                ++target;
                if (t1 == x)
                {
                    t1 = *(++target);
                }
                if (t2 != x)
                    y = abs(x + t1) < abs(x + t2) ? t1 : t2;
                else
                    y = t1;
            }
            else
            {
                if (x == y)
                    y = *(++target);
            }
        }

        if (abs(x + y) < pre)
        {
            ans.first = min(x, y);
            ans.second = max(x, y);
            pre = abs(x + y);
        }

        iter++;
    }

    cout << ans.first << " " << ans.second << "\n";

    return 0;
}
