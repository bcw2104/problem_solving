#include<iostream>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t,n,a,b;

	cin >> t;

	while (t--) {
		cin >> n;

		vector<int> p1;
		vector<bool> p2(n + 1);
		vector<int> p(n + 1);

		for (int i = 1; i < n; i++) {
			cin >> a >> b;

			p[b] = a;
		}
		cin >> a >> b;

		while (a!=0) {
			p1.push_back(a);
			a = p[a];
		}
		while (b!=0) {
			p2[b] = 1;
			b = p[b];
		}

		for (int i = 0; i < p1.size(); i++) {
			if (p2[p1[i]]) {
				cout << p1[i] << "\n";
				break;
			}
		}
	}

	return 0;
}
