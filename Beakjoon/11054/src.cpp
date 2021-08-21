#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    vector<int> arr, dp;
    set<int> con;
    set<int>::iterator iter;

    cin >> n;

    dp.resize(n);

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    con.insert(arr[0]);
    dp[0] = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > *(--con.end())) {
            con.insert(arr[i]);
        }
        else if(arr[i] < *(--con.end())) {
            iter = con.lower_bound(arr[i]);
            con.erase(iter);
            con.insert(arr[i]);
        }
        dp[i] = con.size();
    }

    con.clear();
    con.insert(arr[n - 1]);

    for (int i = n-2; i >= 0; i--) {
        if (arr[i] > *(--con.end())) {
            con.insert(arr[i]);
        }
        else if (arr[i] < *(--con.end())) {
            iter = con.lower_bound(arr[i]);
            con.erase(iter);
            con.insert(arr[i]);
        }
        dp[i] += con.size()-1;
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (ans < dp[i])
            ans = dp[i];
    }
    cout << ans << "\n";

    return 0;
}
