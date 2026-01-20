#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

#define FILENAME ""

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void file() {
	if (FILE *f = fopen(FILENAME".INP", "r")) {
		fclose(f);
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
}

const int MAXN = 1e5 + 5;

vector<int> dist(MAXN, -1);
bool vis[MAXN];

bool valid(int s) {
	return s >= 1 && s <= MAXN;
}

void bfs(int s) {
	queue<int> q;
	
	q.push(s);
	vis[s] = true;
	dist[s] = 0;
	
	while (!q.empty()) {
		int u = q.front(); q.pop();
		
		if (valid(2 * u) && !vis[2 * u]) {
			q.push(2 * u);
			vis[2 * u] = true;
			dist[2 * u] = dist[u] + 1;
		}
		
		if (valid(u - 1) && !vis[u - 1]) {
			q.push(u - 1);
			vis[u - 1] = true;
			dist[u - 1] = dist[u] + 1;
		}
	}
}

void testcase() {
	int n, m; cin >> n >> m;
	bfs(n);
	
	cout << dist[m];
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
