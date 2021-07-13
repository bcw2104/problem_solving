#include<iostream>
#include<vector>
using namespace std;

#define MAX 2e9

int n, m,ans = MAX;
vector<pair<int, int>> home;
vector<pair<int, int>> store;
vector<pair<int, int>> save;

void func(int cnt,int idx) {
	if (cnt == m) {
		int sum = 0;

		for (int i = 0; i < home.size(); i++) {
			int mdist = MAX;

			for (int j = 0; j < save.size(); j++) {
				int dist = abs(home[i].first - save[j].first) + abs(home[i].second - save[j].second);

				if (mdist > dist) {
					mdist = dist;
				}
			}
			sum += mdist;
		}

		if (ans > sum) {
			ans = sum;
		}
	}
	else {
		for (int i = idx; i < store.size(); i++) {
			save.push_back(store[i]);
			func(cnt + 1, i + 1);
			save.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j=1; j <= n; j++) {
			cin >> t;

			if (t == 1) {
				home.push_back({ i,j });
			}
			else if (t == 2) {
				store.push_back({ i,j });
			}
		}
	}

	func(0,0);

	cout << ans << "\n";
	return 0;
}
