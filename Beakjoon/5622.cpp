#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	string str;
	int time = 0;
	int range = 0;

	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] <= 'O') {
			range = (str[i] - 65) / 3;
			time += range + 3;
		}
		else {
			if (str[i] >= 'P' && str[i] <= 'S') {
				time += 8;
			}
			else if (str[i] >= 'T' && str[i] <= 'V') {
				time += 9;
			}
			else {
				time += 10;
			}
		}
	}

	cout << time << endl;

	return 0;
}