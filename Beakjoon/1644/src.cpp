#include <iostream>
#include<vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, idx, answer = 0, left = -1, right = -1 , sum=0;
    vector<int> p;
    vector<int> num;

    cin >> n;

    num.resize(n + 1);

    for (int i = 2; i <= n; i++)
    {
        num[i] = i;
    }

    for (int i = 2; i <= n; i++)
    {
        if (num[i] != 0) {
            idx = 2;

            while (i*idx <= n) {
                num[idx * i] = 0;
                idx++;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (num[i] != 0) {
            p.push_back(i);
        }
    }
    while (left <= right) {
        if (sum <= n) {
            if (sum == n) {
                answer++;
            }
            right++;

            if (right == p.size())
                break;

            sum += p[right];
        }
        else{
            sum -= p[++left];
        }
    }

    cout << answer << "\n";
    
    return 0;
}
