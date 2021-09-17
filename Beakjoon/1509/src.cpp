#include<iostream>
#include<string>
using namespace std;

bool dp[2500][2500] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	int size;
	int count[2501];

	cin >> str;

	size = str.length();

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			if (i == 0)
				dp[j][j] = 1;
			else if (i == 1)
				dp[j][i + j] = str[j] == str[i + j];
			else
				dp[j][i + j] = dp[j + 1][i + j - 1] && str[j] == str[i + j];
		}
	}
	count[0] = 0;
	for (int i = 1; i <= size; i++) {
		count[i] = 2501;
		for (int j = 1; j <= i; j++) {
			if (dp[j-1][i-1]) {
				if (count[i] > count[j - 1] + 1) {
					count[i] = count[j - 1] + 1;
				}
			}
		}
	}

	cout << count[size] << '\n';

	return 0;
}
