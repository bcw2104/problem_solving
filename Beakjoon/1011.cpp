#include<iostream>
#include<cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int t, a, b;
    int count, range;
    int idx;
    cin >> t;

    int* result = new int[t] {0, };

    for (int i = 0; i < t; i++) {
        cin >> a >> b;

        count = 0;
        range = b - a;
        idx = sqrt(range);

        if (idx * idx == range) {
            count = idx + idx - 1;
        }
        else {
            if (range > idx* idx + idx) {
                count = idx + idx + 1;
            }
            else {
                count = idx + idx;
            }
        }

        result[i] = count;
    }

    for (int i = 0; i < t; i++) {
        cout << result[i] << endl;
    }
    return 0;
}
