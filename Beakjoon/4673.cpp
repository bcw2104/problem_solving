#include<iostream>
#include<string>
using namespace std;

int self(int n);

int main() {
	ios::sync_with_stdio(false);

	int* dp = new int[10001]{ 0, };
	int n;
	for (int i = 0; i < 10000; i++) {
		n = self(i);
		if (n <= 10000) {
			dp[n]++;
		}
	}
	for (int i = 0; i < 10000; i++) {
		if (dp[i] == 0) {
			cout << i << endl;
		}
	}

	return 0;
}

int self(int n) {
	string s = to_string(n);
	int rs = n;

	for (int i = 0; i < s.size(); i++) {
		rs += (s[i] - 48);
	}

	return rs;
}