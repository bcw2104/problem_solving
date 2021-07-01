#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, m;
    cin >> t;

    while (t > 0)
    {
        deque<pair<int, int>> dq;
        deque<pair<int, int>>::iterator iter;
        deque<pair<int, int>>::iterator max_iter;
        int idx = 0;
        int max = 0;

        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            pair<int, int> d;

            d.first = idx;
            cin >> d.second;
            dq.push_back(d);

            idx++;
        }

        idx = 1;
        while (!dq.empty())
        {

            for (iter = dq.begin(); iter != dq.end(); iter++)
            {
                if (max < (*iter).second)
                {
                    max = (*iter).second;
                    max_iter = iter;
                }
            }

            for (iter = dq.begin(); iter != max_iter; iter++)
            {
                dq.push_back(*(iter));
                dq.pop_front();
            }

            if (dq.front().first == m)
            {
                break;
            }

            dq.pop_front();

            idx++;
            max = 0;
        }

        cout << idx << "\n";
        t--;
    }
    return 0;
}
