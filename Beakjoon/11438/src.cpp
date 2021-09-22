#include<iostream>
#include<queue>
using namespace std;

#define DMAX 21

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,m,a,b;

	cin >> n;

	queue<int> q;
	vector<int> depth(n + 1);
	vector<vector<int>> spt(n + 1, vector<int>(DMAX));
	vector<vector<int>> edges(n + 1);

	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;

		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	q.push(1);

	while (!q.empty()) {
		int v = q.front();

		q.pop();

		for (int i = 0; i < edges[v].size(); i++) {
			if (edges[v][i] > 1 && depth[edges[v][i]] == 0) {
				spt[edges[v][i]][0] = v;
				depth[edges[v][i]] = depth[v] + 1;
				q.push(edges[v][i]);
			}
		}
	}

	for (int j = 1; j < DMAX; j++) {
		for (int i = 2; i <= n; i++) {
			if (spt[i][j - 1] != 0)
				spt[i][j] = spt[spt[i][j - 1]][j - 1];
		}
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		if (depth[a] > depth[b]) swap(a, b);


		int diff = depth[b] - depth[a];

		for (int j = 0; diff > 0; j++) {
			if (diff%2)
				b = spt[b][j];

			diff >>= 1;
		}

		if (a == b) {
			cout << b << "\n";
		}
		else {
			for (int j = DMAX - 1; j >= 0; j--) {
				if (spt[a][j] != spt[b][j]) {
					a = spt[a][j];
					b = spt[b][j];
				}
			}
			cout << spt[b][0] << "\n";
		}
	}

	return 0;
}
