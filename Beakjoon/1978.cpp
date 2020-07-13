#include<iostream>
using namespace std;

int main(void)
{
	int t;
	int n;
	int count;

	cin >> t;

	count = 0;

	while (t > 0) {
		cin >> n;

		if (n != 1) {
			for (int i = 2; i <= n; i++) {
				if (i == n) {
					count++;
				}
				if (n % i == 0) {
					break;
				}
			}
		}
		t--;
	}
	cout << count << endl;
	return 0;
}