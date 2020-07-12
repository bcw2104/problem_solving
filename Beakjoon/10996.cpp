#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int t;
	int temp;
	cin >> t;

	for (int i = 0; i < t; i++) {
		for (int j = 0; j < t % 2 + t / 2; j++) {
			cout << "* ";
		}
		cout << endl;
		for (int j = 0; j < t / 2; j++) {
			cout << " *";
		}
		cout << endl;
	}
	return 0;
}