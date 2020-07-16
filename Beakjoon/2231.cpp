//Brute Force

#include<iostream>
#include<string>
using namespace std;

int convert(int _n) {
	string n = to_string(_n);
	int result = _n;
	for (int i = 0; i < n.size(); i++) {

		result += n[i] - 48;
	}
	return result;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string n;
	int _n;
	int start;
	int result = 0;

	cin >> n;

	_n = atoi(n.c_str());

	start = _n - 9 * n.size() > 0 ? _n - 9 * n.size() : 1;
	for (int i = start; i < _n; i++) {
		if (convert(i) == _n) {
			result = i;
			break;
		}
	}

	cout << result << "\n";
	return 0;
}