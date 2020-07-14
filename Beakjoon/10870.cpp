#include<iostream>
using namespace std;

int fibo(int*, int);
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int* dp;

	cin >> n;
	dp = new int[n + 1];		//중간 결과 저장 - 메모이제이션

	for (int i = 0; i <= n; i++) {
		dp[i] = -1;
	}

	cout << fibo(dp, n) << "\n";

	return 0;
}

//피보나치 재귀함수
int fibo(int* dp, int n) {
	if (dp[n] == -1) {
		if (n == 0) {
			dp[n] = 0;
		}
		else if (n == 1) {
			dp[n] = 1;
		}
		else {
			dp[n] = fibo(dp, n - 1) + fibo(dp, n - 2);
		}
	}
	return dp[n];
}