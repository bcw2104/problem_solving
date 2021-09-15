#include<iostream>
#include<string>
using namespace std;

typedef long long ll;

string binary(ll n) {
	string str = "";

	while (n != 0) {
		str += n % 2 + '0';
		n /= 2;
	}

	return str;
}

ll get(ll d) {
	if (d == 0)
		return 0;

	int len = binary(d).length()-1;
	ll cnt = 1;
	cnt = (cnt << (len - 1)) * len;

	cnt += d - ((ll)1 << len) + 1;

	cnt += get(d - ((ll)1 << len));

	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll a, b;

	cin >> a >> b;

	cout << get(b)-get(a-1) << "\n";
	return 0;
}
