#include<iostream>
#include<cmath>
using namespace std;

#define MIN_GD -1000000001

int arr[51] = { 0, };
double grad(int x1,int y1,int x2,int y2) {
	return ((double)y2 - y1) / ((double)x2 - x1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, ans = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		double rmaxd= MIN_GD, maxd= MIN_GD;
		double gd;
		int cnt = 0;
		for (int j = i-1; j >= 0; j--) {
			gd = grad(0,arr[i],i-j, arr[j]);
			if (rmaxd < gd) {
				cnt++;
				rmaxd = gd;
			}
		}
		for (int j = i+1; j < n; j++) {
			gd = grad(0, arr[i], j-i, arr[j]);
			if (maxd < gd) {
				cnt++;
				maxd = gd;
			}
		}

		ans = max(ans, cnt);
	}
	cout << ans << "\n";

	return 0;
}
