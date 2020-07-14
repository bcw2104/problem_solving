#include<iostream>
using namespace std;

void star_print(char**, int, int, int);
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	char** pos;
	cin >> n;

	pos = new char* [n + 1];

	for (int i = 0; i <= n; i++) {
		pos[i] = new char[n + 1];
		for (int j = 0; j <= n; j++) {
			pos[i][j] = ' ';
		}
	}

	star_print(pos, n, 1, 1);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << pos[i][j];
		}
		cout << "\n";
	}

	free(pos);
	return 0;
}

void star_print(char** pos, int n, int px, int py) {
	if (n == 1) {
		pos[px][py] = '*';
	}
	else {
		for (int i = 0; i < 3; i++) {
			star_print(pos, n / 3, px + (n / 3) * i, py);
		}
		for (int i = 0; i < 3; i++) {
			if (i != 1) {
				star_print(pos, n / 3, px + (n / 3) * i, py + (n / 3) * 1);
			}
		}
		for (int i = 0; i < 3; i++) {
			star_print(pos, n / 3, px + (n / 3) * i, py + (n / 3) * 2);
		}
	}
}