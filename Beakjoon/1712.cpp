#include<iostream>
using namespace std;

int main(void)
{
	long long a, b, c;

	cin >> a >> b >> c;
	if (c <= b) {
		cout << -1 << endl;
	}
	else {
		cout << (long long)a / (c - b) + 1 << endl;
	}
	return 0;
}