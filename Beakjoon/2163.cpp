#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int m, n;


	cin >> m >> n;

	cout << m - 1 + (n - 1) * m;
	return 0;
}