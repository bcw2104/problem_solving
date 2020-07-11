#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int a, b;

	cin >> a >> b;

	cout << (b % 10) * a << endl;
	cout << (b % 100) / 10 * a << endl;
	cout << b / 100 * a << endl;
	cout << a * b << endl;

	return 0;
}