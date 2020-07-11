#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	string str;
	int count = 0;
	cin >> str;
	for (int i = 0; i < str.size() - 1; i++) {
		if (str[i] == 'c') {
			if (str[i + 1] == '=' || str[i + 1] == '-') {
				str[i] = '0';
				str[i + 1] = '0';
				count++;
			}
		}
		else if (str[i] == 'd') {
			if (str[i + 1] == '-') {
				str[i] = '0';
				str[i + 1] = '0';
				count++;
			}
			else if (str[i + 1] == 'z') {
				if (i + 2 < str.size()) {
					if (str[i + 2] == '=') {
						str[i] = '0';
						str[i + 1] = '0';
						str[i + 2] = '0';
						count++;
					}
				}
			}
		}
		else if (str[i] == 'l') {
			if (str[i + 1] == 'j') {
				str[i] = '0';
				str[i + 1] = '0';
				count++;
			}
		}
		else if (str[i] == 'n') {
			if (str[i + 1] == 'j') {
				str[i] = '0';
				str[i + 1] = '0';
				count++;
			}
		}
		else if (str[i] == 's') {
			if (str[i + 1] == '=') {
				str[i] = '0';
				str[i + 1] = '0';
				count++;
			}
		}
		else if (str[i] == 'z') {
			if (str[i + 1] == '=') {
				str[i] = '0';
				str[i + 1] = '0';
				count++;
			}
		}
	}
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != '0') {
			count++;
		}
	}
	cout << count << endl;

	return 0;
}