#include<iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int result = 1;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		result *= i;
	}

	cout << result << "\n";

	return 0;
}