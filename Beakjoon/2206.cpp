#include <iostream>
#include <string>
#include <queue>

#define MAX 1000
using namespace std;

int N, M;
int MAP[MAX][MAX];
bool Visit[MAX][MAX][2];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int min = -1;

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string Inp;
        cin >> Inp;
        for (int j = 0; j < M; j++)
        {
            int Tmp = Inp[j] - '0';
            MAP[i][j] = Tmp;
        }
    }

    queue<pair<pair<int, int>, pair<int, int>>> Q;
    Q.push(make_pair(make_pair(0, 0), make_pair(0, 1)));
    Visit[0][0][0] = true;

    while (Q.empty() == 0)
    {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int chance = Q.front().second.first;
        int cnt = Q.front().second.second;
        Q.pop();

        if (x == N - 1 && y == M - 1)
        {
            min = cnt;
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < M)
            {
                if (MAP[nx][ny] == 1 && chance == 0)
                {
                    Visit[nx][ny][chance + 1] = true;
                    Q.push(make_pair(make_pair(nx, ny), make_pair(chance + 1, cnt + 1)));
                }
                else if (MAP[nx][ny] == 0 && Visit[nx][ny][chance] == false)
                {
                    Visit[nx][ny][chance] = true;
                    Q.push(make_pair(make_pair(nx, ny), make_pair(chance, cnt + 1)));
                }
            }
        }
    }

    cout << min << "\n";

    return 0;
}
