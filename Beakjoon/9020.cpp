#include<iostream>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	int n;
	int* list;
	int idx;
	int prime1, prime2;

	cin >> t;
	while (t > 0) {
		cin >> n;
		list = new int[n + 1]{ 0, };

		for (int i = 1; i < n + 1; i++) {
			list[i] = i;
		}

		list[1] = 0;
		idx = 2;
		for (int i = 2; i < n + 1; i++) {
			if (list[i] != 0) {
				while (n >= i * idx) {
					if (list[i * idx] != 0) {
						list[i * idx] = 0;
					}
					idx++;
				}
				idx = 2;
			}
		}

		prime1 = 0;
		prime2 = 0;
		for (int i = 2; i < n + 1; i++) {
			if (list[i] > 0) {
				if (list[i] <= list[n - list[i]]) {
					prime1 = list[i];
					prime2 = list[n - list[i]];
				}
			}
		}
		free(list);

		cout << prime1 << " " << prime2 << "\n";
		t--;
	}
	return 0;
}