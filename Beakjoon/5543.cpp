#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int min1 = 0, min2 = 0;
	int num;
	for (int i = 0; i < 3; i++) {
		cin >> num;

		if (min1 == 0 || min1 > num) {
			min1 = num;
		}
	}
	for (int i = 0; i < 2; i++) {
		cin >> num;

		if (min2 == 0 || min2 > num) {
			min2 = num;
		}
	}

	cout << min1 + min2 - 50 << endl;
	return 0;
}