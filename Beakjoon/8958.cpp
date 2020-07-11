#include<iostream>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int t;
	int count;
	int result;
	string list;

	cin >> t;

	while (t > 0) {
		cin >> list;
		count = 0;
		result = 0;
		for (int i = 0; i < list.size(); i++) {
			if (list[i] == 'O') {
				count++;
				result += count;
			}
			else {
				count = 0;
			}
		}

		cout << result << endl;
		t--;
	}
	return 0;
}