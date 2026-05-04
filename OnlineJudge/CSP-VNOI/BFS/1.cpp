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

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "1"

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

void file() {
    if (FILE *f = fopen(FILENAME".INP", "r")) {
        fclose(f);
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
}

const int MAXN = 1005;

vector<int> g[MAXN];
int d[MAXN][MAXN];
pii par[MAXN][MAXN];

void testcase() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) g[i].clear();

    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            d[i][j] = -1;

    queue<pii> q;
    q.emplace(1, n);
    d[1][n] = 0;

    int meet = -1;

    while (q.size()) {
        auto [u, v] = q.front(); q.pop();

        if (u == v) {
            meet = u;
            break;
        }

        for (int nu : g[u]) {
            for (int nv : g[v]) {
                if (d[nu][nv] == -1) {
                    d[nu][nv] = d[u][v] + 1;
                    par[nu][nv] = {u, v};
                    q.emplace(nu, nv);
                }
            }
        }
    }

    if (meet == -1) {
        cout << -1 << el;
        return;
    }

    cout << d[meet][meet] << el;

    vector<int> p1, p2;
    int u = meet, v = meet;

    while (u != 1 || v != n) {
        p1.pb(u);
        p2.pb(v);
        auto t = par[u][v];
        u = t.fi;
        v = t.se;
    }

    p1.pb(1);
    p2.pb(n);

    reverse(all(p1));
    reverse(all(p2));

    for (auto x : p1) cout << x << ' ';
    cout << el;
    for (auto x : p2) cout << x << ' ';
    cout << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1;
    while (t--) testcase();

    return 0;
}