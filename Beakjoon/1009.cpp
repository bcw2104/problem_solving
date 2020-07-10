#include<iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int t, a, b;
    int c, temp;
    cin >> t;

    int* result = new int[t];

    for (int i = 0; i < t; i++) {
        cin >> a >> b;

        if (a > 10) {
            a = a % 10;
        }

        temp = (b - 1) % 4 + 1;

        c = 1;
        for (int j = 0; j < temp; j++) {
            c = c * a;
        }

        temp = c % 10;
        if (temp == 0) {
            temp = 10;
        }
        result[i] = temp;
    }

    for (int i = 0; i < t; i++) {
        cout << result[i] << endl;
    }
    return 0;
}