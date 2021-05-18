#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b;
    int p_arr[100001];
    vector<int> v[100001];
    queue<pair<int, int>> q;

    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 0; i < v[1].size(); i++)
    {
        q.push(make_pair(1, v[1][i]));
    }

    while (!q.empty())
    {
        int parent = q.front().first;
        int child = q.front().second;
        q.pop();

        p_arr[child] = parent;

        for (int i = 0; i < v[child].size(); i++)
        {
            if (p_arr[v[child][i]] == 0)
            {
                q.push(make_pair(child, v[child][i]));
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        cout << p_arr[i] << "\n";
    }

    return 0;
}
