#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int t;
	int* list;
	int max, min;
	cin >> t;

	list = new int[t];
	for (int i = 0; i < t; i++) {
		cin >> list[i];
	}
	max = list[0];
	min = list[0];
	for (int i = 1; i < t; i++) {
		if (list[i] > max) {
			max = list[i];
		}
		if (list[i] < min) {
			min = list[i];
		}
	}

	cout << min << " " << max << endl;
	return 0;
}