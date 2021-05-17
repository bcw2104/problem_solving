#include <iostream>
#include <cmath>
using namespace std;

#define maxnum 10000001

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    int a, b, c;
    int dist[101][101];

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            dist[i][j] = maxnum;

        dist[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << (dist[i][j] == maxnum ? 0 : dist[i][j]) << " ";
        }
        cout << "\n";
    }

    return 0;
}
