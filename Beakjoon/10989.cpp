//Counting Sort

#include<iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int num;
	int* list;

	cin >> n;

	list = new int[10001]{ 0, };

	for (int i = 0; i < n; i++) {
		cin >> num;
		list[num]++;
	}


	for (int i = 1; i < 10001; i++) {
		for (int j = 0; j < list[i]; j++) {
			cout << i << "\n";
		}
	}

	return 0;
}