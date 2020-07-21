#include<iostream>
#include<string>
using namespace std;

void bubble_sort(int*, int);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string num;
	int* list;
	int size;

	cin >> num;

	size = num.size();
	list = new int[size] { 0, };

	for (int i = 0; i < size; i++) {
		list[i] = num[i] - 48;
	}
	bubble_sort(list, size);

	//print
	for (int i = 0; i < size; i++) {
		cout << list[i];
	}
	cout << "\n";

	return 0;
}

void bubble_sort(int* list, int size) {
	int idx;
	int temp;

	for (int i = 0; i < size - 1; i++) {
		idx = 0;
		for (int j = 1; j < size - i; j++) {
			if (list[idx] > list[j]) {
				idx = j;
			}
		}
		temp = list[idx];
		list[idx] = list[size - i - 1];
		list[size - i - 1] = temp;
	}
}