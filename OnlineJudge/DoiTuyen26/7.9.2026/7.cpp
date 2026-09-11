#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "10"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=4e18,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
vector<pii> g[MAXN];
void testcase() {
    int n, m; cin >> n >> m;
    int k, l; cin >> k >> l;
    
    vector<int> bit(n + 1, 0);

    for(int i =1 ; i <= n; i++) {
        int sz; cin >> sz;
        for(int j = 0; j < sz; j++) {
            int x; cin >> x;
            --x;
            bit[i] |= (1LL << x);
        }
    }

    for(int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    vector<vector<int>> dist(1 << k, vector<int>(n + 1, INF));
    struct BRUH {
        int d, u, state;
        bool operator() (const BRUH &x, const BRUH &y) const {
            return x.d > y.d;
        };
    };
    pqueue<BRUH, vector<BRUH>, BRUH>pq;

    pq.push({0, 1, bit[1]});
    dist[bit[1]][1] = 0;

    // for(int i = 1; i <= n; i++) {
    //     cout << bit[i] << el;
    // }

    // return;
    while(pq.size()) {
        auto [d, u, mask] = pq.top(); pq.pop();
        if (d > dist[mask][u]) continue;
        for (auto &[v, w] : g[u]) {
            int nmask = mask | bit[v];
            if (dist[nmask][v] > dist[mask][u] + w) {
                dist[nmask][v] = dist[mask][u] + w;
                pq.push({dist[nmask][v], v, nmask});
            }
        }
    }

    // for(int mask = 0; mask < (1 << k); mask++) {
    //     cout << "mask: " << mask << el;
    //     for(int i = 1; i <= n; i++) {
    //         cout << i << ' ' << dist[mask][i] << el;
    //     }
    //     cout << el;
    // }
    // return;

    int res = INF;

    for(int i = 0; i < (1 << k); i++) {
        // cout << "DEBUG " << dist[i][n] << el;
        if (__builtin_popcount(i) >= l) {
            res = min(res, dist[i][n]);
        }
    }

    cout << (res == INF ? -1 : res);
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}