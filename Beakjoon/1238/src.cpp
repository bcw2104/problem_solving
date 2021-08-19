#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 2e9

typedef struct Vertex {
    vector<pair<int, int>> edges;
}vertex;

struct compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

int ans[1001] = { 0, };
int dist[1001] = { 0, };
int visit[1001];
vector<vertex> vlist;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;

    cin >> n >> m >> k;

    vlist.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int f, t, w;

        cin >> f >> t >> w;

        vlist[f].edges.push_back({ t,w });
    }

    for (int i = 1; i <= n; i++) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

        for (int j = 0; j <= n; j++) {
            dist[j] = MAX;
        }
        dist[i] = 0;

        memset(visit, 0, sizeof(visit));

        pq.push( {i,dist[i]} );

        while (!pq.empty()) {
            int v = pq.top().first;
            int d = pq.top().second;

            pq.pop();

            if (visit[v] == 1)
                continue;

            visit[v] = 1;

            if (v == k) {
                ans[i] += dist[k];
                break;
            }

            for (int j = 0; j < vlist[v].edges.size(); j++) {
                int to = vlist[v].edges[j].first;
                int tow = vlist[v].edges[j].second;

                if (visit[to] == 0) {
                    if (dist[to] > dist[v] + tow) {
                        dist[to] = dist[v] + tow;
                        pq.push({ to,dist[to] });
                    }
                }
            }
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

    for (int i = 0; i <= n; i++) {
        dist[i] = MAX;
    }
    dist[k] = 0;

    memset(visit, 0, sizeof(visit));

    pq.push({ k,dist[k] });

    while (!pq.empty()) {
        int v = pq.top().first;
        int d = pq.top().second;
        pq.pop();

        if (visit[v] == 1)
            continue;

        visit[v] = 1;

        for (int j = 0; j < vlist[v].edges.size(); j++) {
            int to = vlist[v].edges[j].first;
            int tow = vlist[v].edges[j].second;
            if (visit[to] == 0) {
                if (dist[to] > dist[v] + tow) {
                    dist[to] = dist[v] + tow;
                    pq.push({ to,dist[to] });
                }
            }
        }
    }
    int rs = 0;

    for (int i = 1; i <= n; i++) {
        ans[i] += dist[i];
        if (ans[i] > rs) {
            rs = ans[i];
        }
    }

    cout << rs << "\n";

    return 0;
}
