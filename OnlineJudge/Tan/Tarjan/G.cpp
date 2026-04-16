#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int MAXN = 1e5 + 5;
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
bool isBridge[MAXN];

void dfs_bridge(int u, int pe) {
    low[u] = num[u] = ++timer;
    for (pair<int,int> e : g[u]) {
        int v = e.first;
        int id = e.second;

        if (id == pe) continue;

        if (!num[v]) {
            dfs_bridge(v, id);
            low[u] = min(low[u], low[v]);

            if (low[v] > num[u]) {
                isBridge[id] = true;
            }
        } else {
            low[u] = min(low[u], num[v]);
        }
    }
}

int comp[MAXN], compCnt;

void dfs_comp(int u) {
    comp[u] = compCnt;
    for (pair<int,int> e : g[u]) {
        int v = e.first;
        int id = e.second;

        if (comp[v]) continue;
        if (isBridge[id]) continue;

        dfs_comp(v);
    }
}

vector<int> tree[MAXN];

int bfs(int s, int &far) {
    queue<int> q;
    vector<int> dist(compCnt + 1, -1);

    q.push(s);
    dist[s] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : tree[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    far = s;
    for (int i = 1; i <= compCnt; i++) {
        if (dist[i] > dist[far]) far = i;
    }

    return dist[far];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    file();

    cin >> n >> m;

    int id = 0;
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        if (a == b) continue;

        g[a].pb({b, id});
        g[b].pb({a, id});
        id++;
    }

    for (int i = 1; i <= n; i++) {
        if (!num[i]) dfs_bridge(i, -1);
    }

    for (int i = 1; i <= n; i++) {
        if (!comp[i]) {
            compCnt++;
            dfs_comp(i);
        }
    }

    for (int u = 1; u <= n; u++) {
        for (pair<int,int> e : g[u]) {
            int v = e.first;
            int id = e.second;

            if (comp[u] != comp[v]) {
                tree[comp[u]].pb(comp[v]);
            }
        }
    }

    if (compCnt == 1) {
        cout << 0 << '\n';
        return 0;
    }

    int x;
    bfs(1, x);
    int diameter = bfs(x, x);

    int totalBridge = 0;
    for (int i = 0; i < id; i++) {
        if (isBridge[i]) totalBridge++;
    }

    cout << totalBridge - diameter << '\n';
}