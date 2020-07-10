#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	string sentence;
	getline(cin, sentence);

	int voca = 0;
	for (int i = 1; i < sentence.size(); i++)
	{
		if (sentence[i] == ' ')
			voca++;
	}

	if (sentence.back() == ' ')
		cout << voca;
	else
		cout << voca + 1;
}