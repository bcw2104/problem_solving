#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL), cout.tie(NULL), ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--)
	{
		int M, N, x, y;
		cin >> M >> N >> x >> y;
		vector<int> arr_N(N + 1, 0);

		int answer = x;
		int comp_y = x % N > 0 ? x % N : N;
		while (comp_y != y)
		{
			if (arr_N[comp_y])
			{
				answer = 0;
				break;
			}
			else
			{
				arr_N[comp_y] = 1;
				answer += M;

				comp_y = answer % N > 0 ? answer % N : N;
			}
		}

		if (answer)
			cout << answer << '\n';
		else
			cout << -1 << '\n';
	}

	return 0;
}
