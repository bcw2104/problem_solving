#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int a;

	cin >> a;

	cout << (a % 400 == 0 || (a % 4 == 0 && a % 100 != 0) ? 1 : 0) << endl;

	return 0;
}