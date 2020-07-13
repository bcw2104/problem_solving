#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
	int n;
	int* list;
	int idx;
	vector<int> prime;

	while (true) {
		cin >> n;

		if (n == 0) {
			break;
		}
		list = new int[2 * n + 1]{ 0, };

		for (int i = 1; i < 2 * n + 1; i++) {
			list[i] = i;
		}

		list[1] = 0;
		idx = 2;
		for (int i = 2; i < 2 * n + 1; i++) {
			if (list[i] != 0) {
				if (list[i] > n) {
					prime.push_back(i);
				}
				while (2 * n >= i * idx) {
					if (list[i * idx] != 0) {
						list[i * idx] = 0;
					}
					idx++;
				}
				idx = 2;
			}
		}
		free(list);
		cout << prime.size() << "\n";
		prime.clear();
	}
	return 0;
}