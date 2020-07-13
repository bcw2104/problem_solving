#include<iostream>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int x, y, w, h;
	int minx, miny;
	cin >> x >> y >> w >> h;

	minx = w - x < x ? w - x : x;
	miny = h - y < y ? h - y : y;
	cout << (minx > miny ? miny : minx) << "\n";

	return 0;
}