//Brute Force

#include<iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	int sum;
	int max;
	int* list;

	cin >> n >> m;

	list = new int[n] {0, };

	for (int i = 0; i < n; i++) {
		cin >> list[i];
	}

	max = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				sum = list[i] + list[j] + list[k];
				if (sum <= m && max < sum) {
					max = sum;
				}
			}
		}
	}

	cout << max << "\n";

	return 0;
}