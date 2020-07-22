#include<iostream>
using namespace std;

void func(int* list, int n, int m, int index) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			cout << list[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = 0; i < n; i++) {
			if (index == 0 || i + 1 >= list[index - 1]) {
				list[index] = i + 1;
				func(list, n, m, index + 1);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	int* list;
	cin >> n >> m;

	list = new int[m];

	func(list, n, m, 0);

	return 0;
}