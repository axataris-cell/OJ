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
// Created: 2026-03-28 19:02

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "170"

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

const int MAXN = 5005;

vector<pii> g[MAXN];
vector<int> dist(MAXN, INF);
int enddist = INF;

void testcase() {
    int n, m ;cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        g[a].pb({b, c});
        g[b].pb({a, d});
    }
    pqueue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(0, 1);
    dist[1] = 0;
    while (pq.size()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto &[v, w] : g[u]) {
            if (v == 1) {
                if (enddist > dist[u] + w) {
                    enddist = dist[u] + w;
                }
                continue;
            }
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }

    cout << enddist;
    for (int i = 1; i <= n; i++) debug(dist[i]);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}