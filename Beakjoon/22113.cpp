#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    int sum = 0;
    int arr[100];
    int cost[100][100];

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
        arr[i]--;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }

    for (int i = 0; i < m - 1; i++)
    {
        int s = arr[i];
        int e = arr[i + 1];

        sum += cost[s][e];
    }

    cout << sum << "\n";

    return 0;
}
