#include <iostream>
#include<queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    long long n;
    queue<int> s;

    cin >> t;

    while (t--) {
        cin >> n;

        while (n > 0) {
            
            s.push(n % 2);

            n /= 2;
        }

        long long x = 1;
        while (!s.empty()) {
            int i = s.front();

            s.pop();

            n += x * i;

            x *= 3;
        }

        cout << n << "\n";
    }
    return 0;
}
