#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
int arr[8];
int temp[8];

void func(int cnt)
{
    if (cnt < m)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != 0 && !(i > 0 && arr[i] == arr[i - 1]))
            {
                temp[cnt] = arr[i];
                arr[i] = 0;
                func(cnt + 1);
                arr[i] = temp[cnt];
            }
        }
    }
    else
    {
        for (int i = 0; i < m; i++)
        {
            cout << temp[i] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    func(0);
    return 0;
}
