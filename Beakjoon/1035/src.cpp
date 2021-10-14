#include<iostream>
#include<queue>
#include<string>
using namespace std;

#define MAX 25

bool dp[1 << MAX] = { 0, };
int X[4] = { 1,0,-1,0 };
int Y[4] = { 0,1,0,-1 };

int convert(int x, int y) {
	return y * 5 + x;
}

int checkAdj(vector<int> c) {
	int map[5][5] = { 0, };

	for (int i = 0; i < c.size(); i++) {
		map[c[i] / 5][c[i] % 5] = 1;
	}

	queue<pair<int, int>> mq;

	int adcnt = 0;
	mq.push({ c[0] / 5 ,c[0] % 5 });
	map[c[0] / 5][c[0] % 5] = 0;

	while (!mq.empty()) {
		int x = mq.front().second;
		int y = mq.front().first;
		mq.pop();
		adcnt++;

		for (int i = 0; i < 4; i++) {
			int nx = x + X[i];
			int ny = y + Y[i];
			if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && map[ny][nx] == 1) {
				map[ny][nx] = 0;
				mq.push({ ny,nx });
			}
		}
	}

	return adcnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string str;
	vector<int> pos;
	queue<pair<vector<int>,pair<int,int>>> q;
	int visit = 0;
	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		cin >> str;
		for (int j = 0; j < 5; j++) {
			if (str[j] == '*') {
				int p = (1 << convert(j, i));
				pos.push_back(convert(j,i));
				visit |= p;
				cnt++;
			}
		}
	}
	dp[visit] = 1;
	q.push({ pos,{visit,0} });

	while (!q.empty()) {
		vector<int> c = q.front().first;
		int v = q.front().second.first;
		int t = q.front().second.second;
		q.pop();
		

		if (cnt == checkAdj(c)) {
			cout << t << "\n";
			return 0;
		}

		for (int i = 0; i < c.size(); i++) {
			int temp = c[i];
			int x = temp % 5;
			int y = temp / 5;
			for (int j = 0; j < 4; j++) {
				int nx = x + X[j];
				int ny = y + Y[j];
				int p = convert(nx, ny);
				int nv = ((v ^ (1 << c[i])) | (1 << p));
				if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && !((1<<p) & v) && dp[nv] == 0) {
					dp[nv] = 1;
					c[i] = p;
					q.push({ c,{nv,t + 1} });
					c[i] = temp;
				}
			}
		}
	}
	
	return 0;
}
