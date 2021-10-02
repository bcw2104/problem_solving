#include<iostream>
#include<queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int>, less<int>> maxq;
	priority_queue<int, vector<int>, greater<int>> minq;

	vector<int> answer;
	int t,n,mid;

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;	

		if (i == 0) mid = n;
		else {
			if (mid <= n) {
				if (maxq.size() == minq.size()) minq.push(n);
				else if (maxq.size() < minq.size()) {
					maxq.push(mid);
					minq.push(n);
					mid = minq.top();
					minq.pop();
				}
			}
			else if (mid > n) {
				if (maxq.size() == minq.size()) {
					minq.push(mid);
					maxq.push(n);
					mid = maxq.top();
					maxq.pop();
				}
				else if (maxq.size() < minq.size()) maxq.push(n);
			}
		}

		answer.push_back(mid);
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}
	return 0;
}
