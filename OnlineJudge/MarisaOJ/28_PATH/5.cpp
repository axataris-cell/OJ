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

#define int long long

const int MAXN = 2e5 + 5;
const ll INF = (1LL<<60);

vector<pii> g[MAXN];
vector<vector<ll>> dist(MAXN, vector<ll>(11, INF));

struct dat {
    int u, pw;
    ll d;
};

struct comp {
    bool operator()(const dat &x, const dat &y) const {
        return x.d > y.d;
    }
};

void dijkstra(int s) {
    pqueue<dat, vector<dat>, comp> pq;

    dist[s][0] = 0;
    pq.push({s, 0, 0});

    while (!pq.empty()) {
        dat x = pq.top(); pq.pop();
        int u = x.u, pw = x.pw;
        ll d = x.d;

        if (d != dist[u][pw]) continue;

        for (auto [v, w] : g[u]) {
            if (pw == 0) {
                if (dist[v][w] > d) {
                    dist[v][w] = d;
                    pq.push({v, w, d});
                }
            } else {
                ll nd = d + 1LL * pw * w;
                if (dist[v][0] > nd) {
                    dist[v][0] = nd;
                    pq.push({v, 0, nd});
                }
            }
        }
    }
}

void testcase() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        g[i].clear();
        for (int pw = 0; pw <= 10; pw++) dist[i][pw] = INF;
    }

    for (int i = 1; i <= m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }

    dijkstra(1);

    if (dist[n][0] == INF) cout << -1;
    else cout << dist[n][0];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); file();

    ll t = 1;
    while (t--) testcase();

    return 0;
}
