#include <bits/stdc++.h>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
// #define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME ""
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=1e5+5,LOG=20,MOD=1e9+7,BASE=113,BLOCK=400;
vector<int> g[MAXN];
int tin[MAXN], tout[MAXN], tint[MAXN];
int timeDfs = 0;

void dfs(int u, int p) {
    tin[u] = ++timeDfs;
    tint[timeDfs] = u;
    for (int v : g[u]) {
        if (v != p) dfs(v, u);
    }
    tout[u] = timeDfs;
}

int minw[4 * MAXN];
bool lz[4 * MAXN];

void build(int id, int l, int r) {
    minw[id] = l;
    lz[id] = false;
    if (l == r) return;
    int mid = (l + r) / 2;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
}

void push(int id, int l, int r) {
    if (!lz[id]) return;
    int mid = (l + r) / 2;
    lz[id << 1] = true;
    minw[id << 1] = l;

    lz[id << 1 | 1] = true;
    minw[id << 1 | 1] = mid + 1;

    lz[id] = false;
}

void update_white(int id, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return;
    if (ql <= l && r <= qr) {
        lz[id] = true;
        minw[id] = l;
        return;
    }
    push(id, l, r);
    int mid = (l + r) / 2;
    update_white(id << 1, l, mid, ql, qr);
    update_white(id << 1 | 1, mid + 1, r, ql, qr);
    minw[id] = min(minw[id << 1], minw[id << 1 | 1]);
}

void update_black(int id, int l, int r, int pos) {
    if (l == r) {
        minw[id] = INF;
        return;
    }
    push(id, l, r);
    int mid = (l + r) / 2;
    if (pos <= mid) update_black(id << 1, l, mid, pos);
    else update_black(id << 1 | 1, mid + 1, r, pos);
    minw[id] = min(minw[id << 1], minw[id << 1 | 1]);
}

int getnxt(int id, int l, int r, int ql, int qr) {
    if (l > qr || r < ql || minw[id] == INF || minw[id] > qr) return INF;
    if (l == r) return l;
    push(id, l, r);
    int mid = (l + r) / 2;

    int res = getnxt(id << 1, l, mid, ql, qr);
    if (res != INF) return res;
    return getnxt(id << 1 | 1, mid + 1, r, ql, qr);
}

void testcase() {
    int n, q; cin >> n >> q;

    for (int i = 2; i <= n; i++) {
        int p; cin >> p;
        g[i].push_back(p);
        g[p].push_back(i);
    }

    dfs(1, 1);
    build(1, 1, n);

    for (int i = 1; i <= q; i++) {
        int t, v; cin >> t >> v;
        if (t == 1) {
            int curr = tin[v];
            while (curr <= tout[v]) {
                int nxt = getnxt(1, 1, n, curr, tout[v]);
                if (nxt == INF) break;

                update_black(1, 1, n, nxt);

                int u = tint[nxt];
                curr = tout[u] + 1;
            }
        } else if (t == 2) {
            update_white(1, 1, n, tin[v], tout[v]);
        } else {
            int w = getnxt(1, 1, n, tin[v], tin[v]);
            cout << (w == INF ? "black" : "white") << el;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}