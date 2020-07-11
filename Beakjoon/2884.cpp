#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int x, y;

	cin >> x >> y;

	int sum = x * 60 + y;

	if (sum < 45) {
		sum += 1395;
	}
	else {
		sum -= 45;
	}

	x = sum / 60;
	y = sum % 60;

	cout << x << " " << y << endl;

	return 0;
}