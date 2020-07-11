#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int t;
	int temp;
	cin >> t;

	for (int i = 1; i <= 2 * t - 1; i++) {
		temp = i;
		if (temp > t) {
			temp = 2 * t - temp;
		}
		for (int j = 0; j < temp; j++) {
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}