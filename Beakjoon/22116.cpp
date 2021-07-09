#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define MAX 1000000001

int arr[1000][1000];
int dp[1000][1000];
bool visit[1000][1000];

int X[4] = { 1, 0, -1, 0 };
int Y[4] = { 0, 1, 0, -1 };

typedef struct Node
{
    int x, y, h;
}node;


struct compare {
    bool operator()(node a, node b){
        return a.h > b.h;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int ans = 0;

    priority_queue<node,vector<node>, compare> pq;

    memset(visit, 0, sizeof(visit));

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            dp[i][j] = MAX;
        }
    }

    dp[0][0] = 0;
    pq.push({ 0,0,dp[0][0] });

    while (!pq.empty()) {
        int x = pq.top().x;
        int y = pq.top().y;
        int h = pq.top().h;
        
        pq.pop();
        if (visit[y][x] == 1) {
            continue;
        }
      
        visit[y][x] = 1;
       

        if (x == n - 1 && y == n - 1) {
            ans = h;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + X[i];
            int ny = y + Y[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && visit[ny][nx] == 0)
            {
                int nh = max(abs(arr[ny][nx] - arr[y][x]), h);
                dp[ny][nx] = min(nh, dp[ny][nx]);
                
                pq.push({ nx,ny,dp[ny][nx] });
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
