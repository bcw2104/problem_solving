#include <iostream>
#include <queue>
using namespace std;

int group[10001];

typedef struct element
{
    int w;
    int a;
    int b;
} ele;

struct compare
{
    bool operator()(const ele &a, const ele &b)
    {
        return a.w > b.w;
    }
};

int getparent(int n)
{
    if (group[n] == n)
        return n;
    else
        return getparent(group[n]);
}

void setgroup(int a, int b)
{
    int ag = getparent(a);
    int bg = getparent(b);

    if (ag > bg)
        group[ag] = bg;
    else
        group[bg] = ag;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e, a, b, c;
    int counter = 0;
    int adder = 0;
    priority_queue<ele, vector<ele>, compare> q;
    cin >> v >> e;

    for (int i = 1; i <= v; i++)
    {
        group[i] = i;
    }

    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> c;

        q.push({c, a, b});
    }

    while (counter != v - 1)
    {
        int a = q.top().a;
        int b = q.top().b;
        int w = q.top().w;
        q.pop();

        if (getparent(a) == getparent(b))
            continue;

        setgroup(a, b);

        adder += w;
        counter++;
    }

    cout << adder << "\n";

    return 0;
}
