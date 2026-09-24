#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "1817B"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;

vector<int> g[MAXN];
int timeDfs=0;
vector<int> tin(MAXN, 0), tout(MAXN, 0), h(MAXN, 0);
vector<int> par(MAXN, 1);
vector<pii> res;
bool onpath(int u, int v) {
    return ((tin[u] <= tin[v] && tin[v] <= tout[u]) || (tin[v] <= tin[u] && tin[u] <= tout[v]));
}
void dfs(int u, int p) {
    tin[u]= ++timeDfs;
    for(int v : g[u]) {
        if (!tin[v]) {
            par[v] = u;
            h[v] = h[u] + 1;
            dfs(v, u);
        }
    }
    tout[u] = timeDfs;
}
void testcase() {
    int n, m; cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        g[i].clear();
        h[i] = 0;
        tin[i]=tout[i]=0;
        par[i] = i;
    }
    res.clear();
    timeDfs=0;

    for(int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i = 1; i <= n; i++) {
        if (!tin[i] && g[i].size() > 3) {
            dfs(i, i);
        }
    }

    for(int u = 1; u <= n; u++) {
        if (g[u].size() < 4) continue;

        for(int i = 0; i < g[u].size() - 1; i++) {
            for(int j = i + 1; j < g[u].size(); j++) {
                int x = g[u][i], y = g[u][j];
                if (h[x] < h[u] || h[y] < h[u]) continue;
                if (!onpath(x, y)) continue;

                if (h[x] < h[y]) swap(x, y);
                // cout << "PASSED " << x << ' ' << y << el;
                map<int, bool> used;

                used[x] = used[y] = true;
                res.push_back({x, u});
                while (x != y) {
                    used[x] = true;
                    res.push_back({x, par[x]});
                    x = par[x];
                }
                res.push_back({y, u});

            
                int cnt = 0;
                for(int k = 0; k < g[u].size();++k) {
                    if (k == i || k == j) continue;
                    if (used[g[u][k]]) continue;
                    ++cnt;
                    res.push_back({u, g[u][k]});
                    if (cnt >= 2) break;
                }
                if (cnt < 2) {
                    res.clear();
                    continue;
                }

                cout << "YES" << el;
                cout << res.size() << el;
                for(auto &[a, b] : res) {
                    cout << a << ' ' << b << el;
                }


                return;
            }
        }

        for(int i = 0; i < g[u].size() - 1; i++) {
            for(int j = i + 1; j < g[u].size(); j++) {
                int x = g[u][i], y = g[u][j];
                if (h[x] > h[u] || h[y] > h[u]) continue;
                if (!onpath(x, y)) continue;

                if (h[x] > h[y]) swap(x, y);

                map<int, bool> used;

                res.push_back({u, x});
                used[x] = used[y] = true;
                while (y != x) {
                    res.push_back({y, par[y]});
                    used[y] = true;
                    y = par[y];
                }
                res.push_back({y, u});

                int cnt = 0;
                for(int k = 0; k < g[u].size();++k) {
                    if (k == i || k == j) continue;
                    if (used[g[u][k]]) continue;
                    ++cnt;
                    res.push_back({u, g[u][k]});
                    if (cnt >= 2) break;
                }
                if (cnt < 2) {
                    res.clear();
                    continue;
                }

                cout << "YES" << el;
                cout << res.size() << el;
                for(auto &[a, b] : res) {
                    cout << a << ' ' << b << el;
                }
                return;
            }
        }
    }

    cout << "NO" << el;
    return;

    // cout << "YES" << el;
    // cout << res.size() << el;
    // for(auto &[u, v] : res) cout << u << ' ' << v << el;

}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}