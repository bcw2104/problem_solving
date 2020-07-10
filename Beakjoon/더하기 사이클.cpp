#include<iostream>
using namespace std;

int main() {

	int a;
	int t1;
	int t2;
	int count;

	cin >> a;
	count = 0;

	t1 = a;
	while (true) {
		count++;
		if (t1 < 10) {
			t2 = t1 * 10 + t1;
		}
		else {
			t2 = t1 % 10 * 10 + (t1 / 10 + t1 % 10) % 10;
		}
		if (t2 == a) {
			break;
		}
		t1 = t2;
	}

	cout << count << endl;
	return 0;
}