#include <iostream>
#include <cstring>
#include <queue>
#include <set>
using namespace std;

set<int> edge[1001];
int visit[1001];

void dfs(int v)
{
    set<int>::iterator iter;

    cout << v << " ";
    visit[v] = 1;

    for (iter = edge[v].begin(); iter != edge[v].end(); iter++)
    {
        if (visit[*(iter)] == 0)
            dfs(*(iter));
    }
}

void bfs(int v)
{
    queue<int> q;
    set<int>::iterator iter;

    q.push(v);

    while (!q.empty())
    {
        v = q.front();
        q.pop();

        if (visit[v] == 0)
        {
            cout << v << " ";
            visit[v] = 1;
            for (iter = edge[v].begin(); iter != edge[v].end(); iter++)
            {
                if (visit[*(iter)] == 0)
                    q.push(*(iter));
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, v;
    int v1, v2;

    cin >> n >> m >> v;

    for (int i = 0; i < m; i++)
    {
        cin >> v1 >> v2;

        edge[v1].insert(v2);
        edge[v2].insert(v1);
    }

    memset(visit, 0, sizeof(visit));
    dfs(v);

    cout << "\n";
    memset(visit, 0, sizeof(visit));
    bfs(v);

    return 0;
}
