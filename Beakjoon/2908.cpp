#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(void)
{
	string n1, n2;
	string c1, c2;

	cin >> n1 >> n2;
	c1 = "";
	c2 = "";
	for (int i = 0; i < n1.size(); i++) {
		c1 += n1[n1.size() - i - 1];
	}
	for (int i = 0; i < n2.size(); i++) {
		c2 += n2[n2.size() - i - 1];
	}

	cout << max(atoi(c1.c_str()), atoi(c2.c_str())) << endl;
}