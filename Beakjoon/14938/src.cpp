#include <iostream>
#include <vector>
#include <queue>

#define MAX 2e9
using namespace std;

typedef struct Vertex {
    vector<pair<int, int>> edges;
}vertex;

struct compare
{
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int items[101];
    int dist[101];
    bool visit[101];
    vertex vertexs[101];

    int n, m, r, answer = 0;

    cin >> n >> m >> r;

    for (int i = 1; i <= n; i++) {
        cin >> items[i];
    }

    for (int i = 1; i <= r; i++) {
        int t, f, w;

        cin >> t >> f >> w;
        vertexs[t].edges.push_back({ f,w });
        vertexs[f].edges.push_back({ t,w });
    }

    for (int i = 1; i <= n; i++) {
        int sum = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        for (int j = 1; j <= n; j++) {
            dist[j] = MAX;
            visit[j] = 0;
        }
        dist[i] = 0;

        pq.push({ i,dist[i] });

        while (!pq.empty()) {
            int v = pq.top().first;
            pq.pop();

            if (visit[v] == 1)
                continue;

            if (dist[v] <= m)
                sum += items[v];
            else
                break;

            visit[v] = 1;

            for (int j = 0; j < vertexs[v].edges.size(); j++) {
                int nv = vertexs[v].edges[j].first;
                int nw = vertexs[v].edges[j].second;
                if (visit[nv] == 0) {
                    if (dist[nv] > dist[v] + nw) {
                        dist[nv] = dist[v] + nw;
                        pq.push({ nv,dist[nv] });
                    }
                }
            }
        }

        answer = max(answer, sum);
    }

    cout << answer << "\n";
    return 0;
}
