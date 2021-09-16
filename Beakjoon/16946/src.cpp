#include<iostream>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

int map[1000][1000];
int cmap[1000][1000];
int cnt[1000002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, answer = 0,idx=2;
	string str;
	queue<pair<int, int>> q;
	int X[] = { 1,0,-1,0 };
	int Y[] = { 0,1,0,-1 };

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++){
			map[i][j] = str[j]-'0';
			cmap[i][j] = map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				int c=0;
				q.push({ j,i });
				map[i][j] = idx;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;

					q.pop();
					c++;
					for (int k = 0; k < 4; k++) {
						int nx = x + X[k];
						int ny = y + Y[k];

						if (nx >= 0 && nx < m && ny >= 0 && ny < n && map[ny][nx] == 0) {
							map[ny][nx] = idx;
							q.push({ nx,ny });
						}
					}
				}
				cnt[idx] = c;
				idx++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (cmap[i][j] == 1) {
				int x = j, y = i, c = 1;
				vector<int> check;
				for (int l = 0; l < 4; l++) {
					int nx = x + X[l];
					int ny = y + Y[l];
					
					if (nx >= 0 && nx < m && ny >= 0 && ny < n && map[ny][nx] >= 2) {
						bool exist = false;
						for (int k = 0; k < check.size(); k++) {
							if (map[ny][nx] == check[k]) {
								exist = true;
								break;
							}
						}
						if (!exist) {
							c += cnt[map[ny][nx]];
							check.push_back(map[ny][nx]);
						}
					}
				}
				cmap[i][j] = c;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << cmap[i][j];
		}
		cout << "\n";
	}

	return 0;
}
