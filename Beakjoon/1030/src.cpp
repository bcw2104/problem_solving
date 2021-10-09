#include<iostream>
#include<cmath>
using namespace std;

int s, n, k,maxN;

bool isMiddle(int r,int c) {
	int sk = (n - k) / 2;
	int ek = sk + k-1;

	return (r >= sk && r <= ek && c >= sk && c <= ek);
}

int getColor(int r, int c) {
	int curN = maxN;
	int tr = r, tc = c,pr,pc;
	while ((curN /=n) > 0) {
		pr = tr / curN;
		pc = tc / curN;

		if (isMiddle(pr, pc)) return 1;

		tr -= pr * curN;
		tc -= pc * curN;
	}

	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int r1, r2, c1, c2;

	cin >> s >> n >> k >> r1 >> r2 >> c1 >> c2;

	maxN = pow(n, s);

	for (int i = r1; i <= r2; i++) {
		for (int j = c1; j <= c2; j++) {
			cout << getColor(i, j);
		}
		cout << "\n";
	}

	return 0;
}
