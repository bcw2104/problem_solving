#include<iostream>

using namespace std;

typedef struct line {
	pair<int,int> a,b;
};

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	int temp = x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1;

	if (temp > 0) return 1;
	else if (temp < 0) return -1;
	else return 0;
}

int check(line l1, line l2) {
	int abc = ccw(l2.a.first, l2.a.second, l2.b.first, l2.b.second, l1.a.first, l1.a.second);
	int abd = ccw(l2.a.first, l2.a.second, l2.b.first, l2.b.second, l1.b.first, l1.b.second);
	int cda = ccw(l1.a.first, l1.a.second, l1.b.first, l1.b.second, l2.a.first, l2.a.second);
	int cdb = ccw(l1.a.first, l1.a.second, l1.b.first, l1.b.second, l2.b.first, l2.b.second);

	if (abc * abd == 0 && cda * cdb == 0)
	{
		if (l1.a > l1.b) swap(l1.a, l1.b);
		if (l2.a > l2.b) swap(l2.a, l2.b);

		return l1.a <= l2.b && l2.a <= l1.b;
	}

	return abc * abd <= 0 && cda * cdb <= 0;
}

line lines[3000];
int parents[3000][2] = { 0, };

int find(int n) {
	if (parents[n][0] == n) return n;
	return parents[n][0] = find(parents[n][0]);
}

void _union(int n1, int n2) {
	int p1 = find(n1);
	int p2 = find(n2);

	if (p1 != p2) {
		parents[p2][0] = p1;
		parents[p1][1] += parents[p2][1];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,g=0,c=0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> lines[i].a.first >> lines[i].a.second >> lines[i].b.first >> lines[i].b.second;
		parents[i][0] = i;
		parents[i][1] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (check(lines[i], lines[j]))
				_union(i, j);
		}
	}
	for (int i = 0; i < n; i++) {
		if (parents[i][0] == i)
			g++;
		c = max(c, parents[i][1]);
	}

	cout << g << "\n" << c << "\n";
	return 0;
}
