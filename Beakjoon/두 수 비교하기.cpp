#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int a, b;

	cin >> a >> b;

	cout << (a > b ? ">" : a < b ? "<" : "==") << endl;

	return 0;
}