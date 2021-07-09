#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    int ans = 0;
    int arr[100000];

    cin >> n >> k;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
    }

    int jump = 0;

    do
    {
        int start = jump;
        jump = 0;
        int sum = 1;
        int chance = 1;

        for (int i = start; i < n - 1; i++)
        {
            if (arr[i] <= k)
            {
                sum++;
            }
            else if (chance == 1)
            {
                sum++;
                chance = 0;
                jump = i + 1;
            }
            else
            {
                break;
            }
        }

        if (sum > ans)
        {
            ans = sum;
        }

    } while (jump != 0);

    cout << ans << "\n";

    return 0;
}
