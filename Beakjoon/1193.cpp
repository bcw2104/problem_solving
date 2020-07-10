#include<iostream>
using namespace std;

int main(void)
{
	int n;
	int idx = 1;
	int add = 1;
	int x, y;

	cin >> n;

	while (true) {
		if (n < add) {
			idx--;
			add -= idx;
			break;
		}
		else {
			add = add + idx;
			idx++;
		}
	}
	if (idx % 2 == 0) {
		y = idx - (n - add);
		x = 1 + n - add;
	}
	else {
		x = idx - (n - add);
		y = 1 + n - add;
	}

	cout << x << "/" << y << endl;
	return 0;
}