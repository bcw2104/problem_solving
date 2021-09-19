#include<iostream>
#include<vector>
using namespace std;

int spt[200001][19] = { 0, };

vector<int> binary(int n) {
	vector<int> b;

	while (n != 0) {
		b.push_back(n % 2);
		n /= 2;
	}

	return b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m,q,n,x;
	cin >> m;

	vector<int> f(m + 1);

	for (int i = 1; i <= m; i++) {
		cin >> spt[i][0];
	}

	for (int j = 1; j < 19; j++) {
		for(int i=1;i<=m;i++)
			spt[i][j] = spt[spt[i][j - 1]][j - 1];
	}

	cin >> q;

	for (int i = 1; i <= q; i++) {
		cin >> n >> x;

		vector<int> b = binary(n);

		for (int j = 0; j < b.size(); j++) {
			if (b[j] == 1) {
				x = spt[x][j];
			}
		}

		cout << x << "\n";
	}

	return 0;
}
