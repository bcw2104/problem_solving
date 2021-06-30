#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,r = 31,m = 1234567891;
	long long mem = 1;
	long long sum = 0;
	string str;

	cin >> n;

	cin >> str;
	

	for (int i = 0; i < n; i++) {
		sum += ((long long)str[i] - 96)*mem;
		mem *= r;
		if (mem > m) {
			mem %= m;
		}
		if (sum > m) {
			sum %= m;
		}
	}

	cout << sum << "\n";


	return 0;
}
