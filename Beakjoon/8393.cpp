#include<iostream>
using namespace std;

int main() {
	int t;
	cin >> t;

	int count = 0;

	for (int i = 1; i <= t; i++) {
		count += i;
	}

	cout << count << endl;
	return 0;
}