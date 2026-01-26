#include <bits/stdc++.h>
#include <chrono>
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

void debug_time(const string& label = "") {
    static auto start = chrono::steady_clock::now();
    auto now = chrono::steady_clock::now();
    double ms = chrono::duration<double, milli>(now - start).count();
    cerr << "[TIME] " << label << ": " << ms << " ms\n";
}

const int MAXN = 1e5 + 5;

vector<int> g[MAXN], dist(MAXN, 0);
int color[MAXN];
bool vis[MAXN];

void bfs(int s) {
	queue<int> q;
	
	q.push(s);
	vis[s] = true;
	dist[s] = color[s];
	
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int v : g[u]) {
			if (!vis[v]) {
				vis[v] = true;
				dist[v] = dist[u] + color[v];
				q.push(v);
			}
		}
	}
}

void testcase() {
	int n; cin >> n;
	string s; cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') color[i + 1] = -1;
		else color[i + 1] = 1;
	}
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	bfs(1);
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (dist[i] < 0) ++res;
	}
	
	cout << res;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	debug_time();

	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}
