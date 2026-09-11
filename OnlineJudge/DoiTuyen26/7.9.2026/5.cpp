#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "4"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
vector<pii>g[MAXN];
void testcase() {
    int n, m, k; cin >> n >> m >> k;
    for(int i = 1; i <= m; i++) {
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    vector<vector<int>> dist(k + 1,vector<int>(n+1,INF));
    struct DAT {
        int d,u,used;
        bool operator()(const DAT &x, const DAT &y) const {
            return x.d > y.d;
        };
    };
    dist[0][1]=0;
    pqueue<DAT,vector<DAT>,DAT>pq;
    pq.push({0,1,0});
    while(pq.size()){
        auto[d,u,used] = pq.top();pq.pop();
        if(d>dist[used][u])continue;
        for(auto &[v, w] : g[u]) {
            if (dist[used][v] > dist[used][u] + w) {
                dist[used][v]=dist[used][u] + w;
                pq.push({dist[used][v], v, used});
            }
            if (used >= k) {
                continue;
            }
            if (dist[used + 1][v] > dist[used][u]) {
                dist[used + 1][v] = dist[used][u];
                pq.push({dist[used + 1][v], v, used + 1});
            }
        }
    }

    int res = INF;
    for(int i =0; i <= k; i++) res = min(res,dist[i][n]);

    cout << res;
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}