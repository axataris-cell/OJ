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
// Created: 2026-03-28 21:37

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "171"

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

void testcase() {
    int n, m; cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    vector<pii> thang;

    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        if (a > b) swap(a, b);

        thang.pb({a, b});

        adj[a].pb(i - 1);
        adj[b].pb(i - 1);
    }

    vector<int> dist(n + 1, INF);

    pqueue<pii, vector<pii>, greater<pii>> pq;

    dist[1] = 0;
    pq.emplace(0, 1);

    while (!pq.empty()) {

        auto [_d, u] = pq.top();
        pq.pop();

        if (_d > dist[u]) continue;

        for (int id : adj[u]) {

            auto [a, b] = thang[id];

            int len = b - a;
            int cycle = 2 * len;

            int t = _d / 5;

            int cur = t % cycle;

            int target;

            if (u == a) {

                int wait;

                if (cur <= 0) wait = 0 - cur;
                else wait = cycle - cur;

                int time = _d + wait * 5 + len * 5;

                if (dist[b] > time) {
                    dist[b] = time;
                    pq.emplace(dist[b], b);
                }
            }

            else {

                int wait;

                if (cur <= len) wait = len - cur;
                else wait = cycle - (cur - len);

                int time = _d + wait * 5 + len * 5;

                if (dist[a] > time) {
                    dist[a] = time;
                    pq.emplace(dist[a], a);
                }
            }
        }
    }

    if (dist[n] == INF) cout << -1;
    else cout << dist[n];
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    file();

    int t = 1;
    while (t--) testcase();

    return 0;
}