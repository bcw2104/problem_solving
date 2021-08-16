// bcw2104 2021-08-17

#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

vector<bool> kpeople;
vector<bool> kparty;
vector<vector<int>> people;
vector<vector<int>> party;

void recursive(int truthParty) {
	if (kparty[truthParty] == 0) {
		kparty[truthParty] = 1;
		for (int i = 0; i < party[truthParty].size(); i++) {
			int p = party[truthParty][i];
			if (kpeople[p] == 0) {
				kpeople[p] = 1;
				for (int j = 0; j < people[p].size(); j++) {
					recursive(people[p][j]);
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ans = 0;
	int n, m, k ,p;

	cin >> n >> m >> k;

	party.resize(m+1);
	people.resize(n+1);
	
	kpeople.resize(n + 1);
	kparty.resize(m + 1);

	for (int i = 0; i < k; i++) {
		cin >> p;
		kpeople[p] = 1;
	}

	for (int i = 1; i <= m; i++) {
		int psize;
		cin >> psize;

		for (int j = 0; j < psize; j++) {
			cin >> p;
			party[i].push_back(p);
			people[p].push_back(i);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (kpeople[i] == 1) {
			for (int j = 0; j < people[i].size(); j++) {
				if (kparty[people[i][j]] == 0) {
					recursive(people[i][j]);
				}
			}
		}
	}

	for (int i = 1; i <= m; i++) {
		if (kparty[i] == 0)
			ans++;
	}

	cout << ans <<  "\n";
   
	return 0;
}

