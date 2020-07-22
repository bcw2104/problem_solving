#include<iostream>
using namespace std;

void func(int* numbers, int* list, int n, int m, int index) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			cout << list[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = 0; i < n; i++) {
			if (numbers[i] != 0) {
				list[index] = numbers[i];
				numbers[i] = 0;
				func(numbers, list, n, m, index + 1);
				numbers[i] = i + 1;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	int* list;
	int* numbers;
	cin >> n >> m;

	list = new int[m];
	numbers = new int[n];

	for (int i = 0; i < n; i++) {
		numbers[i] = i + 1;
	}

	func(numbers, list, n, m, 0);

	return 0;
}