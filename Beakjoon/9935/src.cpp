#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str, bomb, temp, answer = "";

    cin >> str >> bomb;

    int size = bomb.length();
    int idx = 0;

    for (int i = 0; i < str.length(); i++) {
        answer += str[i];
        
        if (answer.length() >= size) {
            temp = &answer[answer.length() - size];
            if (temp.compare(bomb) == 0) {
                for (int j = 0; j < size; j++) {
                    answer.pop_back();
                }
            }
        }
    }

    if (answer.length() == 0)
        answer = "FRULA";

    cout << answer << "\n";
    return 0;
}
