#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "KROBOT"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
vector<int> g[MAXN];
void testcase() {
    int n, m, k; cin >> n >> m >> k;
    vector<vector<vector<int>>> dist(k, vector<vector<int>>(2, vector<int>(n + 1, INF)));
    vector<int> spec;
    for(int i = 1; i <= k; i++) {
        int x; cin >> x;
        spec.push_back(x);
    }
    auto bfs=[&](int s) -> void {
        queue<pii> q;
        vector<vector<bool>> vis(2, vector<bool>(n + 1, false));
        int start = spec[s];
        dist[s][0][start] = 0;
        vis[0][start] = true;
        q.push({start, 0});
        while (q.size()) {
            auto [u, p] = q.front(); q.pop();
            int nxtp = 1 - p;
            for(int v : g[u]) {
                if (!vis[nxtp][v]) {
                    vis[nxtp][v] = true;
                    dist[s][nxtp][v] = dist[s][p][u] + 1;
                    q.push({v, nxtp});
                }
            }
        }
    };
    for(int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i = 0; i < k; i++) bfs(i);

    int bestdist = INF;
    for(int i = 1; i <= n; i++) {
        int chan = 0, le = 0;
        for(int j = 0; j < k; j++) {
            chan = max(chan, dist[j][0][i]);
            le = max(le, dist[j][1][i]);
        }
        bestdist = min({bestdist, chan, le});
    }

    cout << (bestdist == INF ? -1 : bestdist);
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}