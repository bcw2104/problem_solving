#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 2e9;

typedef struct EDGE
{
    int to;
    int w;
} edge;

typedef struct VERTEX
{
    int x;
    vector<edge> edges;
} vertex;

struct compare
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vertex v[1001];
    bool visit[1001];
    int dist[1001];

    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

    int n, m, from, to, w;
    int ans = 0;

    for (int i = 1; i < 1001; i++)
    {
        dist[i] = MAX;
    }

    memset(visit, 0, sizeof(visit));

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> from >> to >> w;
        v[from].edges.push_back({to, w});
    }

    cin >> from >> to;

    dist[from] = 0;

    pq.push(make_pair(from, dist[from]));

    while (!pq.empty())
    {
        int cur_v = pq.top().first;
        int cur_w = pq.top().second;

        pq.pop();

        if (visit[cur_v] == 1)
            continue;

        visit[cur_v] = 1;
        if (cur_v == to)
        {
            ans = cur_w;
            break;
        }

        for (int i = 0; i < v[cur_v].edges.size(); i++)
        {
            int next_v = v[cur_v].edges[i].to;
            int next_w = v[cur_v].edges[i].w;

            if (visit[next_v] == 0)
            {
                dist[next_v] = min(dist[next_v], cur_w + next_w);
                pq.push(make_pair(next_v, dist[next_v]));
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
