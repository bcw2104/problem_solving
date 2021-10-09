#include<iostream>
#include<queue>
using namespace std;

typedef long long ll;

typedef struct Rate {
	int a, b, p, q;
}rate;

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	ll tm = 1;
	queue<rate> rq;
	ll ans[10] = { 0, };

	cin >> n;

	for (int i = 0; i < n-1; i++) {
		rate r;
		cin >> r.a >> r.b >> r.p >> r.q;

		if (r.p < r.q) {
			swap(r.a, r.b);
			swap(r.p, r.q);
		}

		int g = gcd(r.p, r.q);

		r.p /= g;
		r.q /= g;

		tm *= (ll)r.p*r.q;

		rq.push(r);
	}
	
	rate t = rq.front();
	rq.pop();

	ans[t.a] = tm;
	ans[t.b] = (tm / t.p) * t.q;

	while (!rq.empty()) {
		t = rq.front();
		rq.pop();

		if (ans[t.a] == 0 && ans[t.b] == 0) {
			rq.push(t);
			continue;
		}

		if (ans[t.a] != 0) {
			ans[t.b] = (ans[t.a] / t.p) * t.q;
		}
		else if (ans[t.b] != 0) {
			ans[t.a] = (ans[t.b] / t.q) * t.p;
		}
	}
	ll tg = ans[0];

	for (int i = 1; i < n; i++) {
		tg = gcd(tg, ans[i]);
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] / tg << " ";
	}
	cout << "\n";
	return 0;
}
