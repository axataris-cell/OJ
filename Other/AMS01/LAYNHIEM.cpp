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
// Created: 2026-08-03 09:26

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "LAYNHIEM"

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

const int MAXN = 1e5 + 5;

vector<int> g[MAXN];

void testcase() {
    int n, m, k, X; cin >> n >> m >> k >> X;
    vector<int> virus;
    for (int i = 1; i <= k; i++) {
        int x; cin >> x;
        virus.pb(x);
    }
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    vector<int> vis(n + 1, -1);
    vector<int> maimai(n + 1, 0);
    queue<int> q;
    for (auto x : virus) {
        q.push(x);
        vis[x] = 0;
        for (auto v : g[x]) ++maimai[v];
    }

    int curTime = 0;
    
    while (q.size()) {
        ++curTime;
        queue<int> nxt;
        while (q.size()) { // cur bfs
            int u = q.front(); q.pop();
            for (int v : g[u]) {
                if (vis[v] != -1) continue;
                if (maimai[v] >= X) {
                    vis[v] = curTime;
                    nxt.push(v); 
                }
            }
        }
        while (nxt.size()) {
            int u = nxt.front(); nxt.pop();
            for (int v : g[u]) {
                ++maimai[v];
            }
            q.push(u);
        }
    }

    cout << vis[n];
}

/*
5 6 2 2
1 2
1 3
2 3
2 4
3 4
3 5
4 5
*/

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}