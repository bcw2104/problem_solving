#include<iostream>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	string str;
	int t;
	int repeat;

	cin >> t;

	while (t > 0) {
		cin >> repeat;
		cin >> str;

		for (int i = 0; i < str.size(); i++) {
			for (int j = 0; j < repeat; j++) {
				cout << str[i];
			}
		}
		cout << endl;

		t--;
	}
	return 0;
}