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
// Created: 2026-06-23 14:23

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "G"

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

struct Query {
    int t;
    ll d;
    int id;
};

int vis_id[5005][2];
int dist[5005][2];

void testcase() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vector<vector<Query>> queries(n + 1);
    for (int i = 0; i < k; ++i) {
        int s, t;
        ll d;   
        cin >> s >> t >> d;
        queries[s].pb({t, d, i});
    }

    vector<bool> ans(k);

    for (int s = 1; s <= n; ++s) {
        if (queries[s].empty()) continue;
        if (adj[s].empty()) {
            for (auto& q : queries[s]) {
                ans[q.id] = (s == q.t && q.d == 0);
            }
            continue;
        }

        queue<pii> q;
        vis_id[s][0] = s;
        dist[s][0] = 0;
        q.push({s, 0});

        while (!q.empty()) {
            auto [u, p] = q.front();
            q.pop();

            int nxt_p = 1 - p;
            for (int v : adj[u]) {
                if (vis_id[v][nxt_p] != s) {
                    vis_id[v][nxt_p] = s;
                    dist[v][nxt_p] = dist[u][p] + 1;
                    q.push({v, nxt_p});
                }
            }
        }

        for (auto& qry : queries[s]) {
            int p = qry.d % 2;
            if (vis_id[qry.t][p] == s && dist[qry.t][p] <= qry.d) {
                ans[qry.id] = true;
            } else {
                ans[qry.id] = false;
            }
        }
    }

    for (int i = 0; i < k; ++i) {
        cout << (ans[i] ? "YES" : "NO") << el;
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