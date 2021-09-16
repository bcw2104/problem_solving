#include<iostream>
#include<vector>
using namespace std;

int X[] = { 0,-1,1,1,-1 };
int map[101][101] = { 0, };

typedef struct Shark {
	int r, c, s, d, z;
}shark;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int r, c, m, pos = 1, answer = 0;
	vector<shark> sharks;

	cin >> r >> c >> m;

	sharks.resize(m + 1);
	for (int i = 1; i <= m; i++) {
		cin >> sharks[i].r >> sharks[i].c >> sharks[i].s >> sharks[i].d >> sharks[i].z;

		if (sharks[i].d <= 2) {
			sharks[i].s %= ((r - 1)*2);
		}
		else {
			sharks[i].s %= ((c - 1) * 2);
		}
		if(map[sharks[i].r][sharks[i].c] == 0)
			map[sharks[i].r][sharks[i].c] = i;
		else
			map[sharks[i].r][sharks[i].c] = sharks[map[sharks[i].r][sharks[i].c]].z > sharks[i].z ? map[sharks[i].r][sharks[i].c] : i;
	}

	while (pos <= c) {
		for (int i = 1; i <= r; i++) {
			if (map[i][pos] != 0) {
				answer += sharks[map[i][pos]].z;
				map[i][pos] = 0;
				break;
			}
		}
		int cmap[101][101] = { 0, };

		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				if (map[i][j] != 0) {
					int ch=0;
					if (sharks[map[i][j]].d <= 2) {
						int n;
						int l = sharks[map[i][j]].d == 1 ? sharks[map[i][j]].r - 1 : r - sharks[map[i][j]].r;
						if (l < sharks[map[i][j]].s) {
							l = sharks[map[i][j]].s - l;
							ch++;
							ch += l / r;

							if ((sharks[map[i][j]].d+ch) % 2 == 0) {
								sharks[map[i][j]].d = 2;
							}
							else {
								sharks[map[i][j]].d = 1;
							}

							l = l % (r - 1) == 0 ?  r - 1 : l % (r - 1);

							if (sharks[map[i][j]].d == 1) {
								n = r - l;
							}
							else {
								n = 1 + l;
							}

							sharks[map[i][j]].r = n;

							if (cmap[n][j] == 0)
								cmap[n][j] = map[i][j];
							else
								cmap[n][j] = sharks[cmap[n][j]].z > sharks[map[i][j]].z ? cmap[n][j] : map[i][j];
						}
						else {
							n = i + X[sharks[map[i][j]].d] * sharks[map[i][j]].s;

							sharks[map[i][j]].r = n;
							if (cmap[n][j] == 0)
								cmap[n][j] = map[i][j];
							else
								cmap[n][j] = sharks[cmap[n][j]].z > sharks[map[i][j]].z ? cmap[n][j] : map[i][j];
						}
					}
					else {
						int n;
						int l = sharks[map[i][j]].d == 4 ? sharks[map[i][j]].c - 1 : c - sharks[map[i][j]].c;
						if (l < sharks[map[i][j]].s) {
							l = sharks[map[i][j]].s - l;
							ch++;
							ch += l / c;

							if ((sharks[map[i][j]].d + ch) % 2 == 0) {
								sharks[map[i][j]].d = 4;
							}
							else {
								sharks[map[i][j]].d = 3;
							}

							l = l % (c-1) == 0 ? c-1 : l%(c-1);

							if (sharks[map[i][j]].d == 4) {
								n = c - l;
							}
							else {
								n = 1 + l;
							}

							sharks[map[i][j]].c = n;
							if (cmap[i][n] == 0)
								cmap[i][n] = map[i][j];
							else
								cmap[i][n] = sharks[cmap[i][n]].z > sharks[map[i][j]].z ? cmap[i][n] : map[i][j];
						}
						else {
							n = j + X[sharks[map[i][j]].d] * sharks[map[i][j]].s;

							sharks[map[i][j]].c = n;
							if (cmap[i][n] == 0)
								cmap[i][n] = map[i][j];
							else
								cmap[i][n] = sharks[cmap[i][n]].z > sharks[map[i][j]].z ? cmap[i][n] : map[i][j];
						}
					}
				}
			}
		}

		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				map[i][j] = cmap[i][j];
			}
		}

		pos++;
	}
	cout << answer <<"\n";
	return 0;
}
