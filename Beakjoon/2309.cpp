#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int* arr = new int[9];
	int sum;
	int counter = 0;

	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		counter += arr[i];
	}

	for (int i = 0; i < 8; i++) {
		sum = arr[i];
		for (int j = i + 1; j < 9; j++) {
			sum += arr[j];

			if (counter - sum == 100) {
				arr[i] = 0;
				arr[j] = 0;

				i = 8;
				break;
			}
			sum = arr[i];
		}
	}

	int end = 8;
	int temp = 0;

	while (end > 0) {
		for (int i = 0; i < end; i++) {
			if (arr[i] > arr[i + 1]) {
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
		end--;
	}

	for (int i = 2; i < 9; i++) {
		cout << arr[i] << endl;
	}

	return 0;
}