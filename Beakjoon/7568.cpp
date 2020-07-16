//Brute Force

#include<iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int** list;
	int n;

	cin >> n;

	list = new int* [n];
	for (int i = 0; i < n; i++) {
		list[i] = new int[4]{ 0, };
		cin >> list[i][0] >> list[i][1];
		list[i][2] = 1;
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (list[i][0] < list[j][0] && list[i][1] < list[j][1]) {
				list[i][2] ++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << list[i][2] << " ";
	}
	cout << "\n";
	return 0;
}