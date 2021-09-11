#include<iostream>

using namespace std;

int ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
	long long temp = x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1;
	if (temp > 0) {
		return 1;
	}
	else if (temp < 0) {
		return -1;
	}
	else {
		return 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x1, y1, x2, y2, x3, y3, x4, y4,answer=0;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

	int rs1 = ccw(x3, y3, x4, y4, x1, y1);
	int rs2 = ccw(x3, y3, x4, y4, x2, y2);
	int rs3 = ccw(x1, y1, x2, y2, x3, y3);
	int rs4 = ccw(x1, y1, x2, y2, x4, y4);

	if (rs3 * rs4 < 0 && rs1*rs2<0) 
		answer = 1;
	if (rs1 == 0) {
		if (max(x3, x4) >= x1 && min(x3, x4) <= x1 && max(y3, y4) >= y1 && min(y3, y4) <= y1)
			answer = 1;
	}
	if (rs2 == 0) {
		if (max(x3, x4) >= x2 && min(x3, x4) <= x2 && max(y3, y4) >= y2 && min(y3, y4) <= y2)
			answer = 1;
	}
	if (rs3 == 0) {
		if (max(x1, x2) >= x3 && min(x1, x2) <= x3 && max(y1, y2) >= y3 && min(y1, y2) <= y3)
			answer = 1;
	}
	if (rs4 == 0) {
		if (max(x1, x2) >= x4 && min(x1, x2) <= x4 && max(y1, y2) >= y4 && min(y1, y2) <= y4)
			answer = 1;
	}

	cout << answer << "\n";
	return 0;
}
