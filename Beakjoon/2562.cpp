#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int* list;
	int max, idx;

	list = new int[9];
	for (int i = 0; i < 9; i++) {
		cin >> list[i];
	}
	idx = 0;
	max = list[0];
	for (int i = 1; i < 9; i++) {
		if (list[i] > max) {
			max = list[i];
			idx = i;
		}
	}

	cout << max << "\n" << idx + 1 << endl;
	return 0;
}