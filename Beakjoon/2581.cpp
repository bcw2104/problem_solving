#include<iostream>
using namespace std;

int main(void)
{
	int m, n;
	int* list;
	int idx;
	int min, sum;

	cin >> m >> n;

	list = new int[n + 1]{ 0, };

	for (int i = 1; i < n + 1; i++) {
		list[i] = i;
	}

	list[1] = 0;
	idx = 2;
	for (int i = 2; i < n + 1; i++) {
		while (n >= i * idx) {
			if (list[i * idx] != 0) {
				list[i * idx] = 0;
			}
			idx++;
		}
		idx = 2;
	}

	sum = 0;
	min = 0;

	for (int i = m; i < n + 1; i++) {
		if (list[i] != 0) {
			sum += list[i];
			if (min == 0) {
				min = list[i];
			}
		}
	}

	if (sum > 0) {
		cout << sum << "\n" << min << endl;
	}
	else {
		cout << -1 << endl;
	}

	return 0;
}