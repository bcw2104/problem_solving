#include<iostream>
#include<vector>
using namespace std;

int n, start, sum = 0, answer = 2e9;
bool visit[11] = { 0, };
vector<vector<pair<int,int>>> edge;

void func(int v,int cnt) {
	if (cnt == n) {
		for (int i = 0; i < edge[v].size(); i++) {
			if (edge[v][i].first == start) {
				sum += edge[v][i].second;
				answer = min(answer, sum);

				sum -= edge[v][i].second;
				break;
			}
		}
	}
	else {
		for (int i = 0; i < edge[v].size(); i++) {
			if (visit[edge[v][i].first] == 0) {
				if (sum + edge[v][i].second < answer) {
					visit[edge[v][i].first] = 1;
					sum += edge[v][i].second;
					func(edge[v][i].first, cnt + 1);
					sum -= edge[v][i].second;
					visit[edge[v][i].first] = 0;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int w;
	cin >> n;

	edge.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> w;
			if(w!=0)
				edge[i].push_back({ j,w });
		}
	}

	start = 1;
	visit[start] = 1;
	func(start,1);

	cout << answer << "\n";
	return 0;
}
