#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fi first
#define se second
#define null nullptr
#define pb push_back
#define len length
#define ll long long
#define ld long double
#define el '\n'

// Author: Fua

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

#ifdef LOCAL
   #define debug(x) cerr << x << '\n'
#else
   #define debug(x)
#endif

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

#define int long long

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;

vector<int> g[MAXN];
vector<int> h(MAXN, 0);
vector<int> par(MAXN, 1);
vector<int> pow2(MAXN, 1);

void prep() {
	for (int i = 1; i < MAXN; i++) {
		pow2[i] = (pow2[i - 1] * 2) % MOD;
	}
}

void dfs(int u, int p) {
	for (int v : g[u]) {
		if (v == p) continue;
		h[v] = h[u] + 1;
		par[v] = u;
		dfs(v, u);
	}
}

int lca(int u, int v) {
	if (h[u] < h[v]) swap(u, v);
	while (h[u] != h[v]) u = par[u];
	if (u == v) return u;
	while (par[u] != par[v]) {
		u = par[u];
		v = par[v];
	}
	return par[u];
}

void testcase() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		g[i].clear();
		par[i] = 1;
		h[i] = 0;
	}
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	int leafCount = 0;
	vector<int> leaves;
	for (int i = 2; i <= n; i++) {
		if (g[i].size() == 1) {
			++leafCount;
			leaves.pb(i);
		}
	}
	if (leafCount > 2) {
		cout << 0 << el;
		return;
	}
	if (leafCount == 1) {
		cout << pow2[n] << el;
		return;
	} else {
		dfs(1, 1);
		int x = h[leaves[0]];
		int y = h[leaves[1]];
		if (x > y) swap(x, y);
		int lc = h[lca(leaves[0], leaves[1])];

		if (x == y) {
			cout << (4 * pow2[lc]) % MOD << el;
			return;
		}
		cout << (2 * (pow2[lc]) * ((pow2[y - x] + pow2[y - x - 1]) % MOD)) % MOD << el;
		return;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	prep();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}