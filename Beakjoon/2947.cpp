#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int p;
	int temp;
	int* arr;

	arr = new int[5];

	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}
	p = 4;
	while (p > 0) {
		for (int i = 0; i < p; i++) {
			if (arr[i] > arr[i + 1]) {
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;

				for (int i = 0; i < 5; i++) {
					cout << arr[i] << " ";
				}
				cout << endl;
			}
		}
		p--;
	}

	return 0;
}