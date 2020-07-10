#include<iostream>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	string str;
	int* count = new int[26]{ 0, };
	int max;
	int dup;
	char result;

	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 97) {
			count[str[i] - 97]++;
		}
		else {
			count[str[i] - 65]++;
		}
	}
	result = 0;
	max = count[0];
	dup = 0;
	for (int i = 1; i < 26; i++) {
		if (max < count[i]) {
			max = count[i];
			result = i;
			dup = 0;
		}
		else if (max == count[i]) {
			dup++;
		}
	}

	if (dup > 0) {
		cout << "?" << endl;
	}
	else {
		cout << (char)(result + 65) << endl;
	}

	return 0;
}