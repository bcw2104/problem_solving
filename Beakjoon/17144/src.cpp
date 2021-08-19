#include <iostream>
using namespace std;

int map[51][51] = { 0, };
int dif[51][51] = { 0, };
int X[] = { 1,0,-1,0 };
int Y[] = { 0,1,0,-1 };
int r, c,ap;

void diffusion() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (map[i][j] >= 5) {
                int d = map[i][j] / 5;
                for (int k = 0; k < 4; k++) {
                    int nx = j + X[k];
                    int ny = i + Y[k];

                    if (nx >= 0 && nx < c && ny >= 0 && ny < r && map[ny][nx] != -1) {
                        dif[ny][nx] += d;
                        map[i][j] -= d;
                    }
                }
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (dif[i][j] > 0) {
                map[i][j] += dif[i][j];
                dif[i][j] = 0;
            }
        }
    }
}

int clean() {
    int t = ap - 1;
    int b = ap;
    int rs = map[t - 1][0] + map[b + 1][0];

    for (int i = t - 1; i > 0; i--) {
        map[i][0] = map[i - 1][0];
    }
    for (int i = b + 1; i < r - 1; i++) {
        map[i][0] = map[i+1][0];
    }

    for (int i = 0; i < c - 1; i++) {
        map[0][i] = map[0][i + 1];
        map[r - 1][i] = map[r - 1][i + 1];
    }

    for (int i = 0; i <= t - 1; i++) {
        map[i][c - 1] = map[i + 1][c - 1];
    }
    for (int i = r - 1; i >= b + 1; i--) {
        map[i][c - 1] = map[i - 1][c - 1];
    }

    for (int i = c - 1; i > 1; i--) {
        map[t][i] = map[t][i - 1];
        map[b][i] = map[b][i - 1];
    }
    map[t][1] = 0;
    map[b][1] = 0;

    return rs;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    int ans = 0;
    cin >> r >> c >> t;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> map[i][j];
            if (map[i][j] == -1)
                ap = i;
            else {
                ans += map[i][j];
            }
        }
    }

    while (t--) {
        diffusion();

        ans -= clean();
    }

    cout << ans << "\n";
    return 0;
}
