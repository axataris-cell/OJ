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
struct Edge{
    int to, l, t;
};
void testcase() {
    int k; cin >> k;
    int n, m; cin >> n >> m;
    vector<vector<Edge>>g(n+1);
    for(int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        int t; cin >> t;
        g[u].push_back({v, w, t});
        // g[v].push_back({u, w, t});
    }

    vector<vector<int>> dist(k + 1, vector<int>(n + 1, INF));
    struct DAT {
        int d, u, t;
        bool operator()(const DAT &x, const DAT &y) const {
            return x.d > y.d;
        };
    };
    pqueue<DAT, vector<DAT>, DAT> pq;
    pq.push({0, 1, 0});
    dist[0][1]=0;

    while (pq.size()) {
        auto [d, u, pre] = pq.top();pq.pop();
        if (d > dist[pre][u]) continue;
        for(auto &[v, w, t] : g[u]) {
            int nxt = pre + t;
            if (nxt > k) continue;
            if (dist[nxt][v] > dist[pre][u] + w) {
                dist[nxt][v] = dist[pre][u] + w;
                pq.push({dist[nxt][v], v, nxt});
            }
        }
    }

    int res = INF;
    for(int i= 0; i <= k; i++) {
        res= min(res, dist[i][n]);
    }

    cout << (res == INF ? -1 : res) << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}