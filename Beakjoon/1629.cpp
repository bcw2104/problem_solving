#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c;
    unsigned long long m = 1;
    unsigned long long res = 1;

    map<int, unsigned long long> mem;

    cin >> a >> b >> c;

    res = a % c;
    mem.insert(make_pair(0, 1));
    mem.insert(make_pair(1, a));

    while (1)
    {
        if (b >= 2 * m)
        {
            res *= res;
            res %= c;
            m += m;
            mem.insert(make_pair(m, res));
        }
        else
        {
            break;
        }
    }

    b = b - m;
    while (1)
    {
        if (b >= m / 2)
        {
            res *= mem[m / 2];
            res %= c;
            b -= m / 2;

            if (b == 0)
            {
                break;
            }
        }
        else
        {
            m /= 2;
        }
    }

    cout << res << "\n";

    return 0;
}
