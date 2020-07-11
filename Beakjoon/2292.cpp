#include<iostream>
using namespace std;

int main(void)
{
	int n;
	int add;
	int idx;

	cin >> n;

	idx = 0;
	add = 1;

	while (true) {
		if (n <= add) {
			break;
		}
		else {
			idx++;
			add += 6 * idx;
		}
	}
	cout << idx + 1 << endl;
	return 0;
}