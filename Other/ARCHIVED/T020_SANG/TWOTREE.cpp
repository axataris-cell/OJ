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
// Created: 2026-06-25 07:41

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "TWOTREE"

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

const int MAXN = 5e5 + 5;
const int LOG = 30;

int n;

vector<pii> g1[MAXN];

vector<vector<int>> par(LOG + 1, vector<int>(MAXN, 1));
vector<vector<int>> mx(LOG + 1, vector<int>(MAXN, 0));
vector<int> h(MAXN, 0);

void dfs(int u, int p) {
	for (auto &[v, w] : g1[u]) {
        if (v == p) continue;
        h[v] = h[u] + 1;
        par[0][v] = u;
        mx[0][v] = w; // max di 2^i cua v;?
        dfs(v, u);
    }
}

void preprocess() {
	for (int i = 1; i <= LOG; i++) {
		for (int j = 1; j <= n; j++) {
			par[i][j] = par[i - 1][par[i - 1][j]];
            mx[i][j] = max(mx[i - 1][j], mx[i - 1][par[i - 1][j]]);
		}
	}
}

int lcamx(int u, int v) {
    int res = 0;

	if (h[u] < h[v]) swap(u, v);
	int k = h[u] - h[v];
	for (int i = 0; (1 << i) <= k; i++) {
		if (k >> i & 1) {
            res = max(res, mx[i][u]);
            u = par[i][u];
        }
	}

	if (u == v) return res;
	
	for (int i = LOG; i >= 0; i--) {
		if (par[i][u] != -1 && par[i][u] != par[i][v]) {
            res = max({res, mx[i][u], mx[i][v]});
			u = par[i][u];
			v = par[i][v];
		}
	}

    return max({res, mx[0][u], mx[0][v]});

}

// tree 2 lca 

vector<pii> g2[MAXN];

vector<vector<int>> par2(LOG + 1, vector<int>(MAXN, 1));
vector<vector<int>> mx2(LOG + 1, vector<int>(MAXN, 0));
vector<int> h2(MAXN, 0);

void dfs2(int u, int p) {
	for (auto &[v, w] : g2[u]) {
        if (v == p) continue;
        h2[v] = h2[u] + 1;
        par2[0][v] = u;
        mx2[0][v] = w;
        dfs2(v, u);
    }
}

void preprocess2() {
	for (int i = 1; i <= LOG; i++) {
		for (int j = 1; j <= n; j++) {
			par2[i][j] = par2[i - 1][par2[i - 1][j]];
            mx2[i][j] = max(mx2[i - 1][j], mx2[i - 1][par2[i - 1][j]]);
		}
	}
}

int lcamx2(int u, int v) {
    int res = 0;

	if (h2[u] < h2[v]) swap(u, v);
	int k = h2[u] - h2[v];
	for (int i = 0; (1 << i) <= k; i++) {
		if (k >> i & 1) {
            res = max(res, mx2[i][u]);
            u = par2[i][u];
        }
	}

	if (u == v) return res;
	
	for (int i = LOG; i >= 0; i--) {
		if (par2[i][u] != -1 && par2[i][u] != par2[i][v]) {
            res = max({res, mx2[i][u], mx2[i][v]});
			u = par2[i][u];
			v = par2[i][v];
		}
	}

    return max({res, mx2[0][u], mx2[0][v]});

}
// casse

void testcase() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b, w; cin >> a >> b >> w;
        g1[a].pb({b, w});
        g1[b].pb({a, w});
    }
    for (int i = 1; i < n; i++) {
        int a, b, w; cin >> a >> b >> w;
        g2[a].pb({b, w});
        g2[b].pb({a, w});
    }
    dfs(1, 1);
    dfs2(1, 1);
    preprocess();
    preprocess2();

    if (n > 5000) {

    }

    vector<int> ans(2*n - 1, 0);

    for (int i = 2; i <= n; i++) {
        for (int j = i - 1; j >= 1; j--) {
            int mg = lcamx(i, j);
            int mp = lcamx2(i, j);
            // cout << "DEB " << i << ' ' << j << ' ' << mg << ' ' << mp << el;
            if (mg == mp) ++ans[mg];
            else {
                ++ans[mg];
                ++ans[mp];
            }
        }
    }

    for (int i = 1; i < 2 * n - 1; i++) cout << ans[i] << ' ';
}

/*
5
1 2 6
1 3 4
2 4 7
2 5 2
1 2 3
2 3 2
3 4 7
3 5 2
*/

/*
4
1 2 1
2 3 2
3 4 4
2 3 2
1 4 1
2 4 4
*/

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}