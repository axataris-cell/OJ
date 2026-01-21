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

vector<int> g[26], deg(26, 0), topo;
bool vis[26];

void testcase() {
	int n; cin >> n;
	vector<string> dictionary;
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		dictionary.push_back(s);
	}
	for (int i = 0; i < n - 1; i++) {
		int l = 0, r = 0;
		int x = dictionary[i].size(), y = dictionary[i + 1].size();
		while (dictionary[i][l] == dictionary[i + 1][r] && l < x - 1 && r < y - 1) {
			++l; ++r;
		}
		if (dictionary[i][l] != dictionary[i + 1][r]) {
			g[dictionary[i][l] - 'a'].push_back(dictionary[i + 1][r] - 'a');
			++deg[dictionary[i + 1][r] - 'a'];
		}
	}
	queue<int> q;
	for (int i = 0; i < 26; i++) {
		if (deg[i] == 0) {
			q.push(i);
		}
	}
	while (q.size()) {
		int u = q.front(); q.pop();
		topo.push_back(u);
		for (int v : g[u]) {
			if (!vis[v]) {
				--deg[v];
				if (deg[v] == 0) q.push(v);
			}
		}
	}
	if (topo.size() < 26) {
		cout << -1;
		return;
	}
	for (auto x : topo) cout << (char)(x + 'a');
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	debug_time();

	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}
