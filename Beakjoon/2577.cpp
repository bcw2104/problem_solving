#include<iostream>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int a, b, c;
	string result;
	int* count;

	cin >> a >> b >> c;
	count = new int[10]{ 0, };

	result = to_string(a * b * c);

	for (int i = 0; i < result.size(); i++) {
		count[(int)result[i] - 48]++;
	}

	for (int i = 0; i < 10; i++) {
		cout << count[i] << endl;
	}
	return 0;
}