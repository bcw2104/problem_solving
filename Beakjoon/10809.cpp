#include<iostream>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	string str;
	int* dp = new int[26];
	cin >> str;

	for (int i = 0; i < 26; i++) {
		dp[i] = -1;
	}
	for (int i = 0; i < str.size(); i++) {
		if (dp[str[i] - 97] == -1) {
			dp[str[i] - 97] = i;
		}
	}

	for (int i = 0; i < 26; i++) {
		cout << dp[i] << " ";
	}
	cout << endl;
	return 0;
}