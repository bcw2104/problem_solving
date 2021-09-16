#include<iostream>
#include<string>
#include<cstring>
using namespace std;

char map[1000][1000];
int visit[1000][1000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, answer = 0,idx=1;
	string str;
	memset(visit, 0, sizeof(visit));

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++){
			map[i][j] = str[j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j] == 0) {
				int nx=j,ny=i;
				while (true) {
					if (visit[ny][nx] > 0) {
						if (visit[ny][nx] == idx) answer++;
						idx++;
						break;
					}
					visit[ny][nx] = idx;

					if (map[ny][nx] == 'L') nx--;
					else if (map[ny][nx] == 'R') nx++;
					else if (map[ny][nx] == 'U') ny--;
					else if (map[ny][nx] == 'D') ny++;
				}
			}
		}
	}

	cout << answer << "\n";

	return 0;
}
