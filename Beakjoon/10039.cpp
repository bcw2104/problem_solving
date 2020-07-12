#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int num;
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		cin >> num;

		if (num < 40) {
			num = 40;
		}
		sum += num;
	}

	cout << sum / 5 << endl;
	return 0;
}