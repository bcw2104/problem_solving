#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    string name, pw;

    map<string, string> m;

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> name >> pw;

        m[name] = pw;
    }

    for (int i = 0; i < k; i++)
    {
        cin >> name;

        cout << m[name] << "\n";
    }

    return 0;
}
