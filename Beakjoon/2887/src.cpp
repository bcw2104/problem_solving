#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

typedef struct Planet {
	int n;
	int pos[3];
}planet;

typedef struct Edge {
	int a,b,w;
}edge;

struct compare {
	bool operator()(edge a, edge b) {
		return a.w > b.w;
	}
};

priority_queue<edge,vector<edge>, compare> pq;
vector<planet> planets;
vector<int> parent;

bool compx(planet a, planet b) {
	return a.pos[0] < b.pos[0];
}
bool compy(planet a, planet b) {
	return a.pos[1] < b.pos[1];
}
bool compz(planet a, planet b) {
	return a.pos[2] < b.pos[2];
}

int find(int n) {
	if (parent[n] == n) return n;
	return parent[n] = find(parent[n]);
}

bool _union(int n1, int n2) {
	int p1 = find(n1);
	int p2 = find(n2);

	if (p1 != p2) {
		parent[p1] = p2;
		return 1;
	}

	return 0;
}

void adj(int d) {
	for (int i = 0; i < planets.size()-1; i++) {
		edge e;

		e.a = planets[i].n;
		e.b = planets[i+1].n;
		e.w = abs(planets[i].pos[d] - planets[i + 1].pos[d]);
		pq.push(e);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	long long ans = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		planet p;

		p.n = i;
		cin >> p.pos[0] >> p.pos[1] >> p.pos[2];

		planets.push_back(p);
		parent.push_back(i);
	}
	sort(planets.begin(), planets.end(),compx);
	adj(0);
	sort(planets.begin(), planets.end(), compy);
	adj(1);
	sort(planets.begin(), planets.end(), compz);
	adj(2);

	while (!pq.empty()) {
		edge e = pq.top();
		pq.pop();

		if (_union(e.a, e.b))
			ans += e.w;
	}
	cout << ans << "\n";
	return 0;
}
