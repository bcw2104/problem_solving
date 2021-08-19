#include <iostream>
#include <string>
#include <vector>
#include<queue>

using namespace std;

typedef struct Pipe {
	int fx, fy, rx, ry;
}pipe;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<pair<pipe, int>> q;
	int n, answer = 0;
	int map[16][16];

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	q.push({{ 0,0,1,0 }, 0});

	while (!q.empty()) {
		pipe p = q.front().first;
		int status = q.front().second;
		q.pop();

		if (p.rx == n - 1 && p.ry == n - 1)
			answer++;
		
		if (status != 1 && p.rx + 1 < n && map[p.ry][p.rx + 1] == 0) {
			q.push({ { p.fx + 1,p.fy,p.rx + 1,p.ry }, 0 });
		}
		if (status != 0 && p.ry + 1 < n && map[p.ry+1][p.rx] == 0) {
			q.push({ { p.fx,p.fy + 1,p.rx,p.ry + 1 },1 });
		}
		if (p.rx + 1 < n && p.ry+1 < n && map[p.ry][p.rx + 1] == 0 && map[p.ry+1][p.rx] == 0 && map[p.ry+1][p.rx + 1] == 0) {
			q.push({ { p.fx,p.fy,p.rx+1,p.ry + 1 },2 });
		}
	}

	cout << answer << "\n";

	return 0;
}

