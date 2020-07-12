#include<iostream>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);


	string str1;
	string str2;

	int size1, size2;
	int** arr;

	cin >> str1 >> str2;

	size1 = str1.size() + 1;
	size2 = str2.size() + 1;

	arr = new int* [size1];

	for (int i = 0; i < size1; i++) {
		arr[i] = new int[size2] { 0, };
	}


	for (int i = 1; i < size1; i++) {
		for (int j = 1; j < size2; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				arr[i][j] = arr[i - 1][j - 1] + 1;
			}
			else {
				arr[i][j] = arr[i][j - 1] > arr[i - 1][j] ? arr[i][j - 1] : arr[i - 1][j];
			}
		}
	}

	cout << arr[size1 - 1][size2 - 1] << endl;


	return 0;
}