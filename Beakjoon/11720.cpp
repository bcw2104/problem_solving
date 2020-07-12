#include<iostream>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	string str;
	int t;
	int sum = 0;

	cin >> t >> str;

	for (int i = 0; i < t; i++) {
		sum += str[i] - 48;
	}

	cout << sum << endl;
	return 0;
}