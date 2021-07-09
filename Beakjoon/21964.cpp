#include <iostream>
#include<string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    int n;

    cin >> n >> str;
    
    cout << str.substr(n - 5) << "\n";
    return 0;
}
