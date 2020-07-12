#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int t, temp;
	int arr[3] = { 0, };
	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 2; i++) {
		temp = 0;
		for (int j = 1; j < 3 - i; j++) {
			if (arr[temp] < arr[j]) {
				temp = j;
			}
		}
		t = arr[temp];
		arr[temp] = arr[3 - i - 1];
		arr[3 - i - 1] = t;
	}

	cout << arr[1] << endl;
	return 0;
}