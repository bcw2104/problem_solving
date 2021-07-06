#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, idx;
    int arr[100001];
    int pos[2];
    string cmd, str;
    char c;
    bool error;

    cin >> t;

    while (t--)
    {

        memset(arr, 0, sizeof(arr));

        cin >> cmd >> n;

        idx = 0;

        str = "";

        do
        {
            cin >> c;

            if (c >= '0' && c <= '9')
            {
                str += c;
            }
            else if (c == ',')
            {

                arr[idx] = atoi(str.c_str());
                idx++;
                str = "";
            }
        } while (c != ']');
        if (str.length() > 0)
        {
            arr[idx] = atoi(str.c_str());
        }

        pos[0] = 0;
        pos[1] = n - 1;
        error = false;
        idx = 0;

        for (int i = 0; i < cmd.length(); i++)
        {
            if (cmd[i] == 'R')
            {
                idx ^= 1;
            }
            else
            {
                if (pos[0] > pos[1])
                {
                    error = true;
                    break;
                }
                else
                {
                    if (idx == 0)
                        pos[idx]++;
                    else
                        pos[idx]--;
                }
            }
        }

        if (error)
        {
            cout << "error\n";
        }
        else
        {
            if (pos[0] > pos[1])
            {
                cout << "[]\n";
            }
            else
            {
                if (idx == 1)
                {
                    cout << "[";
                    for (int i = pos[1]; i > pos[0]; i--)
                    {
                        cout << arr[i] << ",";
                    }
                    cout << arr[pos[0]] << "]\n";
                }
                else
                {
                    cout << "[";
                    for (int i = pos[0]; i < pos[1]; i++)
                    {
                        cout << arr[i] << ",";
                    }
                    cout << arr[pos[1]] << "]\n";
                }
            }
        }
    }

    return 0;
}
