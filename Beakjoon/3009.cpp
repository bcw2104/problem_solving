#include<iostream>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int pos[3][2]{ 0, };
	int x, y;

	for (int i = 0; i < 3; i++) {
		cin >> pos[i][0] >> pos[i][1];
	}

	if (pos[0][0] == pos[1][0]) {
		x = pos[2][0];
	}
	else {
		if (pos[0][0] == pos[2][0]) {
			x = pos[1][0];
		}
		else {
			x = pos[0][0];
		}
	}

	if (pos[0][1] == pos[1][1]) {
		y = pos[2][1];
	}
	else {
		if (pos[0][1] == pos[2][1]) {
			y = pos[1][1];
		}
		else {
			y = pos[0][1];
		}
	}

	cout << x << " " << y << "\n";
	return 0;
}