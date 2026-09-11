#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "UOIGOD"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=4e18,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;

vector<pii> g[MAXN];
struct Edge {
    int to, w;
};

void testcase() {
    int n, m, a, b; cin >> n >> m >> a >> b;

    vector<vector<Edge>> g(n + 1), rev(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        rev[v].push_back({u, w});
    }

    vector<vector<int>> dist1(n + 1, vector<int>(a + 1, INF));

    {
        using DAT = tuple<int, int, int>;
        priority_queue<DAT, vector<DAT>, greater<DAT>> pq;

        dist1[1][0] = 0;
        pq.emplace(0, 1, 0);

        while (!pq.empty()) {
            auto [d, u, k] = pq.top(); pq.pop();
            if (d > dist1[u][k]) continue;

            for (auto &[v, w] : g[u]) {
                if (dist1[v][k] > d + w) {
                    dist1[v][k] = d + w;
                    pq.emplace(dist1[v][k], v, k);
                }
                if (k < a && dist1[v][k + 1] > d) {
                    dist1[v][k + 1] = d;
                    pq.emplace(dist1[v][k + 1], v, k + 1);
                }
            }
        }
    }

    vector<int> f(n + 1, INF);
    for (int u = 1; u <= n; u++) {
        for (int k = 0; k <= a; k++) {
            f[u] = min(f[u], dist1[u][k]);
        }
    }
    vector<vector<array<int, 2>>> dist2(n + 1, vector<array<int, 2>>(b + 1, {INF, INF}));

    {
        using DAT = tuple<int, int, int, int>;
        priority_queue<DAT, vector<DAT>, greater<DAT>> pq;

        for (int u = 1; u <= n; u++) {
            if (f[u] != INF) {
                dist2[u][0][0] = f[u];
                pq.emplace(f[u], u, 0, 0);
            }
        }

        while (!pq.empty()) {   
            auto [d, u, k, s] = pq.top(); pq.pop();
            if (d > dist2[u][k][s]) continue;

            for (auto &[v, w] : rev[u]) {
                if (dist2[v][k][1] > d + w) {
                    dist2[v][k][1] = d + w;
                    pq.emplace(dist2[v][k][1], v, k, 1);
                }
                if (k < b && dist2[v][k + 1][s] > d + 2 * w) {
                    dist2[v][k + 1][s] = d + 2 * w;
                    pq.emplace(dist2[v][k + 1][s], v, k + 1, s);
                }
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        int ans = INF;
        ans = min({ans, dist2[i][b][0], dist2[i][b][1]});
        for (int k = 0; k < b; k++) {
            ans = min(ans, dist2[i][k][0]);
        }
        cout << (ans == INF ? -1 : ans) << ' ';
    }
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}