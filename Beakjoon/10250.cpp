#include<iostream>
using namespace std;

int main(void)
{
	int t;
	int h, w, n;
	int a, b;
	cin >> t;
	while (t > 0) {
		cin >> h >> w >> n;

		a = (n - 1) % h + 1;
		b = (n - 1) / h + 1;

		printf("%d%02d\n", a, b);
		t--;
	}
	return 0;
}