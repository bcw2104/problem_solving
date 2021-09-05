#include<iostream>

using namespace std;

int sets[500000];

int find(int n) {
	if (n == sets[n]) return n;
	return sets[n] = find(sets[n]);
}
bool group(int n1, int n2) {
	int g1 = find(n1);
	int g2 = find(n2);

	if (g1 == g2)
		return 0;

	sets[g1] = g2;
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, answer = 0;
	int n1, n2;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		sets[i] = i;
	}

	for (int i = 1; i <= m; i++) {
		cin >> n1 >> n2;

		if (!group(n1, n2)) {
			answer = i;
			break;
		}
	}

	cout << answer << "\n";

	return 0;
}
