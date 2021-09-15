#include<iostream>
using namespace std;

int glist[100001];

int find(int g) {
	if (glist[g] == g) return g;
	return glist[g] = find(glist[g]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int g, p,answer=0,gi;
	bool fin = false;
	cin >> g >> p;

	for (int i = 1; i <= g; i++) {
		glist[i] = i;
	}

	for (int i = 0; i < p; i++) {
		cin >> gi;
		if (!fin) {
			int empty = find(gi);
			if (glist[empty] > 0) {
				answer++;
				glist[empty] = empty - 1;
			}
			else {
				fin = true;
			}
		}
	}
	cout << answer << "\n";

	return 0;
}
