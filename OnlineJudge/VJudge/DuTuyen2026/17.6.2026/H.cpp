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

#define FILENAME "H"

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
    int s, t; cin >> s >> t;
    
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }
    
    if (s == t) {
        cout << 0 << el;
        return;
    }
    
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, -1));
    queue<pii> q;
    
    dist[s][t] = 0;
    q.push({s, t});
    
    while (!q.empty()) {
        auto [u, v] = q.front();
        q.pop();
        
        for (int x : adj[u]) {
            for (int y : adj[v]) {
                if (dist[x][y] == -1) {
                    dist[x][y] = dist[u][v] + 1;
                    if (x == y) {
                        cout << dist[x][y] << el;
                        return;
                    }
                    q.push({x, y});
                }
            }
        }
    }
    
    cout << -1 << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; 
    while (t--) testcase();

    return 0;
}