#include<iostream>
#include<cmath>
using namespace std;


int main() {
	ios::sync_with_stdio(false);

	int t1;
	cin >> t1;

	double x1, y1, x2, y2, r1, r2;
	int counter;
	double l, s;
	double range;

	int* result = new int[t1];
	for (int i = 0; i < t1; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		counter = 0;

		if (x1 == x2 && y1 == y2) {
			if (r1 == r2) {
				counter = -1;
			}
		}
		else {
			range = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));

			l = r1 >= r2 ? r1 : r2;
			s = r1 < r2 ? r1 : r2;

			if (range == l + s || l == range + s) {
				counter = 1;
			}
			else if (range < l + s && l < range + s) {
				counter = 2;
			}
		}

		result[i] = counter;
	}
	for (int i = 0; i < t1; i++) {
		cout << result[i] << endl;
	}
	return 0;
}