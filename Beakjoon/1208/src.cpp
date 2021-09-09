#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> arr;
vector<int> sums[2];

void func(int part,int idx,int end,int sum) {
	if (idx < end) {
		func(part, idx + 1, end, sum);
		sum += arr[idx];
		sums[part].push_back(sum);
		func(part, idx + 1, end, sum);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, s;
    long long answer=0;
	cin >> n >> s;

	arr.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	func(0, 0, n / 2,0);
	func(1, n/2, n,0);

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < sums[i].size(); j++) {
			if (sums[i][j] == s)
				answer++;
		}
	}

	sort(sums[1].begin(), sums[1].end());

	for (int i = 0; i < sums[0].size(); i++) {
		int sum = sums[0][i];
		answer += upper_bound(sums[1].begin(), sums[1].end(), s - sum) - lower_bound(sums[1].begin(), sums[1].end(), s - sum);
	}

	cout << answer << "\n";

	return 0;
}
