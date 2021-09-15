#include<iostream>
#include<vector>
using namespace std;

#define INF 2e9

int dist(int a, int b) {
	if (a == b)
		return 1;
	else if (a == 0)
		return 2;
	else if ((a + b) % 2 == 1)
		return 3;								
	else
		return 4;
}

int dp[100001][5][5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> arr;
	int num, size,answer=INF;

	while(1) {
		cin >> num;
		if (num == 0) break;

		arr.push_back(num);
	}

	size = arr.size();
	
	for (int i = 0; i <= size; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				dp[i][j][k] = INF;
			}
		}
	}
	dp[0][0][0] = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				if (dp[i][j][k] != INF) {
					if(k != arr[i])
						dp[i + 1][arr[i]][k] = min(dp[i + 1][arr[i]][k], dp[i][j][k] + dist(j, arr[i]));
					if (j != arr[i])
						dp[i + 1][j][arr[i]] = min(dp[i + 1][j][arr[i]], dp[i][j][k] + dist(k, arr[i]));
				}
			}
		}
	}
	for (int j = 0; j < 5; j++) {
		for (int k = 0; k < 5; k++) {
			answer = min(dp[size][j][k], answer);
		}
	}

	cout << answer << "\n";

	return 0;
}
