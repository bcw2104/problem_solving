#include<iostream>
using namespace std;

void merge(int** list, int start, int mid, int end) {
	int p1 = start;
	int p2 = mid + 1;
	int index = start;
	int** copy = new int* [end - start + 1];

	for (int i = start; i <= end; i++) {
		copy[i - start] = list[i];
	}

	while (p1 <= mid && p2 <= end) {
		if (copy[p1 - start][0] > copy[p2 - start][0]) {
			list[index] = copy[p2 - start];
			p2++;
		}
		else if (copy[p1 - start][0] < copy[p2 - start][0]) {
			list[index] = copy[p1 - start];
			p1++;
		}
		else {
			if (copy[p1 - start][1] > copy[p2 - start][1]) {
				list[index] = copy[p2 - start];
				p2++;
			}
			else if (copy[p1 - start][1] < copy[p2 - start][1]) {
				list[index] = copy[p1 - start];
				p1++;
			}
		}
		index++;
	}

	for (int i = p1; i <= mid; i++) {
		list[index] = copy[i - start];
		index++;
	}

	free(copy);
}
void mergesort(int** list, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		mergesort(list, start, mid);
		mergesort(list, mid + 1, end);
		merge(list, start, mid, end);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int** list;

	cin >> n;

	list = new int* [n];

	for (int i = 0; i < n; i++) {
		list[i] = new int[2];
		cin >> list[i][0] >> list[i][1];
	}

	mergesort(list, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << list[i][0] << " " << list[i][1] << "\n";
	}

	return 0;
}