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
// Created: 2026-07-01 09:41

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "cards"

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
    if (FILE *f = fopen(FILENAME".inp", "r")) {
        fclose(f);
        freopen(FILENAME".inp", "r", stdin);
        freopen(FILENAME".out", "w", stdout);
    }
}

#define int long long

const int MAXN = 5e6 + 5;

vector<int> tplt(MAXN, 0);
vector<int> sz(MAXN, 0);
vector<bool> vis(MAXN, false);
vector<int> g[MAXN];

int comp = 0;

void bfs(int s) {
    queue<int> q;

    q.push(s);
    vis[s] = true;
    tplt[s] = comp;

    while (q.size()) {
        int u = q.front(); q.pop();
        ++sz[comp];
        for (int v : g[u]) {
            if (!vis[v]) {
                vis[v] = true;
                tplt[v] = comp;
                q.emplace(v);
            }
        }
    }
}

void testcase() {
    int n; cin >> n;
    int k; cin >> k;
    string s; cin >> s;

    vector<int> a(n + 1, 0);
    vector<int> b(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[a[i]] = i;
        g[i].pb(a[i]);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            ++comp;
            bfs(i);
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     cout << tplt[i] << ' ' << sz[tplt[i]] << el;
    // }

    sort(all(s));
    s = " " + s;

    vector<char> res(n + 1);
    for (int i = 1; i <= n; i++) {
        int szcomp = sz[tplt[i]];
        int bruh = k % szcomp;
        // cout << bruh << ' ' << i << el;

        int cur = i;
        for (int j = 1; j <= bruh; j++) {
            cur = b[cur];
        }
        res[cur] = s[i];
    }

    for (int i = 1; i <= n; i++) cout << res[i];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}