#include <iostream>

using namespace std;

bool pos[3073][6144] = { 0, };

void recursive(int n,int x,int y) {
    if (n > 3) {
        recursive(n / 2, x, y);
        recursive(n / 2, x-n/2, y + n / 2);
        recursive(n / 2, x+n / 2, y + n / 2);
    }
    else {
        pos[y][x] = 1;
        pos[y+1][x-1] = 1;
        pos[y + 1][x+1] = 1;  
        pos[y + 2][x - 2] = 1;
        pos[y + 2][x-1] = 1;
        pos[y + 2][x] = 1;
        pos[y + 2][x + 1] = 1;
        pos[y + 2][x + 2] = 1;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    recursive(n,n,1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 2*n-1; j++) {
            cout << (pos[i][j] == 1 ? "*" : " ");
        }
        cout << "\n";
    }
    return 0;
}
