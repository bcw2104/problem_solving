#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,num,sum = 0;
	stack<int> s;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;

		if (!s.empty() && num == 0) {
			s.pop();
		}
		else {
			s.push(num);
		}
	}

	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}

	cout << sum << "\n";

	return 0;
}
