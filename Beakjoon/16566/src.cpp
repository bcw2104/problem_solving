#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> cards, parent;

int find(int n) {
	if (parent[n] == n) return n;
	return parent[n] = find(parent[n]);
}

void _union(int n1, int n2) {
	int p1 = find(n1);
	int p2 = find(n2);

	if (p1 != p2)
		parent[p1] = p2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k,card;

	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		cin >> card;
		cards.push_back(card);
		parent.push_back(i);
	}
	sort(cards.begin(), cards.end());

	for (int i = 0; i < k; i++) {
		cin >> card;
		int p = find(upper_bound(cards.begin(), cards.end(), card)-cards.begin());
		cout << cards[p] << "\n";
		if(p+1<m)
			_union(p, p + 1);
	}
	return 0;
}
