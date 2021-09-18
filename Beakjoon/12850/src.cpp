#include<iostream>
#include<vector>
using namespace std;

#define MOD 1000000007

typedef long long ll;

vector<vector<ll>> v = {
	{0,1,1,0,0,0,0,0},
	{1,0,1,1,0,0,0,0},
	{1,1,0,1,1,0,0,0},
	{0,1,1,0,1,1,0,0},
	{0,0,1,1,0,1,1,0},
	{0,0,0,1,1,0,0,1},
	{0,0,0,0,1,0,0,1},
	{0,0,0,0,0,1,1,0}
};
vector<vector<ll>> multiply(vector<vector<ll>> m1, vector<vector<ll>> m2) {
	vector<vector<ll>> nm(8,vector<ll>(8));

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			for (int k = 0; k < 8; k++) {
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

	int n;

	cin >> n;

	vector<vector<ll>> dp = v;
	vector<vector<ll>> answer(8, vector<ll>(8));
	for (int i = 0; i < 8; i++) {
		answer[i][i] = 1;
	}

	while (n) {
		if (n % 2) {
			answer = multiply(answer, dp);
			n--;
		}
		dp = multiply(dp, dp);
		n /= 2;
	}

	cout << answer[0][0] << "\n";

	return 0;
}
