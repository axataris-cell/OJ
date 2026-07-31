#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fi first
#define se second
#define null nullptr
#define pb push_back
#define len length
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-06-30 09:39

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "DTREE"

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

#ifdef LOCAL
   #define debug(x) cerr << x << '\n'
#else
   #define debug(x)
#endif

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

void file() {
    if (FILE *f = fopen(FILENAME".INP", "r")) {
        fclose(f);
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
}

const int MAXN = 4e5 + 5;

vector<int> g[MAXN];
int n, q;
bool treeA[MAXN], treeB[MAXN];

vector<int> distA(MAXN, 0);
vector<int> distB(MAXN, 0);

int bfsA() {
    // bfs1
    int bestdist = 0;
    int bestnode = -1;
    {
        vector<int> vis(MAXN, false);
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (treeA[i]) {
                q.push(i);
                distA[i] = 0;
                vis[i] = true;
                bestnode = i;
                break;
            }
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : g[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    distA[v] = distA[u] + 1;
                    if (treeA[v] && bestdist < distA[v]) {
                        bestdist = distA[v];
                        bestnode = v;
                    }
                    q.push(v);
                }
            }
        }
    }
    {
        vector<int> vis(MAXN, false);
        queue<int> q;
        q.push(bestnode);
        vis[bestnode] = true;
        distA[bestnode] = 0;
        bestdist = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : g[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    distA[v] = distA[u] + 1;
                    if (treeA[v] && bestdist < distA[v]) {
                        bestdist = distA[v];
                    }
                    q.push(v);
                }
            }
        }
    }
    return bestdist;
}

int bfsB() {
    // bfs1
    int bestdist = 0;
    int bestnode = -1;
    {
        vector<int> vis(MAXN, false);
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (treeB[i]) {
                q.push(i);
                distB[i] = 0;
                vis[i] = true;
                bestnode = i;
                break;
            }
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : g[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    distB[v] = distB[u] + 1;
                    if (treeB[v] && bestdist < distB[v]) {
                        bestdist = distB[v];
                        bestnode = v;
                    }
                    q.push(v);
                }
            }
        }
    }
    {
        vector<int> vis(MAXN, false);
        queue<int> q;
        q.push(bestnode);
        vis[bestnode] = true;
        distB[bestnode] = 0;
        bestdist = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : g[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    distB[v] = distB[u] + 1;
                    if (treeB[v] && bestdist < distB[v]) {
                        bestdist = distB[v];
                    }
                    q.push(v);
                }
            }
        }
    }
    return bestdist;
}

void testcase() {
    cin >> n >> q;

    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    for (int i = 1; i <= n; i++) treeA[i] = true;


    while(q--) {
        int x; cin >> x;
        treeA[x] = false;
        treeB[x] = true;
        cout << bfsA() << ' ' << bfsB() << el;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}