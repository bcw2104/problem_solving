#include<iostream>
using namespace std;


int* fibo(int n, int** memo) {
	int* a, * b;
	if (memo[n][0] != 1) {
		memo[n][0] == 1;
		if (n == 0) {
			memo[n][0] = 1;
			memo[n][1] = 1;
			memo[n][2] = 0;
		}
		else if (n == 1) {
			memo[n][0] = 1;
			memo[n][1] = 0;
			memo[n][2] = 1;
		}
		else {
			a = fibo(n - 1, memo);
			b = fibo(n - 2, memo);

			memo[n][0] = 1;
			memo[n][1] = a[1] + b[1];
			memo[n][2] = a[2] + b[2];
		}
	}

	return memo[n];

}
int main() {
	ios::sync_with_stdio(false);

	int t1;
	int  n;
	cin >> t1;

	int** memo;
	int* result;

	int* result1 = new int[t1] {0, };
	int* result2 = new int[t1] {0, };


	for (int i = 0; i < t1; i++) {
		cin >> n;

		memo = new int* [n + 1];

		for (int j = 0; j < n + 1; j++) {
			memo[j] = new int[3]{ 0, 0,0 };
		}

		result = fibo(n, memo);
		result1[i] = result[1];
		result2[i] = result[2];

	}
	for (int i = 0; i < t1; i++) {
		cout << result1[i] << " " << result2[i] << endl;
	}
	return 0;
}