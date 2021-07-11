#include <iostream>
#include<cstring>
#include<queue>
using namespace std;

int X[4] = { 1,0,-1,0 };
int Y[4] = { 0,1,0,-1 };

int n, m;
int board[8][8];
bool visit[8][8];
vector<pair<int, int>> virus;
queue<pair<int, int>> q;
int space = 0;

int func(int i, int j, int k) {
    board[i / m][i % m] = 1;
    board[j / m][j % m] = 1;
    board[k / m][k % m] = 1;

    int safe = space;

    memset(visit, 0, sizeof(visit));

    for (int i = 0; i < virus.size(); i++) {
        q.push(virus[i]);
        visit[virus[i].first][virus[i].second] = 1;
        safe++;
    }

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;

        q.pop();
        safe--;

        for (int i = 0; i < 4; i++) {
            int nx = x + X[i];
            int ny = y + Y[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[ny][nx] == 0 && visit[ny][nx] == 0) {
                visit[ny][nx] = 1;
                q.push(make_pair(ny,nx));
            }
        }
    }

    board[i / m][i % m] = 0;
    board[j / m][j % m] = 0;
    board[k / m][k % m] = 0;
    
    return safe;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    int ans = 0;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];

            if (board[i][j] == 0) {
                space++;
            }
            if (board[i][j] == 2) {
                virus.push_back(make_pair(i, j));
            }
        }
    }

    space -= 3;

    for (int i = 0; i < m*n-2; i++) {
        if (board[i / m][i % m] == 0) {
            for (int j = i; j < m * n - 1; j++) {
                if (board[j / m][j % m] == 0) {
                    for (int k = j; k < m * n; k++) {
                        if (board[k / m][k % m] == 0) {
                            int rs = func(i, j, k);

                            if (ans < rs) {
                                ans = rs;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << ans << "\n";
    
    return 0;
}
