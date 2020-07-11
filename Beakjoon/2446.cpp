#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int t;
	int temp;
	cin >> t;

	for (int i = 0; i < 2 * t - 1; i++) {
		if (i > t - 1) {
			for (int j = 0; j < t - 1 - (i - t + 1); j++) {
				cout << " ";
			}
			temp = 1 + 2 * (i - t + 1);
		}
		else {
			for (int j = 0; j < i; j++) {
				cout << " ";
			}
			temp = 1 + (t - 1) * 2 - 2 * i;
		}
		for (int j = 0; j < temp; j++) {
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}