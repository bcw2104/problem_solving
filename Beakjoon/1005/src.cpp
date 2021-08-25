#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t, n, k,w;
    int answer;
    queue<int> q;
    vector<int> dp, times,in;
    vector<vector<int>> forw;

    cin >> t;

    while (t--) {
        cin >> n >> k;

        answer = 0;
        forw.resize(n+1);
        in.resize(n + 1);
        dp.resize(n + 1);
        times.resize(n + 1);
        
        for (int i = 1; i <= n; i++) {
            cin >> times[i];
        }
        for (int i = 0; i < k; i++) {
            int to, from;
            cin >> from >> to;

            in[to]++;
            forw[from].push_back(to);
        }
        cin >> w;

        for (int i = 1; i <= n; i++) {
            if (in[i] == 0) {
                q.push(i);
                dp[i] = times[i];
            }
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            if(cur == w)
                answer = dp[cur];

            for (int i = 0; i < forw[cur].size(); i++) {
                int next = forw[cur][i];
                dp[next] = max(dp[next], dp[cur] + times[next]);
                in[next]--;
                if (in[next] == 0) {
                    q.push(next);
                }
            }
        }
        cout << answer << "\n";

        forw.clear();
        in.clear();
        dp.clear();
        times.clear();
    }
   
    return 0;
}
