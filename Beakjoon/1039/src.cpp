#include<iostream>
#include<string>
#include<vector>
using namespace std;

int ans = 0;
void func(vector<int> v, int k, int i) {
	int sz = v.size();
	int temp;

	if (k == 0 || i == sz-1) {
		if (k > 0 && k % 2 == 1) {
			temp = v[sz - 1];
			v[sz - 1] = v[sz - 2];
			v[sz - 2] = temp;
		}

		int ret = 0;
		int pos = 1;
		for (int i = sz-1; i >= 0; i--) {
			ret += v[i] * pos;
			pos *= 10;
		}

		ans = max(ans,ret);
	}
	else {
		int m = v[i];
		for (int j = i + 1; j < sz; j++) {
			if (m <= v[j]) {
				m = v[j];
			}
		}
		for (int j = i + 1; j < sz; j++) {
			if (m == v[j]) {
				temp = v[i];
				v[i] = v[j];
				v[j] = temp;
				func(v, k - 1, i + 1);
				temp = v[i];
				v[i] = v[j];
				v[j] = temp;
			}
		}
		func(v, k, i + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string n;
	int k,sz;
	vector<int> v;

	cin >> n >> k;

	sz = n.length();
	v.resize(sz);

	for (int i = 0; i < sz; i++) {
		v[i] = n[i] - '0';
	}

	if (sz == 1 || (sz == 2 && v[sz - 1] == 0)) {
		cout << "-1\n";
		return 0;
	}

	func(v, k, 0);

	cout << ans << "\n";

	return 0;
}
