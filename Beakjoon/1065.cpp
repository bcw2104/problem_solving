#include<iostream>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int num;
	string str;
	int temp;
	int counter;

	cin >> num;

	if (num >= 100) {
		counter = 99;
		for (int i = 100; i <= num; i++) {
			str = to_string(i);
			for (int j = 0; j < str.size() - 1; j++) {
				if (j == 0) {
					temp = str[j] - str[j + 1];
				}
				else {
					if (temp != str[j] - str[j + 1]) {
						temp = 10;
						break;
					}
				}
			}

			if (temp != 10) {
				counter++;
			}
		}
	}
	else {
		counter = num;
	}

	cout << counter << endl;

	return 0;
}