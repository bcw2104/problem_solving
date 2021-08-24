#include <iostream>
#include <string>

using namespace std;

int n;
int dp[38][5][5] = { 0, };

string toBinary(long long b) {
    string rs = "";

    while (b > 0) {
        rs += b % 2+48;
        b /= 2;
    }

    return rs;
}

void matrixMulti(int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                dp[m +1][i][j] += (dp[m][i][k] * dp[m][k][j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[m + 1][i][j] = dp[m + 1][i][j] % 1000;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    long long b;
    int answer[5][5] = { 0, };

    cin >> n >> b;

    string bin = toBinary(b);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> num;
            dp[0][i][j] = num;
        }
    }
    for (int i = 0; i < bin.length(); i++) {
        matrixMulti(i);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                answer[i][j] = 1;
            else
                answer[i][j] = 0;
        }
    }

    for (int s = 0; s < bin.length(); s++) {
        if (bin[s] == '1') {
            int temp[5][5] = { 0, };
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < n; k++) {
                        temp[i][j] += (answer[i][k] * dp[s][k][j]);
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    answer[i][j] = temp[i][j] % 1000;
                }
            }
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
