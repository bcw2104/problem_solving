#include <iostream>
#include<string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string str;

    cin >> n >> str;
    
    if (n > 25) {
        bool line = true;
        for (int i = 11; i < n - 11; i++) {
            if (i!= n-12 && str[i] == '.') {
                line = false;
                break;
            }
        }

        if (line) {
            str = str.substr(0, 11) + "..." + str.substr(n - 11, 11);
        }
        else {
            str = str.substr(0, 9) + "......" + str.substr(n - 10, 10);
        }
    }

    cout << str << "\n";
    return 0;
}
