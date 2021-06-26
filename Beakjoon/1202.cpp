#include <iostream>
#include <set>
#include <queue>
using namespace std;

typedef struct Node
{
    int m;
    int v;
} node;

struct compare
{
    bool operator()(node *a, node *b)
    {
        return a->v < b->v;
    }
};

priority_queue<node *, vector<node *>, compare> pq;
multiset<int> s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, c;
    long long sum = 0;
    set<int>::iterator iter;

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        node *n = new node;

        cin >> n->m >> n->v;

        pq.push(n);
    }

    for (int i = 0; i < k; i++)
    {
        cin >> c;

        s.insert(c);
    }

    while (!s.empty() && !pq.empty())
    {
        node *n = pq.top();
        pq.pop();
        iter = s.lower_bound(n->m);

        if (iter != s.end())
        {
            s.erase(iter);
            sum += n->v;
        }
        else
        {
            continue;
        }
    }

    cout << sum << "\n";

    return 0;
}
