#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 200000001

typedef struct Vertex {
    vector<pair<int, int>> edges;
}vertex;

struct compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

int dist[801];
int visit[801];
vector<vertex> vlist;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    int ans = MAX;
    int v1, v2;

    cin >> n >> m;

    vlist.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int f, t, w;

        cin >> f >> t >> w;

        vlist[f].edges.push_back({ t,w });
        vlist[t].edges.push_back({ f,w });
    }

    cin >> v1 >> v2;
        
    int cases[2][3] = { {v1,v2,n},{v2,v1,n} };

    for (int i = 0; i < 2; i++) {
        int s = 1;
        int total_dist = 0;
        for (int j = 0; j < 3; j++) {
            int e = cases[i][j];
            priority_queue<pair<int,int>, vector<pair<int, int>>, compare> pq;
            memset(visit, 0, sizeof(visit));

            for (int k = 1; k <= n; k++) {
                dist[k] = MAX;
            }
            dist[s] = 0;

            pq.push({ s,dist[s] });

            while (!pq.empty()) {
                int v = pq.top().first;
                int d = pq.top().second;

                pq.pop();

                if (visit[v] == 1)
                    continue;

                if (v == e) {
                    break;
                }
                visit[v] = 1;

                for (int k = 0; k < vlist[v].edges.size(); k++) {
                    int to = vlist[v].edges[k].first;
                    int tow = vlist[v].edges[k].second;
                    if (visit[to] == 0) {
                        dist[to] = min(d + tow, dist[to]);
                        pq.push({ to,dist[to] });
                    }
                }
            }
            total_dist += dist[e];
            s = e;
        }

        if ( ans > total_dist)
            ans = total_dist;
    }
   
    if (ans >= MAX)
        ans = -1;

    cout << ans << "\n";

    return 0;
}

