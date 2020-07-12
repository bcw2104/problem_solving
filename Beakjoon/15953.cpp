#include<iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);

	int t1;
	int a, b;
	cin >> t1;

	int* result = new int[t1];
	int sum;
	int a_arr[6][2] = { {1,500},{3,300},{6,200},{10,50},{15,30},{21,10} };
	int b_arr[5][2] = { {1,512},{3,256},{7,128},{15,64},{31,32} };
	for (int i = 0; i < t1; i++) {
		cin >> a >> b;

		sum = 0;

		if (a > 0 && a <= 21) {
			for (int j = 0; j < 6; j++) {
				if (a <= a_arr[j][0]) {
					sum += a_arr[j][1];
					break;
				}
			}
		}

		if (b > 0 && b <= 31) {
			for (int j = 0; j < 5; j++) {
				if (b <= b_arr[j][0]) {
					sum += b_arr[j][1];
					break;
				}
			}
		}

		result[i] = sum * 10000;

	}
	for (int i = 0; i < t1; i++) {
		cout << result[i] << endl;
	}
	return 0;
}