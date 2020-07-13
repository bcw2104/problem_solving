#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
	int m, n;
	int* list;
	int idx;
	vector<int> prime;

	cin >> m >> n;

	list = new int[n + 1]{ 0, };

	for (int i = 1; i < n + 1; i++) {
		list[i] = i;
	}

	list[1] = 0;
	idx = 2;
	for (int i = 2; i < n + 1; i++) {
		if (list[i] != 0) {
			if (list[i] >= m) {
				prime.push_back(i);
			}
			while (n >= i * idx) {
				if (list[i * idx] != 0) {
					list[i * idx] = 0;
				}
				idx++;
			}
			idx = 2;
		}
	}

	for (int i = 0; i < prime.size(); i++) {
		cout << prime.at(i) << "\n";
	}
	return 0;
}