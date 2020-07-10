#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	int t;
	int count = 0;
	int* dp;
	int idx;
	string str;

	cin >> t;

	while (t > 0) {
		cin >> str;
		dp = new int[26]{ 0, };

		for (int i = 0; i < str.size(); i++) {
			idx = str[i] - 97;
			if (dp[idx] == 0) {
				dp[idx] = i + 1;
			}
			else {
				if (dp[idx] == i) {
					dp[idx] = i + 1;
				}
				else {
					idx = -1;
					break;
				}
			}
		}

		if (idx != -1) {
			count++;
		}

		t--;
	}

	cout << count << endl;
	return 0;
}