#include<iostream>
using namespace std;

const int x_arr[4] = { 1,0,-1,0 };
const int y_arr[4] = { 0,1,0,-1 };

void detection(int x, int y, int** arr, int size_x, int size_y, int num, int& counter) {
	counter++;
	arr[x][y]++;
	if (counter < num) {
		for (int i = 0; i < 4; i++) {
			if (x + x_arr[i] >= 0 && x + x_arr[i] < size_x && y + y_arr[i] >= 0 && y + y_arr[i] < size_y) {
				if (arr[x + x_arr[i]][y + y_arr[i]] == 1) {
					detection(x + x_arr[i], y + y_arr[i], arr, size_x, size_y, num, counter);
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);

	int t;
	int x_size, y_size, num;
	int x, y;
	int** arr;
	int counter, level;

	cin >> t;
	while (t > 0) {
		cin >> x_size >> y_size >> num;
		arr = new int* [x_size];
		for (int i = 0; i < x_size; i++) {
			arr[i] = new int[y_size] {0, };
		}

		for (int i = 0; i < num; i++) {
			cin >> x >> y;
			arr[x][y] = 1;
		}

		counter = 0;
		level = 0;
		for (int i = 0; i < x_size; i++) {
			for (int j = 0; j < y_size; j++) {
				if (arr[i][j] == 1) {
					detection(i, j, arr, x_size, y_size, num, counter);
					level++;
				}
			}
		}

		cout << level << endl;

		t--;
	}
	return 0;
}