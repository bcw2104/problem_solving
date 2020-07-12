#include<iostream>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int t, a, b;
	char* m;
	int temp;
	string str;

	cin >> t;
	while (t > 0) {
		cin >> a >> b;
		cin >> str;

		m = new char[26];
		for (int i = 0; i < 26; i++) {
			m[i] = 0;
		}

		for (int i = 0; i < str.size(); i++) {
			temp = str[i] - 65;
			if (m[temp] == 0) {
				m[temp] = (a * temp + b) % 26 + 65;
			}
			str[i] = m[temp];
		}

		cout << str << endl;
		t--;
	}
	return 0;
}