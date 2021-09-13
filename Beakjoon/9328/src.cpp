#include<iostream>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

bool visit[102][102];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, h, w;
	int X[] = { 1,0,-1,0 };
	int Y[] = { 0,1,0,-1 };
	cin >> t;

	while (t--) {
		int answer = 0;
		vector<vector<char>> map;
		bool keys[26] = { 0, };
		memset(visit, 0, sizeof(visit));

		string line;

		cin >> h >> w;
		map.resize(h + 2);
		for (int i = 0; i <= h + 1; i++) {
			map[i].resize(w + 2, '.');
			if (i >= 1 && i <= h) {
				cin >> line;
				for (int j = 0; j < line.length(); j++) {
					map[i][j + 1] = line[j];
				}
			}
		}

		cin >> line;
		if (line[0] != '0') {
			for (int i = 0; i < line.length(); i++) {
				keys[line[i] - 'a'] = 1;
			}
		}

		queue<pair<int, int>> q;

		visit[0][0] = 1;
		q.push({ 0,0 });

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;

			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + X[i];
				int ny = y + Y[i];

				if (nx >= 0 && nx < w + 2 && ny >= 0 && ny < h + 2 && visit[ny][nx] == 0 && map[ny][nx] != '*') {
					if (map[ny][nx] >= 'A' && map[ny][nx] <= 'Z') {
						if (keys[map[ny][nx] - 'A'] == 1) {
							q.push({ nx,ny });
							visit[ny][nx] = 1;
						}
					}
					else if (map[ny][nx] >= 'a' && map[ny][nx] <= 'z') {
						if (keys[map[ny][nx] - 'a'] == 0) {
							keys[map[ny][nx] - 'a'] = 1;
						}
						memset(visit, 0, sizeof(visit));
						map[ny][nx] = '.';
						visit[ny][nx] = 1;
						while (!q.empty()) {
							q.pop();
						}
						q.push({ nx,ny });
					}
					else if (map[ny][nx] == '.') {
						visit[ny][nx] = 1;
						q.push({ nx,ny });
					}
					else if (map[ny][nx] == '$') {
						visit[ny][nx] = 1;
						map[ny][nx] = '.';
						answer++;
						q.push({ nx,ny });
					}
				}
			}
		}
		cout << answer << "\n";
	}

	return 0;
}
