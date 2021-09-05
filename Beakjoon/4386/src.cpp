#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

vector<int> parents;

typedef struct Vertex {
    double x, y;
}vertex;

typedef struct Edge {
    int st, ed;
    double w;
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
    vector<vertex> v;
    int n;
    double answer = 0;

    cin >> n;

    v.resize(n + 1);
    parents.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        parents[i] = i;
    }

    for (int i = 1; i <= n; i++) {
        cin >> v[i].x >> v[i].y;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            edge e;
            e.st = i;
            e.ed = j;
            e.w = sqrt(pow(abs(v[i].x - v[j].x), 2)+ pow(abs(v[i].y - v[j].y), 2));
            pq.push(e);
        }
    }
    
    while (!pq.empty())
    {
        edge e = pq.top();
        
        pq.pop();

        if (group(e.st, e.ed)) {
            answer += e.w;
        }
    }
    cout.precision(2);
    cout << fixed <<  answer << "\n";

    return 0;
}
