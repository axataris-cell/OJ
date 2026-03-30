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
// Created: 2026-03-28 15:30

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "167"

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

const int MAXN = 1e2 + 5;

vector<pii> g[MAXN];

void testcase() {
    int n, m; cin >> n >> m;
    int ha, sa, hb, sb;
    cin >> ha >> sa >> hb >> sb;

    for (int i = 1; i <= m; i++) {
        int a, b, c; cin >> a >> b >> c;
        g[a].pb({b, c});
        g[b].pb({a, c});
    }

    // SP DAG A
    vector<bool> onSP(n + 1, false);
    vector<int> dist1(n + 1, INF);
    {
        pqueue<pii, vector<pii>, greater<pii>> pq;
        pq.emplace(0, ha);
        dist1[ha] = 0;
        while (pq.size()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist1[u]) continue;
            for (auto &[v, w] : g[u]) {
                if (dist1[v] > dist1[u] + w) {
                    dist1[v] = dist1[u] + w;
                    pq.emplace(dist1[v], v);
                }
            }
        }
        vector<int> dag[n + 1];
        for (int u = 1; u <= n; u++) {
            for (auto &[v, w] : g[u]) {
                if (dist1[v] == dist1[u] + w) {
                    dag[v].pb(u);
                }
            }
        }
        // bfs
        queue<int> q;
        q.push(sa);
        while (q.size()) {
            int u = q.front();
            q.pop();
            onSP[u] = true;
            for (auto v : dag[u]) {
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++) debug(onSP[i]);
    cerr << el;
    // SP DAG 2
    int res = INF;
    {
        pqueue<pii, vector<pii>, greater<pii>> pq;
        vector<int> dist(n + 1, INF);
        pq.emplace(0, hb);
        dist[hb] = 0;
        while (pq.size()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (auto &[v, w] : g[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }
        vector<int> dag[n + 1];
        for (int u = 1; u <= n; u++) {
            for (auto &[v, w] : g[u]) {
                if (dist[v] == dist[u] + w) {
                    dag[u].pb(v);
                }
            }
        }
        queue<int> q;
        q.push(hb);
        while (q.size()) {
            int u = q.front(); q.pop();
            if (onSP[u] && dist1[u] == dist[u]) res = min(res, dist[u]);
            for (int v : dag[u]) {
                q.push(v);
            }
        }
    }

    cout << (res == INF ? -1 : res);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}