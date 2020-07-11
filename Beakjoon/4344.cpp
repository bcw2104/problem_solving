#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int t, n;
	int* list;
	double avg;
	int sum;

	cin >> t;

	while (t > 0) {
		cin >> n;
		list = new int[n];

		avg = 0;
		sum = 0;

		for (int i = 0; i < n; i++) {
			cin >> list[i];
			sum += list[i];
		}

		avg = (double)sum / n;
		sum = 0;
		for (int i = 0; i < n; i++) {
			if (list[i] > avg) {
				sum++;
			}
		}

		printf("%0.3f%%\n", (double)sum / n * 100);
		t--;
	}
	return 0;
}