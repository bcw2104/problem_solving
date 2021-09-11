#include<iostream>
#include<queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m,size,a,b;
	int in[32001] = { 0, };
	queue<int> q;
	vector<int> ans;

	cin >> n >> m;  
	
	vector<vector<int>> edges(n+1);

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		edges[a].push_back(b);
		in[b]++;
	}

	for (int i = 1; i <= n; i++) {
		if (in[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		ans.push_back(cur);
		for (int i = 0; i < edges[cur].size(); i++) {
			int next = edges[cur][i];
			in[next]--;
			if (in[next] == 0)
				q.push(next);
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i]<< " ";
	}
	cout << "\n";
	return 0;
}
