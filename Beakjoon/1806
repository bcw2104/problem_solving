#include <iostream>
#include<vector>
using namespace std;

int main() {
	
	int n, s,num;
	int ps=-1, pe=-1;
	int min,count,sum;
	vector<int> v;

	cin >> n >> s;

	min = n + 1;
	count = 0;
	sum = 0;

	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}

	while (1) {
		if (sum < s) {
			pe++;
			sum += v[pe];
			count++;
		}
		else {
			ps++;
			sum -= v[ps];
			count--;
		}

		if (sum >= s) {
			if (min > count) {
				min = count;
			}
		}

		if (sum < s && pe == n - 1)
			break;
	}


	if (min == n + 1) {
		min = 0;
	}

	cout << min << "\n";

	return 0;
}
