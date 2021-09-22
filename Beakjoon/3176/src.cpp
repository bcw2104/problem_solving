#include<iostream>
#include<queue>
using namespace std;

#define DMAX 21

typedef struct Parent {
	int n=0, minw=0, maxw=0;
}parent;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,m,u,v,w;

	cin >> n;

	queue<int> q;
	vector<int> depth(n + 1);
	vector<vector<parent>> spt(n + 1, vector<parent>(DMAX));
	vector<vector<pair<int,int>>> edges(n + 1);

	for (int i = 0; i < n-1; i++) {
		cin >> u >> v >> w;

		edges[u].push_back({ v,w });
		edges[v].push_back({ u,w });
	}

	q.push(1);

	while (!q.empty()) {
		int cv = q.front();

		q.pop();

		for (int i = 0; i < edges[cv].size(); i++) {
			if (edges[cv][i].first > 1 && depth[edges[cv][i].first] == 0) {
				spt[edges[cv][i].first][0].n = cv;
				spt[edges[cv][i].first][0].maxw = edges[cv][i].second;
				spt[edges[cv][i].first][0].minw = edges[cv][i].second;

				depth[edges[cv][i].first] = depth[cv] + 1;
				q.push(edges[cv][i].first);
			}
		}
	}

	for (int j = 1; j < DMAX; j++) {
		for (int i = 2; i <= n; i++) {
			if (spt[i][j - 1].n != 0) {
				spt[i][j].n = spt[spt[i][j - 1].n][j - 1].n;
				spt[i][j].maxw = max(spt[i][j - 1].maxw,spt[spt[i][j - 1].n][j - 1].maxw);
				spt[i][j].minw = min(spt[i][j - 1].minw, spt[spt[i][j - 1].n][j - 1].minw);
			}
		}
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> u >> v;

		if (depth[u] > depth[v]) swap(u, v);

		int minans = 1000001, maxans = 0;
		int diff = depth[v] - depth[u];

		for (int j = 0; diff > 0; j++) {
			if (diff % 2) {
				minans = min(minans, spt[v][j].minw);
				maxans = max(maxans, spt[v][j].maxw);
				v = spt[v][j].n;
			}
			diff >>= 1;
		}

		if (u != v) {
			for (int j = DMAX - 1; j >= 0; j--) {
				if (spt[u][j].n != spt[v][j].n) {
					minans = min(min(minans, spt[v][j].minw), spt[u][j].minw);
					maxans = max(max(maxans, spt[v][j].maxw), spt[u][j].maxw);
					u = spt[u][j].n;
					v = spt[v][j].n;
				}
			}
			minans = min(min(minans, spt[v][0].minw), spt[u][0].minw);
			maxans = max(max(maxans, spt[v][0].maxw), spt[u][0].maxw);
		}
		cout << minans << " " << maxans << "\n";
	}

	return 0;
}
