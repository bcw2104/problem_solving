#include<iostream>
#include<queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t,n,m;

	cin >> t;

	while (t--) {
		cin >> n;
		
		int a, b;
		bool consist = true;
		vector<int> answer;
		vector<int> in(n + 1),pre(n + 1), preidx(n+1);
		vector<vector<int>> edges(n + 1, vector<int>(n+1));
		queue<int> q;

		for (int i = 1; i <= n; i++) {
			cin >> pre[i];

			in[pre[i]] = i - 1;
			preidx[pre[i]] = i;
			for (int j = 1; j < i; j++) {
				edges[pre[j]][pre[i]] = 1;
			}
		}

		cin >> m;
		for (int i = 1; i <= m; i++) {
			cin >> a >> b;

			int from = preidx[a] > preidx[b] ? a:b;
			int to = preidx[a] > preidx[b] ? b:a ;
			in[from]--;
			in[to]++;

			edges[to][from] = 0;
			edges[from][to] = 1;
		}

		for (int i = 1; i <= n; i++) {
			if (in[pre[i]] == 0) {
				q.push(pre[i]);
			}
		}

		while (!q.empty()) {
			if (q.size() >= 2) {
				cout << "?\n";
				return 0;
			}
			int num = q.front();

			q.pop();

			answer.push_back(num);

			for (int i = 1; i <= n; i++) {
				if (edges[num][i] == 1) {
					edges[num][i] = 0;
					in[i]--;

					if (in[i] == 0) {
						q.push({ i });
					}
				}
			}
		}
		if (answer.size() != n) {
			cout << "IMPOSSIBLE\n";
		}
		else {
			for (int i = 0; i < answer.size(); i++) {
				cout << answer[i] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
