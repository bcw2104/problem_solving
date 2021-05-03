#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 30000001

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v, l, x, s, e, w;
    int len;

    vector<int> dist;
    vector<pair<int, int>> con[20001];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    cin >> v >> l;

    cin >> x;

    for (int i = 0; i < l; i++)
    {
        cin >> s >> e >> w;

        con[s].push_back({w, e});
    }

    dist.resize(v + 1);
    for (int i = 1; i <= v; i++)
    {
        dist[i] = INF;
    }

    dist[x] = 0;
    pq.push({0, x});

    while (!pq.empty())
    {
        int cdist = pq.top().first;
        int cnode = pq.top().second;

        pq.pop();

        if (dist[cnode] < cdist)
            continue;

        for (int i = 0; i < con[cnode].size(); i++)
        {
            int nnode = con[cnode][i].second;
            int ndist = cdist + con[cnode][i].first;

            if (dist[nnode] > ndist)
            {
                dist[nnode] = ndist;
                pq.push({ndist, nnode});
            }
        }
    }

    for (int i = 1; i < dist.size(); i++)
    {
        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }

    return 0;
}
