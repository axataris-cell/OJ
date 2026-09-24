#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-14 22:24

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME ""

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void file() {
    if (FILE *f = fopen(FILENAME".INP", "r")) {
        fclose(f);
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
}

const int MAXN = 8001;
bitset<MAXN> reach[MAXN];
bitset<MAXN> col[MAXN];
bitset<MAXN> computed[MAXN];

void testcase() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        reach[i].reset();
        col[i].reset();
        computed[i].reset();
    }

    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < n; j++) {
            if (s[j] == '1') {
                reach[i].set(j);
                col[j].set(i);
            }
        }
    }
    bool ok = true;

    for(int i = 0; i < n && ok; i++) {
        if(!reach[i].test(i)) ok = false;
    }

    for(int i = 0; i < n && ok; i++) {
        for(int j = i + 1; j < n && ok; j++){
            if(reach[i].test(j) && reach[j].test(i)) ok = false;
        }
    }

    for(int i = 0; i < n && ok; i++) {
        for(int j = 0; j < n && ok; j++) {
            if (i != j && reach[i].test(j)) {
                if((reach[j] & reach[i]) != reach[j]) ok = false;
            }
        }
    }

    if (!ok) {
        cout << "NO" << el;
        return;
    }

    vector<pii> edges;
    vector<vector<int>> adj(n);

    for(int u = 0; u < n && ok; u++){
        for(int v = 0; v < n; v++){
            if(u == v || !reach[u].test(v)) continue;
            bitset<MAXN> inter = reach[u] & col[v];
            inter.reset(u); 
            inter.reset(v);
            if(inter.none()){
                adj[u].push_back(v);
                edges.push_back({u,v});
            }
        }
    }

    if (edges.size() != n - 1) {
        cout << "NO" << el;
        return;
    }

    vector<int> uf(n);
    iota(uf.begin(), uf.end(), 0);

    function<int(int)> find = [&](int x) -> int {
        return uf[x] == x ? x : uf[x] = find(uf[x]);
    };

    bool hasCycle = false;
    for(auto [u, v] : edges){
        int pu = find(u), pv = find(v);
        if(pu == pv) {
            hasCycle = true;
            break;
        }
        uf[pu] = pv;
    }

    if(hasCycle) {
        cout << "NO" << el;
        return;
    }

    int root = find(0);
    for(int i = 1; i < n && ok; i++) {
        if(find(i) != root) ok = false;
    }

    if(!ok) {
        cout << "NO" << el;
        return;
    }

    for(int i = 0; i < n; i++) {
        computed[i].set(i);
    }

    vector<int> indeg(n, 0);
    for(int u = 0; u < n; u++) {
        for(int v : adj[u]) indeg[v]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) q.push(i);
    }

    vector<int> topo;
    while(!q.empty()){
        int u = q.front(); 
        q.pop();
        topo.push_back(u);
        for(int v : adj[u]) {
            if(--indeg[v]==0) q.push(v);
        }
    }

    if (topo.size() < n) {
        cout << "NO" << el;
        return;
    }

    for(int i = topo.size() - 1; i >= 0; i--){
        int u = topo[i];
        for(int v : adj[u]) computed[u] |= computed[v];
    }

    for(int i = 0; i < n && ok; i++) {
        if(computed[i] != reach[i]) ok = false;
    }

    if (!ok) {
        cout << "NO" << el;
        return;
    }

    cout << "YES" << el;
    for (auto [x, y] : edges) {
        cout << x + 1 << ' ' << y + 1 << el;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); file();

    int t = 1; cin >> t;
    while (t--) testcase();

    return 0;
}