#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
    long long t,answer = 0;
    vector<int> a1, a2,s1;

    cin >> t >> n;

    a1.resize(n);

    for (int i = 0; i < n; i++)
        cin >> a1[i];

    cin >> m;

    a2.resize(m);

    for (int i = 0; i < m; i++)
        cin >> a2[i];

    for (int i = 0; i < n; i++) {
        long long sum = 0;
        for (int j = i; j < n; j++) {
            sum += a1[j];
            s1.push_back(sum);
        }
    }

    sort(s1.begin(), s1.end());

    for (int i = 0; i < m; i++) {
        long long sum = 0;
        for (int j = i; j < m; j++) {
            sum += a2[j];   
            answer+= upper_bound(s1.begin(), s1.end(), t - sum) - lower_bound(s1.begin(), s1.end(), t - sum);
        }
    }

    cout << answer << "\n";
    
    return 0;
}
