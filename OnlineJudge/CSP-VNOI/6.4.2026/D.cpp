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
// Created: 2026-04-06 19:35

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "D"

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

const int MAXN = 1e3 + 2;

int s, t, startime, numberofroadsblokkk;

vector<pii> g[MAXN];
vector<vector<int>> adj(MAXN, vector<int>(MAXN, 0));
vector<int> dist(MAXN, INF);
vector<int> camduong;
map<pii, pii> block;

void dijkstra() {
    pqueue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(startime, s);
    dist[s] = startime;
    while (pq.size()) {
        auto [d, u] = pq.top(); pq.pop();
        for (auto [v, w] : g[u]) {
            if (block[{u, v}].second) {
                if (block[{u, v}].first <= d && d <= block[{u, v}].second) {
                    w += block[{u, v}].second - d;
                }
            }
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }
}

void testcase() {
    int n, m; cin >> n >> m;
    cin >> s >> t >> startime >> numberofroadsblokkk;
    for (int i = 1; i <= numberofroadsblokkk; i++) {
        int u; cin >> u;
        camduong.pb(u);
    }
    for (int i = 1; i <= m; i++) {
        int a, b, c; cin >> a >> b >> c;
        g[a].pb({b, c});
        g[b].pb({a, c});
        adj[a][b] = adj[b][a] = c;
    }
    int lasts = 0;
    for (int i = 1; i < camduong.size(); i++) {
        block[{camduong[i], camduong[i - 1]}] = block[{camduong[i - 1], camduong[i]}] = {lasts, lasts + adj[camduong[i]][camduong[i - 1]]};
        lasts += adj[camduong[i]][camduong[i - 1]];
    }
    dijkstra();

    cout << dist[t] - startime;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}