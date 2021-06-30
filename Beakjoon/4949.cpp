#include <iostream>
#include <string>
#include<stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	bool balance = true;
	stack<char> s;

	while (1) {
		getline(cin, str);

		int size = str.length();

		if(size == 1 && str[0] == '.')
			break;

		for (int i = 0; i < size; i++) {
			if (str[i] == '(' || str[i] == '[') {
				s.push(str[i]);
			}
			else if ((str[i] == ')' || str[i] == ']')) {
				if (!s.empty()) {
					char t = s.top();

					if ((str[i] == ')' && t == '(') || (str[i] == ']' && t == '[')) {
						s.pop();
					}
					else {
						balance = false;
						break;
					}
				}
				else {
					balance = false;
					break;
				}
			}
		}

		if (balance && s.empty()) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";

			while (!s.empty()) {
				s.pop();
			}
		}

		balance = true;
	}

	return 0;
}
