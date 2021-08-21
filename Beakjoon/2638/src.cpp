#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,answer = 0;
    int board[100][100] = { 0, };
    bool visit[100][100];
    int X[] = { 1,0,-1,0 };
    int Y[] = { 0,1,0,-1 };
    queue<pair<int, int>> melt,air;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    board[0][0] = 2;
    while(true) {
        memset(visit, 0, sizeof(visit));
        air.push({ 0,0 });
        visit[0][0] = 1;

        while (!air.empty()) {
            int ax = air.front().second;
            int ay = air.front().first;

            air.pop();

            for (int k = 0; k < 4; k++) {
                int ny = ay + Y[k];
                int nx = ax + X[k];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[ny][nx] != 1 && visit[ny][nx] == 0) {
                    visit[ny][nx] = 1;
                    board[ny][nx] = 2;
                    air.push({ ny,nx });
                }
            }
        }

        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (board[i][j] == 1) {
                    int cnt = 0;
                    for (int k = 0; k < 4; k++) {
                        if (board[i + Y[k]][j + X[k]] == 2) cnt++;
                    }
                    if (cnt >= 2) melt.push({ i,j });
                }
            }
        }

        if (melt.empty())
            break;
        else {
            answer++;
            while (!melt.empty()) {
                int rx = melt.front().second;
                int ry = melt.front().first;
                melt.pop();

                board[ry][rx] = 2;
            }
        }
    }

    cout << answer << "\n";

    return 0;
}
