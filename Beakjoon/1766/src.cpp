#include<iostream>
#include<queue>
using namespace std;

int in[32001] = { 0, };
vector<int> edges[32001];

struct compare {
	bool operator()(int a,int b) {
		return a > b;
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,m,a,b;
	vector<int> answer;
	priority_queue<int, vector<int>, compare> pq;
	cin >> n >> m;

	for (int i=0; i < m; i++) {
		cin >> a >> b;

		in[b]++;
		edges[a].push_back(b);
	}

	for (int i = 1; i <= n; i++) {
		if (in[i] == 0)
			pq.push(i);
	}

	while (!pq.empty()) {
		int v = pq.top();
		pq.pop();
		answer.push_back(v);
		for (int i = 0; i < edges[v].size(); i++) {
			in[edges[v][i]]--;
			if (in[edges[v][i]] == 0)
				pq.push(edges[v][i]);
		}
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	cout << "\n";
	return 0;
}
