#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    string s1, s2;

    cin >> t;

    while (t > 0)
    {
        map<string, int> m;
        map<string, int>::iterator iter;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> s1 >> s2;

            if (m.find(s2) == m.end())
                m[s2] = 1;
            else
                m[s2]++;
        }

        int ans = 1;

        for (iter = m.begin(); iter != m.end(); iter++)
        {
            ans *= ((*iter).second + 1);
        }

        cout << ans - 1 << "\n";

        t--;
    }
    return 0;
}
