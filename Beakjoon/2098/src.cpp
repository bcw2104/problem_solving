#include<iostream>
using namespace std;

#define INF 16000001
#define MAX 17

int n;
int dp[1 << MAX][MAX] = { 0, };
int edges[MAX][MAX] = { 0, };

int TSP(int visit, int cur) {
	if (visit == (1 << n) - 1)
		return edges[cur][1];

	int &ret = dp[visit][cur];

	if (ret != 0) return ret;

	ret = INF;

	for (int i = 1; i <= n; i++) {
		if (visit & (1<<(i-1)) || edges[cur][i] == INF)
			continue;

		ret = min(ret, edges[cur][i] + TSP(visit | (1 << (i-1)), i));
	}

	return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int w;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> w;
			if (w == 0) w = INF;

			edges[i][j] = w;
		}
	}

	cout << TSP(1, 1) << "\n";
  return 0;
}
