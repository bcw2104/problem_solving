#include<iostream>
#include<vector>
using namespace std;

#define INF 1e9

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc, n, m, w;
	int s, e, t;

	cin >> tc;

	while (tc > 0) {
		cin >> n >> m >> w;

		int cycle = 0;
		vector<vector<pair<int, int>>> line;
		vector<int> dist;

		line.resize(n + 1);
		dist.resize(n + 1);

		for (int i = 0; i < m; i++) {
			cin >> s >> e >> t;

			line[s].push_back({ t,e });
			line[e].push_back({ t,s });
		}
		for (int i = 0; i < w; i++) {
			cin >> s >> e >> t;
			line[s].push_back({ -t,e });
		}

		for (int i = 1; i <= n; i++) {
			dist[i] = INF;
		}
		
		dist[1] = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 0; k < line[j].size(); k++) {
					int cost = line[j][k].first;
					int next = line[j][k].second;

					if (dist[next] > cost + dist[j]) {
						if (i == n) {
							cycle = 1;
						}
						dist[next] = cost + dist[j];
					}
				}
			}
		}

		if (cycle == 1) cout << "YES\n";
		else cout << "NO\n";
		tc--;
	}

	return 0;
}
