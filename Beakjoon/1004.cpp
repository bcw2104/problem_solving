#include<iostream>
#include<cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int t1, t2;
	double x1, y1, x2, y2;
	int counter;

	double r1, r2;
	double** arr;

	cin >> t1;

	int* result = new int[t1] {0, };

	for (int i = 0; i < t1; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> t2;

		arr = new double* [t2];

		for (int j = 0; j < t2; j++) {
			arr[j] = new double[3];

			cin >> arr[j][0] >> arr[j][1] >> arr[j][2];
		}

		counter = 0;

		for (int j = 0; j < t2; j++) {
			r1 = sqrt(pow(arr[j][0] - x1, 2) + pow(arr[j][1] - y1, 2));
			r2 = sqrt(pow(arr[j][0] - x2, 2) + pow(arr[j][1] - y2, 2));

			if ((r1 > arr[j][2] && r2 < arr[j][2]) || (r1 < arr[j][2] && r2 > arr[j][2])) {
				counter++;
			}
		}

		result[i] = counter;
	}
	for (int i = 0; i < t1; i++) {
		cout << result[i] << endl;
	}
	return 0;
}