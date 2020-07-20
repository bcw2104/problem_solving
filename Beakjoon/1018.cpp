//Brute Force

#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	string* board;
	int min;
	int count;
	int flag;
	char check[2] = { 'B','W' };

	cin >> n >> m;
	board = new string[n];

	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	min = n * m;
	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			flag = 0;
			while (flag < 2) {
				count = 0;
				for (int k = i; k < i + 8; k++) {
					for (int l = j; l < j + 8; l++) {
						if (board[k][l] != check[flag]) {
							count++;
						}
						flag ^= 1;
					}
					flag ^= 1;
				}
				if (min > count) {
					min = count;
				}
				flag++;
			}
		}
	}

	cout << min << "\n";

	return 0;
}