#include<iostream>
using namespace std;

int main(void)
{
	int n;
	int mod;
	int div;
	int sub;

	cin >> n;

	mod = n % 5;
	div = n / 5;


	while (mod % 3 != 0) {
		mod += 5;
		div--;
		if (div < 0) {
			break;
		}
	}
	if (div < 0) {
		div = -1;
	}
	else {
		div += mod / 3;
	}


	cout << div << endl;
	return 0;
}