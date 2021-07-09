#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int x;
    int pre=0;
    bool c=false, ans = true;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        if (!c) {
            if (pre < x) {
                pre = x;
            }
            else if(pre > x){
                c = true;
            }
            else {
                ans = false;
                break;
            }
        }
        else {
            if (pre <= x) {
                ans = false;
                break;
            }
            else {
                pre = x;
            }
        }
    } 

    cout << (ans ? "YES\n" : "NO\n");
   
    return 0;
}
