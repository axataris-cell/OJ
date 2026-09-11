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
// Created: 2026-06-08 15:52

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "9"

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

const int MAXN = 2e5 + 5;

int n, k;

vector<int> g[MAXN];
int sz[MAXN];

bool del[MAXN];
int curres=INF;
int cnt=0;

void dfs(int u, int p, int curx) {
    sz[u]=1;
    for(int v:g[u]){
        if(v==p)continue;
        dfs(v,u,curx);
        if (sz[v] >= curx) {
            del[v]=true;
            ++cnt;
            continue;
        }
        sz[u]+=sz[v];
    }
}

void testcase() {
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int l=1, r=n;
    int res=1;
    int debug=1;
    while (l<=r){
        int mid= (l+r)/2;
        cnt=0;
        for(int i=1;i<=n;i++)del[i]=false;
        dfs(1,1,mid);
        curres=sz[1];
        for(int i=1;i<=n;i++){
            if (del[i])curres=min(sz[i],curres);
        }
        if(cnt>=k){
            res=mid;
            // cout<<mid<<el;
            // for(int i=1;i<=n;i++)cout<< sz[i]<<' ';
            // cout<<el;
            debug=curres;
            l=mid+1;
        } else r=mid-1;
    }
    cout<<debug;
    // cout<<res;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}