#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "9"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=4e18,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
vector<pii> g[MAXN];
void testcase() {
    int n, m, k, C, s, t;
    cin >> n >> m >> k >> C >> s >> t;

    vector<int> spec;
    vector<bool> special(n + 1, false);

    for(int i = 1; i<= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    for(int i = 1; i <= k; i++) {
        int x; cin >> x;
        spec.push_back(x);
        special[x] = true;
    }

    vector<int> dist(n + 1, INF);
    pqueue<pii,vector<pii>,greater<pii>>pq;
    pq.emplace(0, s);
    dist[s] = 0;
    bool visspec=false;
    if (special[s]) {
        visspec=true;
        for(auto u : spec) {
            if (u == s) continue;
            dist[u] = C;
            pq.emplace(dist[u], u);
        }
    }
    while (pq.size()) {
        auto [d,u] = pq.top();pq.pop();
        if (d>dist[u]) continue;
        for(auto&[v,w] : g[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v],v);
            }
        }
        if (!special[u] || visspec)continue;
        
        visspec = true;
        for(auto v : spec) {
            if (dist[v] > dist[u] + C) {
                dist[v] = dist[u] + C;
                pq.emplace(dist[v], v);
            }
        }
    }

    cout << dist[t];
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}