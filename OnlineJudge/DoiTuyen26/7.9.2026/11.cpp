#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "11"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=4e18,MAXN=3e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
vector<pii>g[MAXN];
void testcase() {
    int n, m, s; cin >> n >> m >> s;
    vector<int> a(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) {
        int u, v, c; cin >> u >> v >> c;
        g[u].push_back({v, c});
    }
    vector<int> dist(n + 1, INF);
    vector<int> curmn(n + 1, INF);

    dist[s] = a[s];
    pqueue<pii,vector<pii>,greater<pii>>pq;
    pq.emplace(dist[s], s);
    curmn[s] = a[s];

    while (pq.size()) {
        auto [d, u ]= pq.top();pq.pop();
        if (d > dist[u]) continue;
        for(auto &[v, w] : g[u]) {
            int nxt = dist[u] + w;
            
            if (curmn[u] > a[v]) {
                nxt -= curmn[u];
                nxt += a[v];
            }
            if (dist[v] > nxt) {
                dist[v] = nxt;
                curmn[v] = min(curmn[u], a[v]);
                pq.emplace(dist[v], v);
            }
        }
    }

    // for(int i = 1; i <= n; i++) {
    //     cout << dist[i] << ' ';
    // }
    // return;

    int bestnode= -1;
    int resdist = -INF;
    for(int i = 1; i <= n; i++) {
        if (i == s) continue;
        if (dist[i] != INF && dist[i] > resdist) {
            resdist = dist[i];
            bestnode = i;
        }
    }

    cout << resdist << ' ' << bestnode;
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}