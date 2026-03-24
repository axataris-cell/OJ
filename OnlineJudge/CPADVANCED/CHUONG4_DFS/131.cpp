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

// Author: Axataris
// Created: 2026-03-24 15:42

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "131"

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

#ifdef LOCAL
   #define debug(x) cerr << x << '\n'
#else
   #define debug(x)
#endif

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

void file() {
    if (FILE *f = fopen(FILENAME".INP", "r")) {
        fclose(f);
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
}

const int MAXN = 205;

vector<int> g[MAXN];
int num[MAXN], low[MAXN], comp[MAXN];
int csize[MAXN], outdeg[MAXN];
bool inst[MAXN];

int timer = 0, cnt = 0;
stack<int> st;

void dfs(int u) {
	num[u] = low[u] = ++timer;
	st.push(u);
	inst[u] = true;

	for (int v : g[u]) {
		if (!num[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if (inst[v]) {
			low[u] = min(low[u], num[v]);
		}
	}

	if (low[u] == num[u]) {
		++cnt;
		while (true) {
			int v = st.top(); st.pop();
			inst[v] = false;
			comp[v] = cnt;
			++csize[cnt];
			if (v == u) break;
		}
	}
}

void testcase() {
	int n; cin >> n;

	int a, b;
	while (cin >> a >> b) {
		g[a].push_back(b);
	}

	for (int i = 1; i <= n; i++) {
		if (!num[i]) dfs(i);
	}

	for (int u = 1; u <= n; u++) {
		for (int v : g[u]) {
			if (comp[u] != comp[v]) {
				outdeg[comp[u]]++;
			}
		}
	}

	int res = -1;
	for (int i = 1; i <= cnt; i++) {
		if (outdeg[i] == 0) {
			if (res == -1 || csize[i] < csize[res]) {
				res = i;
			}
		}
	}

	cout << csize[res] << el;
	for (int i = 1; i <= n; i++) {
		if (comp[i] == res) {
			cout << i << ' ';
		}
	}
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}