#include <iostream>
#include <cstring>
using namespace std;

int n;
int cnt[11];
int arr[1000000];

int gap() {
    int small = 0;
    int big = 0;

    for (int i = 1; i <= 10; i++) {
        if (cnt[i] > 0) {
            if (small == 0) {
                small = i;
            }
            big = i;
        }
    }

    return big - small;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ans = 0,len =0;
    int s = 0, e = 0;
       
    memset(cnt, 0, sizeof(cnt));

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    while (s <= e) {
        if (gap() <=2 && e<n ) {
            cnt[arr[e]]++;
            e++;
            len++;

            if (gap() <= 2 && ans < len) {
                ans = len;
            }
        }
        else{
            len--;
            cnt[arr[s]]--;
            s++;
        }
    }

    cout << ans << "\n";
   
    return 0;
}
