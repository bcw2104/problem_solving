#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    int multi = 0;

    for (int i = 0; i < 5; i++)
    {
        cin >> num;

        multi += num * num;
    }

    cout << multi % 10 << "\n";

    return 0;
}
