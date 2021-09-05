#include <iostream>
#include <queue>
using namespace std;

vector<int> parents;

typedef struct Edge {
    int st, ed, w;
}edge;

struct compare {
    bool operator()(edge a, edge b) {
        return a.w > b.w;
    }
};

int find(int n) {
    if (n == parents[n]) return n;
    return parents[n] = find(parents[n]);
}

bool group(int n1, int n2) {
    int p1 = find(n1);
    int p2 = find(n2);

    if (p1 != p2) {
        parents[p1] = p2;
        return 1;
    }

    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<edge, vector<edge>,compare> pq;
    int n, m,answer = 0,last = 0;

    cin >> n >> m;

    parents.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        parents[i] = i;
    }

    for (int i = 0; i < m; i++) {
        edge e;

        cin >> e.st >> e.ed >> e.w;

        pq.push(e);
    }
    
    while (!pq.empty())
    {
        edge e = pq.top();
        
        pq.pop();

        if (group(e.st, e.ed)) {
            answer += e.w;
            last = e.w;
        }
    }

    cout << answer-last << "\n";

    return 0;
}
