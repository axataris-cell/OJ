#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "1"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=4e18,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
vector<pii>g[MAXN];
void testcase() {
    int n, m; cin >> n >> m;
    for(int i =1 ; i<= m; i++) {
        int k; cin >> k;
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        if (k == 2) {
            g[v].push_back({u, w});
        }
    }
    vector<int> cnt(n + 1, 0);
    vector<int> dist(n + 1, INF);
    pqueue<pii,vector<pii>,greater<pii>>pq;
    pq.emplace(0, 1);
    dist[1] = 0;
    cnt[1] = 1;
    while (pq.size()) {
        auto [d,u]= pq.top();pq.pop();
        if (d > dist[u]) continue;
        for(auto &[v, w] : g[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u];
                pq.emplace(dist[v], v);
            } else if (dist[v] == dist[u] + w) cnt[v] += cnt[u];
        }
    }
    if (dist[n] == INF) {
        cout << -1 << ' ' << 0;
        return;
    }
    cout << dist[n] << ' ' << cnt[n];
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}