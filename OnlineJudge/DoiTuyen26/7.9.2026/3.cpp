#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "3"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=4e18,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
void testcase() {
    int n, m, k, s, t; cin >> n >> m >> k >> s >> t;
    vector<vector<pii>> g(n + 1);
    for(int i = 1; i <= m; i++) {
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    vector<vector<pii>> can(n + 1);
    for(int i = 1; i <= k; i++) {
        int x, y; cin >> x >> y;
        int c; cin >> c;
        can[x].push_back({y, c});
        can[y].push_back({x, c});
    }
    vector<vector<int>>dist(2,vector<int>(n + 1, INF));
    dist[0][s] = 0;
    struct DAT{
        int d, u, used;
        bool operator()(const DAT &x, const DAT &y) const {
            return x.d > y.d;
        } ;
    };
    pqueue<DAT,vector<DAT>,DAT>pq;
    pq.push({0, s, 0});
    while (pq.size()) {
        auto [d,u,us] = pq.top();pq.pop();
        if (d > dist[us][u]) continue;
        for(auto &[v, w] : g[u]) {
            if (dist[us][v] > dist[us][u] + w) {
                dist[us][v] = dist[us][u] + w;
                pq.push({dist[us][v], v, us});
            }
        }
        if (us) continue;
        for(auto &[v, w] : can[u]) {
            if (dist[us + 1][v] > dist[us][u] + w) {
                dist[us + 1][v] = dist[us][u] + w;
                pq.push({dist[us + 1][v], v, us+ 1});
            }
        }
    }

    int res = min(dist[0][t],dist[1][t]);
    cout << (res == INF ? -1 : res) << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}