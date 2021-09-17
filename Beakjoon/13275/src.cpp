#include<iostream>
#include<string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string in,str="#";
    int p,r=-1,len,answer = 0;
    int dp[200001] = { 0, };

    cin >> in;

    for (int i = 0; i < in.length(); i++) {
        str += in[i];
        str += "#";
    }

    len = str.length();

    for (int i = 0; i < len; i++) {
        if (i > r) {
            p = r = i;
            while (r < len && r <= 2 * p && str[r] == str[2 * p - r]) r++;
            r--;
            dp[i] = r - p;
        }
        else {
            int j = 2 * p - i;
            if (dp[j] < r - i) {
                dp[i] = dp[j];
            }
            else if (dp[j] > r - i) {
                dp[i] = r - i;
            }
            else {
                p = i;
                while (r < len && r <= 2 * p && str[r] == str[2 * p - r]) r++;
                r--;
                dp[i] = r - p;
            }
        }
    }

    for (int i = 0; i < len; i++) {
        answer = max(answer,dp[i]);
    }

    cout << answer << "\n";

    return 0;
}
