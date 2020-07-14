#include<iostream>
#include<queue>
using namespace std;

void hanoi(queue<int*>&, int, int, int, int);
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	queue<int*> q;
	cin >> n;

	hanoi(q, n, 1, 2, 3);

	cout << q.size() << "\n";

	while (!q.empty()) {
		cout << q.front()[0] << " " << q.front()[1] << "\n";
		q.pop();
	}
	return 0;
}

void hanoi(queue<int*>& q, int n, int a, int b, int c) {
	if (n == 1) {
		q.push(new int[2]{ a,c });
	}
	else {
		hanoi(q, n - 1, a, c, b);
		q.push(new int[2]{ a,c });
		hanoi(q, n - 1, b, a, c);
	}
}