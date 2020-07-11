#include<iostream>
using namespace std;

int main(void)
{
	long long a, b, v, c;

	cin >> a >> b >> v;

	v = v - a;
	c = v / (a - b) - 1;
	v = v - c * (a - b) + a;

	if (v <= a) {
		c++;
	}
	else {
		while (1) {
			if (v <= a) {
				c++;
				break;
			}
			else {
				v = v - (a - b);
				c++;
			}
		}
	}
	cout << c << endl;
	return 0;
}