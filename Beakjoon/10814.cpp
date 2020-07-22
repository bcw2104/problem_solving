#include<iostream>
#include<string>
#include<vector>
using namespace std;

void merge(vector<pair<int, string>>& list, int start, int mid, int end) {
	int p1 = start;
	int p2 = mid + 1;
	int index = start;
	vector<pair<int, string>> copy;

	for (int i = start; i <= end; i++) {
		copy.push_back(list[i]);
	}

	while (p1 <= mid && p2 <= end) {
		if (copy[p1 - start].first > copy[p2 - start].first) {
			list[index] = copy[p2 - start];
			p2++;
		}
		else if (copy[p1 - start].first <= copy[p2 - start].first) {
			list[index] = copy[p1 - start];
			p1++;
		}
		index++;
	}

	for (int i = p1; i <= mid; i++) {
		list[index] = copy[i - start];
		index++;
	}
}
void mergesort(vector<pair<int, string>>& list, int start, int end) {
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
	int age;
	string name;

	vector<pair<int, string>> list;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> age >> name;
		list.push_back(make_pair(age, name));
	}

	mergesort(list, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << list[i].first << " " << list[i].second << "\n";
	}

	return 0;
}