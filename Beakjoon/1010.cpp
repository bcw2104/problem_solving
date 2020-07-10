#include<iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int t, a, b;
    int temp;
    cin >> t;

    int* result = new int[t];

    for (int i = 0; i < t; i++) {
        cin >> a >> b;

        temp = 1;
        for (int j = 1; j < a + 1; j++) {
            temp = temp * ((b - a) + j) / j;
        }

        result[i] = temp;
    }

    for (int i = 0; i < t; i++) {
        cout << result[i] << endl;
    }
    return 0;
}