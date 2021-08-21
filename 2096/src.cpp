#include <iostream>

using namespace std;
#define MAX 2e9 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, line[3], idx = 0;
    int minDp[2][3] = { 0, };
    int maxDp[2][3] = { 0, };

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> line[0] >> line[1] >> line[2];

        for (int i = 0; i < 3; i++) {
            int big,small;
            if (i == 0) {
                big = max(maxDp[idx ^ 1][0], maxDp[idx ^ 1][1]);
                small = min(minDp[idx ^ 1][0], minDp[idx ^ 1][1]);
            }
            else if (i == 1) {
                big = max(max(maxDp[idx ^ 1][0], maxDp[idx ^ 1][1]), maxDp[idx ^ 1][2]);
                small = min(min(minDp[idx ^ 1][0], minDp[idx ^ 1][1]), minDp[idx ^ 1][2]);
            }
            else {
                big = max(maxDp[idx ^ 1][1], maxDp[idx ^ 1][2]);
                small = min(minDp[idx ^ 1][1], minDp[idx ^ 1][2]);
            }

            maxDp[idx][i] = line[i] + big;
            minDp[idx][i] = line[i] + small;
        }

        idx ^= 1;
    }

    int big=0, small= MAX;
    for (int i = 0; i < 3; i++) {
        if (big < maxDp[idx^1][i])
            big = maxDp[idx^1][i];
        if (small > minDp[idx ^ 1][i])
            small = minDp[idx ^ 1][i];
    }

    cout << big << " " << small << "\n";
    return 0;
}
