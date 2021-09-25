#include<iostream>
#include<vector>
using namespace std;

int n,ans = 0;
vector<vector<pair<int,int>>> able;
vector<bool> check;

int func(int line) {
	if (line >= able.size()) return 0;

	int ret = 0;
	for (int i = 0; i < able[line].size(); i++) {
		int y = able[line][i].first;
		int x = able[line][i].second;

		if (!check[n + y - x - 1]) {
			check[n + y - x - 1] = true;
			ret = max(ret,func(line + 2)+1);
			check[n + y - x - 1] = false;
		}
	}

	ret = max(ret, func(line + 2));

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	able.resize(2 * n-1);
	check.resize(2 * n-1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int ele;
			cin >> ele;

			if (ele) able[i + j].push_back({ i,j });
		}
	}

	ans = func(0) + func(1);

	cout << ans << "\n";

	return 0;
}
