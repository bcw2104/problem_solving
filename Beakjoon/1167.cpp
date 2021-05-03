#include <iostream>
#include <vector>
using namespace std;

int maxval = 0;
int maxnode;
vector<pair<int, int>> tree[100001];
int visit[100001];

void dfs(int current, int dist)
{
    visit[current] = 1;

    if (maxval < dist)
    {
        maxval = dist;
        maxnode = current;
    }

    for (int i = 0; i < tree[current].size(); i++)
    {
        if (visit[tree[current][i].first] == 0)
        {
            dfs(tree[current][i].first, dist + tree[current][i].second);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v, d, n, t;

    cin >> v;

    for (int i = 0; i < v; i++)
    {
        cin >> t;

        while (1)
        {
            cin >> d;

            if (d == -1)
                break;

            cin >> n;
            tree[t].push_back({d, n});
        }
    }

    dfs(1, 0);
    for (int i = 0; i <= 100000; i++)
    {
        visit[i] = 0;
    }
    dfs(maxnode, 0);
    cout << maxval << "\n";

    return 0;
}
