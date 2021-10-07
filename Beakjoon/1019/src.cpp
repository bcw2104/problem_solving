#include<iostream>
using namespace std;

int ans[10]={ 0, };

void counter(int n, int m) {
	while (n) {
		ans[n % 10]+=m;
		n /= 10;
	}
}

void func(int start ,int end,int m) {
	while (start % 10 != 0 && start	<= end) {
		counter(start,m);
		start++;
	}
	if (start <= end) {
		while (end % 10 != 9 && start <= end) {
			counter(end,m);
			end--;
		}

		for (int i = 0; i < 10; i++) {
			ans[i] += (end / 10 - start / 10 + 1) * m;
		}

		start /= 10;
		end /= 10;

		func(start, end, m * 10);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;

	cin >> n;

	func(1, n, 1);


	for (int i = 0; i < 10; i++) {
		cout << ans[i] << " ";
	}

	cout << "\n";
	return 0;
}
