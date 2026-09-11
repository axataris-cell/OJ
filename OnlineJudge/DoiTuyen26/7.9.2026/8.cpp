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
    int k; cin >> k;
    for(int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    vector<int> s(k);
    for(int i = 0; i < k; i++) {
        cin >> s[i];
    }
    vector<int> dist(n + 1, INF);
    pqueue<pii,vector<pii>,greater<pii>> pq;

    for(int i = 0; i < k; i++) {
        dist[s[i]] = 0;
        pq.emplace(0, s[i]);
    }

    while (pq.size()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for(auto &[v, w] : g[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << (dist[i] == INF ? -1 : dist[i]) << ' ';
    }
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}