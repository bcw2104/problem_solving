#include <iostream>
#include <string>

using namespace std;

int r, c;
int map[20][20] = { 0, };
int visit[26] = { 0, };
int answer = 0;
int X[] = { 1,0,-1,0 };
int Y[] = { 0,1,0,-1 };

void recursive(int idx,int x,int y) {
    bool end = true;
    for (int i = 0; i < 4; i++) {
        int nx = X[i] + x;
        int ny = Y[i] + y;
        if (nx >= 0 && nx < c && ny >= 0 && ny < r && visit[map[ny][nx]] == 0) {
            visit[map[ny][nx]]++;
            recursive(idx + 1, nx, ny);
            visit[map[ny][nx]]--;
            end = false;
        }
    }
    if (end) {
        answer = max(answer, idx);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < c; j++) {
            map[i][j] = line[j] - 65;
        }
    }

    visit[map[0][0]]++;
    recursive(1, 0, 0);

    cout << answer << "\n";
    return 0;
}
