#include <bits/stdc++.h>
#include <chrono>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define int long long
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

int n, m;
string s;

vector<int> g[MAXN], deg(MAXN, 0), val(MAXN, 0);
int dist[26][MAXN];

int res = 0;

void bfs() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) {
			q.push(i);
			dist[val[i]][i] = 1;
		}
	}
	while (q.size()) {
		int u = q.front(); q.pop();
		for (auto v : g[u]) {
			for (int c = 0; c < 26; c++) dist[c][v] = max(dist[c][v], dist[c][u]);
			if (--deg[v] == 0) {
				++dist[val[v]][v];
				q.push(v);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
//		cerr << "DEBUG AT " << i << ": ";
		for (int c = 0; c < 26; c++) {
//			cerr << dist[c][i] << ' ';
			res = max(res, dist[c][i]);
		}
//		cerr << el;
	}
}

void testcase() {
	cin >> n >> m;
	cin >> s;
	
	for (int i = 0; i < n; i++) {
		val[i + 1] = s[i] - 'a';
	}
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		++deg[b];
	}
	
	bfs();
	
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
