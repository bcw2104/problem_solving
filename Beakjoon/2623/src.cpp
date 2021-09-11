#include<iostream>
#include<queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m,size,a,b;
	int in[1001] = { 0, };
	queue<int> q;
	vector<int> ans;

	cin >> n >> m;  
	
	vector<vector<int>> edges(n+1);

	for (int i = 0; i < m; i++) {
		cin >> size >> a;
		for (int j = 1; j < size; j++) {
			cin >> b;
			edges[a].push_back(b);
			in[b]++;
			a = b;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (in[i] == 0)
			q.push(i);
	}

	int cnt = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		ans.push_back(cur);
		cnt++;
		for (int i = 0; i < edges[cur].size(); i++) {
			int next = edges[cur][i];
			in[next]--;
			if (in[next] == 0)
				q.push(next);
		}
	}

	if (cnt < n)
		cout << 0 << "\n";
	else {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i]<< "\n";
		}
	}

	return 0;
}
