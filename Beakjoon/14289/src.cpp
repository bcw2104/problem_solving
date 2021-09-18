#include<iostream>
#include<vector>
using namespace std;

#define MOD 1000000007

typedef long long ll;

int n, m;
vector<vector<ll>> v;

vector<vector<ll>> multiply(vector<vector<ll>> m1, vector<vector<ll>> m2) {
	vector<vector<ll>> nm(n,vector<ll>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				nm[i][j] += (m1[i][k] * m2[k][j]);
				nm[i][j] %= MOD;
			}
		}
	}

	return nm;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a,b,d;

	cin >> n >> m;

	v.resize(n, vector<ll>(n));

	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		v[a-1][b-1] = 1;
		v[b-1][a-1] = 1;
	}
	cin >> d;

	vector<vector<ll>> dp = v;
	vector<vector<ll>> answer(n, vector<ll>(n));
	for (int i = 0; i < n; i++) {
		answer[i][i] = 1;
	}

	while (d) {
		if (d % 2) {
			answer = multiply(answer, dp);
			d--;
		}
		dp = multiply(dp, dp);
		d /= 2;
	}

	cout << answer[0][0] << "\n";

	return 0;
}
