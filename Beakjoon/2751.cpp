//MergeSort

#include<iostream>
using namespace std;

void merge(int* list, int* space, int start, int mid, int end) {
	int p1 = start;
	int p2 = mid + 1;
	int index = start;

	for (int i = start; i <= end; i++) {
		space[i] = list[i];
	}

	while (p1 <= mid && p2 <= end) {
		if (space[p1] > space[p2]) {
			list[index] = space[p2];
			p2++;
		}
		else {
			list[index] = space[p1];
			p1++;
		}
		index++;
	}

	for (int i = p1; i <= mid; i++) {
		list[index] = space[i];
		index++;
	}
}

void mergesort(int* list, int* space, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		mergesort(list, space, start, mid);
		mergesort(list, space, mid + 1, end);
		merge(list, space, start, mid, end);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int* list;
	int* space;

	cin >> n;

	list = new int[n] {0, };
	space = new int[n] {0, };

	for (int i = 0; i < n; i++) {
		cin >> list[i];
	}

	mergesort(list, space, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << list[i] << "\n";
	}

	return 0;
}