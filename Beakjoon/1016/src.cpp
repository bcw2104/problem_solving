include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

#define MAX 1000001
typedef long long ll;
bool p[MAX];
bool ns[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n, m;
	int ans = 0;

	memset(p, 1, sizeof(p));
	memset(ns, 1, sizeof(ns));

	cin >> n >> m;
	int limit = sqrt(m);

	for (int i = 2; i <= limit; i++) {
		if (p[i]) {
			int w = i*2;
			while (w <= limit) {
				p[w] = 0;
				w += i;
			}
		}
	}

	for (int i = 2; i <= limit; i++) {
		if (p[i]) {
			ll sq = (ll)i * i;
			ll start;

			if (sq < n) start = n % sq ? sq*((n/sq)+1) : sq * (n / sq);
			else start = sq;
			while (start <= m) {
				ns[start - n] = 0;
				start += sq;
			}
		}
	}

	for (int i = 0; i <= m - n; i++) {
		if (ns[i] == 1) {
			ans++;
		}
	}
	cout << ans << "\n";

	return 0;
}
