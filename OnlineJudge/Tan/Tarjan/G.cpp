#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int MAXN = 1e5 + 5;
const int MAXM = 2e5 + 5;
#define FILENAME "BAI4"

void file() {
    if (FILE *f = fopen(FILENAME".INP", "r")) {
        fclose(f);
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
}

vector<pair<int,int>> g[MAXN];
int n, m;
int low[MAXN], num[MAXN], timer;
bool isBridge[MAXM];

void dfs_bridge(int u, int pe) {
    low[u] = num[u] = ++timer;
    for (auto &e : g[u]) {
        int v = e.first;
        int id = e.second;
        if (id == pe) continue;
        if (!num[v]) {
            dfs_bridge(v, id);
            low[u] = min(low[u], low[v]);
            if (low[v] > num[u]) isBridge[id] = true;
        } else {
            low[u] = min(low[u], num[v]);
        }
    }
}

int comp[MAXN], compCnt;
void dfs_comp(int u) {
    comp[u] = compCnt;
    for (auto &e : g[u]) {
        int v = e.first;
        if (comp[v] || isBridge[e.second]) continue;
        dfs_comp(v);
    }
}

vector<int> tree[MAXN];
int dist[MAXN];
bool vis_global[MAXN];
bool vis_local[MAXN];

pair<int, int> bfs(int s, vector<int> &visited_nodes) {
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    vis_local[s] = true;
    visited_nodes.push_back(s);
    
    int far = s;
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(dist[u] > dist[far]) far = u;
        for(int v : tree[u]){
            if(!vis_local[v]){
                vis_local[v] = true;
                dist[v] = dist[u] + 1;
                visited_nodes.push_back(v);
                q.push(v);
            }
        }
    }
    return {far, dist[far]};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    if(!(cin >> n >> m)) return 0;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        if (u == v) continue;
        g[u].pb({v, i});
        g[v].pb({u, i});
    }

    for (int i = 1; i <= n; i++) if (!num[i]) dfs_bridge(i, -1);
    for (int i = 1; i <= n; i++) {
        if (!comp[i]) {
            compCnt++;
            dfs_comp(i);
        }
    }

    for (int u = 1; u <= n; u++) {
        for (auto &e : g[u]) {
            int v = e.first;
            if (comp[u] != comp[v]) tree[comp[u]].pb(comp[v]);
        }
    }

    int max_diam = 0;
    for (int i = 1; i <= compCnt; i++) {
        if (!vis_global[i]) {
            vector<int> nodes1, nodes2;
            pair<int, int> p1 = bfs(i, nodes1);
            for(int node : nodes1) {
                vis_local[node] = false;
                vis_global[node] = true;
            }
            pair<int, int> p2 = bfs(p1.first, nodes2);
            for(int node : nodes2) vis_local[node] = false;
            max_diam = max(max_diam, p2.second);
        }
    }

    cout << max_diam << '\n';
    return 0;
}