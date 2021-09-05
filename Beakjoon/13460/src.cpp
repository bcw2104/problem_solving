#include<iostream>
#include<queue>
#include<string>

using namespace std;

int X[] = { 1,0,-1,0 };
int Y[] = { 0,1,0,-1 };

typedef struct position {
	int bx, by, rx, ry;
}pos;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<pair<pos, int>> q;
	int n, m, answer=-1;
	char map[10][10];
	string line;
	pos init;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> line;

		for (int j = 0; j < m; j++) {
			map[i][j] = line[j];
			if (line[j] == 'B') {
				init.bx = j;
				init.by = i;
			}
			else if (line[j] == 'R') {
				init.rx = j;
				init.ry = i;
			}	
		}
	}

	q.push({ init ,0 });

	while (!q.empty()) {
		pos cur = q.front().first;
		int lvl = q.front().second;

		q.pop();

		if (lvl > 10) {
			break;
		}
				
		if (map[cur.ry][cur.rx] == 'O') {
			answer = lvl;
			break;
		}

		for (int i = 0; i < 4; i++) {
			pos np = cur;
			bool fail = false;
			if (X[i] == 0 && np.rx == np.bx) {
				if (np.ry * Y[i] > np.by * Y[i]) {
					while (map[np.ry + Y[i]][np.rx] != '#') {
						np.ry += Y[i];

						if (map[np.ry][np.rx] == 'O')
							break;
					}
					while (map[np.by + Y[i]][np.bx] != '#' && (np.by + Y[i] != np.ry || map[np.by+Y[i]][np.bx] == 'O')) {
						np.by += Y[i];

						if (map[np.by][np.bx] == 'O') {
							fail = true;
							break;
						}
					}
					if (!fail) {
						q.push({ np ,lvl + 1 });
					}
				}
				else {
					while (map[np.by + Y[i]][np.bx] != '#') {
						np.by += Y[i];

						if (map[np.by][np.bx] == 'O') {
							fail = true;
							break;
						}
					}
					if (!fail) {
						while (map[np.ry + Y[i]][np.rx] != '#' && np.by != np.ry + Y[i]) {
							np.ry += Y[i];

							if (map[np.ry][np.rx] == 'O')
								break;
						}
						q.push({ np ,lvl + 1 });
					}
				}
			}
			else if (Y[i] == 0 && np.ry == np.by) {
				if (np.rx * X[i] > np.bx * X[i]) {
					while (map[np.ry][np.rx + X[i]] != '#') {
						np.rx += X[i];

						if (map[np.ry][np.rx] == 'O')
							break;
					}
					while (map[np.by][np.bx + X[i]] != '#' && (np.bx + X[i] != np.rx || map[np.by][np.bx + X[i]] == 'O')) {
						np.bx += X[i];

						if (map[np.by][np.bx] == 'O') {
							fail = true;
							break;
						}
					}
					if (!fail) {
						q.push({ np ,lvl + 1 });
					}
				}
				else {
					while (map[np.by][np.bx + X[i]] != '#') {
						np.bx += X[i];

						if (map[np.by][np.bx] == 'O') {
							fail = true;
							break;
						}
					}
					if (!fail) {
						while (map[np.ry][np.rx + X[i]] != '#' && np.bx != np.rx + X[i]) {
							np.rx += X[i];

							if (map[np.ry][np.rx] == 'O')
								break;
						}
						q.push({ np ,lvl + 1 });
					}
				}
			}
			else {
				while (map[np.by + Y[i]][np.bx + X[i]] != '#') {
					np.bx += X[i];
					np.by += Y[i];

					if (map[np.by][np.bx] == 'O') {
						fail = true;
						break;
					}
				}
				if (!fail) {
					while (map[np.ry + Y[i]][np.rx + X[i]] != '#') {
						np.rx += X[i];
						np.ry += Y[i];

						if (map[np.ry][np.rx] == 'O')
							break;
					}

					q.push({ np ,lvl + 1 });
				}
			}
		}
	}

	cout << answer << "\n";
	return 0;
}
