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
// Created: 2026-04-01 10:20

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "xola"

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
const int maxn = 1e5 + 5;
bool vis[maxn];
vector <int> g[maxn];
vector <int> tplt;
void dfs (int s){
    vis[s] = true;
    tplt.push_back(s);
    for (auto x : g[s]){
        if (!vis[x]) dfs(x);
    }
}
void testcase() {
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if (!vis[i]){
            cnt++;
            dfs(i);
        }
    }
    cout << cnt << '\n';
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++){
        if (!vis[i]){
            tplt.clear();
            dfs(i);
            cout << tplt.size() << ' ';
            for (auto x : tplt) cout << x << ' ';
            cout << '\n';
        }
        
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