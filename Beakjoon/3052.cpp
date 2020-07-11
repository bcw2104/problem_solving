#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int n;
	int* count;

	count = new int[42]{ 0, };

	for (int i = 0; i < 10; i++) {
		cin >> n;
		count[n % 42]++;
	}

	n = 0;
	for (int i = 0; i < 42; i++) {
		if (count[i] > 0) {
			n++;
		}
	}
	cout << n << endl;
	return 0;
}