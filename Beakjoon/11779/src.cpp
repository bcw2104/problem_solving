#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 100000001

typedef struct Vertex {
    vector<pair<int, int>> edges;
}vertex;

struct compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

int dist[1001];
int visit[1001];
int pre[1001];
vector<int> path;
vector<vertex> vlist;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    int ans = 0;
    int start,end;

    cin >> n >> m;

    vlist.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int f, t, w;

        cin >> f >> t >> w;

        vlist[f].edges.push_back({ t,w });
    }

    cin >> start >> end;
        
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    memset(visit, 0, sizeof(visit));
    
    for (int i = 1; i <= n; i++) {
        dist[i] = MAX;
        pre[i] = i;
    }
    dist[start] = 0;

    pq.push({ start,dist[start] });

    while (!pq.empty()) {
        int v = pq.top().first;

        pq.pop();

        if (visit[v] == 1)
            continue;

        if (v == end) {
            break;
        }
        visit[v] = 1;

        for (int k = 0; k < vlist[v].edges.size(); k++) {
            int to = vlist[v].edges[k].first;
            int tow = vlist[v].edges[k].second;
            if (visit[to] == 0) {
                if (dist[v] + tow < dist[to])
                    pre[to] = v;

                dist[to] = min(dist[v] + tow, dist[to]);
                pq.push({ to,dist[to] });
            }
        }
    }
   
    ans = dist[end];

    int cnt = 1;
    int cur = end;

    while (pre[cur] != cur) {
        path.push_back(cur);
        cur = pre[cur];
        cnt++;
    }
    path.push_back(cur);


    cout << ans << "\n";
    cout << cnt << "\n";

    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << " ";
    }
    cout << "\n";

    return 0;
}
