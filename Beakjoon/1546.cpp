#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int t;
	int m;
	int* score;
	double avg;

	cin >> t;

	score = new int[t] {0, };

	for (int i = 0; i < t; i++) {
		cin >> score[i];
	}

	m = score[0];

	for (int i = 1; i < t; i++) {
		if (m < score[i]) {
			m = score[i];
		}
	}
	avg = 0;
	for (int i = 0; i < t; i++) {
		avg += (double)score[i] / m * 100;
	}

	cout << avg / t << endl;
	return 0;
}