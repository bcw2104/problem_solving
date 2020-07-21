#include<iostream>
#include<string>
using namespace std;

void merge(string* list, int start, int mid, int end) {
	int p1 = start;
	int p2 = mid + 1;
	int index = start;
	string* copy = new string[end - start + 1];

	for (int i = start; i <= end; i++) {
		copy[i - start] = list[i];
	}

	while (p1 <= mid && p2 <= end) {
		if (copy[p1 - start].size() > copy[p2 - start].size()) {
			list[index] = copy[p2 - start];
			p2++;
		}
		else if (copy[p1 - start].size() < copy[p2 - start].size()) {
			list[index] = copy[p1 - start];
			p1++;
		}
		else {
			int i;
			for (i = 0; i < copy[p1 - start].size(); i++) {
				if (copy[p1 - start][i] > copy[p2 - start][i]) {
					list[index] = copy[p2 - start];
					p2++;
					i = -1;
					break;
				}
				else if (copy[p1 - start][i] < copy[p2 - start][i]) {
					list[index] = copy[p1 - start];
					p1++;
					i = -1;
					break;
				}
			}
			if (i != -1) {
				list[index] = copy[p1 - start];
				p1++;
				index++;
				list[index] = "";
				p2++;
			}
		}
		index++;
	}

	for (int i = p1; i <= mid; i++) {
		list[index] = copy[i - start];
		index++;
	}
}
void mergesort(string* list, int start, int end) {
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
	string* list;

	cin >> n;

	list = new string[n];

	for (int i = 0; i < n; i++) {
		cin >> list[i];
	}

	mergesort(list, 0, n - 1);

	for (int i = 0; i < n; i++) {
		if (list[i].size() != 0) {
			cout << list[i] << "\n";
		}
	}

	return 0;
}