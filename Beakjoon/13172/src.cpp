#include <iostream>
using namespace std;

long long MOD = 1000000007;
long long n, s;

long long multi(long long x, long long k) {
    if (k == 1) return x;
    if (k%2) return x * multi(x, k - 1) % MOD;
    long long rs = multi(x, k / 2);

    return rs * rs % MOD;
}
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long ans = 0;

    int t; 
    cin >> t; 
    while (t--){
        cin >> n >> s;
        long long g = gcd(n, s);
        s /= g;
        n /= g;

        long long rev = multi(n, MOD - 2);
        ans += s * rev % MOD;
        ans %= MOD; 
    };
    cout << ans << "\n";
}
