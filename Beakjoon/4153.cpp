#include<iostream>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int list[3];
	int key;
	int temp;

	while (true) {
		for (int i = 0; i < 3; i++) {
			cin >> list[i];
		}

		if (list[0] == 0) {
			break;
		}
		for (int i = 0; i < 2; i++) {
			key = 0;
			for (int j = 1; j < 3; j++) {
				if (list[key] > list[j]) {
					temp = list[key];
					list[key] = list[j];
					list[j] = temp;
				}
				key = j;
			}
		}

		if (list[2] * list[2] == (list[1] * list[1]) + (list[0] * list[0])) {
			cout << "right\n";
		}
		else {
			cout << "wrong\n";
		}
	}

	return 0;
}