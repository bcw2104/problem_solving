//Brute Force

#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int count = 0;
	int num = 666;
	string _num;
	cin >> n;

	while (true) {
		_num = to_string(num);
		if (_num.find("666") != -1) {
			count++;
		}

		if (count == n) {
			cout << num << "\n";
			break;
		}
		num++;
	}

	return 0;
}