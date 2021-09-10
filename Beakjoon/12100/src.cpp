board[i][idx] = board[i][j];
						if (idx != j)
							board[i][j] = 0;
					}
					
				}
			}
		}
	}
	else if (d == 2) {
		for (int i = 0; i < n; i++) {
			idx = 0;
			for (int j = 1; j < n; j++) {
				if (board[j][i] != 0) {
					if (board[idx][i] == 0 || board[idx][i] == board[j][i]) {
						board[idx][i] += board[j][i];
						if (board[idx][i] == 2 * board[j][i])
							idx++;
						board[j][i] = 0;
					}
					else {
						idx++;
						board[idx][i] = board[j][i];
						if (idx != j)
							board[j][i] = 0;
					}
					
				}
			}
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			idx = n - 1;
			for (int j = n - 2; j >= 0; j--) {
				if (board[j][i] != 0) {
					if (board[idx][i] == 0 || board[idx][i] == board[j][i]) {
						board[idx][i] += board[j][i];
						if (board[idx][i] == 2 * board[j][i])
							idx--;
						board[j][i] = 0;
					}
					else {
						idx--;
						board[idx][i] = board[j][i];
						if (idx != j)
							board[j][i] = 0;
					}
					
				}
			}
		}
	}
}

void func(int cnt) {
	if (cnt == 5) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				answer = max(answer,board[i][j]);
			}
		}
	}
	else {
		int temp[20][20];
		copy(&board[0][0], &board[0][0] + 400, &temp[0][0]);

		for (int i = 0; i < 4; i++) {
			move(i);
			func(cnt + 1);
			copy(&temp[0][0], &temp[0][0] + 400, &board[0][0]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n; 

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	func(0);
	cout << answer << "\n";

	return 0;
}
