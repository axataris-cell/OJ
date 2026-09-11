#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "K"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5,LOG=30,MOD=1e9+7,BASE=113;

const int BLOCK = 400;
int n=1,m=1,q=1,i=0,j=0;
int color[MAXN];
vector<int> g[MAXN];

int timeDfs =0;
int tin[MAXN],tout[MAXN];
int at[MAXN];

int mp[MAXN],f[MAXN];
void dfs(int u, int p) {
    tin[u]=++timeDfs;
    at[timeDfs]=u;
    for(int v : g[u]) {
        if(v==p)continue;
        dfs(v,u);
    }
    tout[u]=timeDfs;
}
void solve() {
    cin >> n >> q;
    for(int i =1 ; i<= n;i++) cin >> color[i];
    for(int i =1 ; i < n; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,1);
    struct Query{int l,r,k, id;};
    vector<Query>queries;
    for(int i =1 ; i <= q;i++) {
        int v, k;cin>>v >>k;
        int l = tin[v], r= tout[v];
        queries.push_back({l,r,k,i});
    }
    sort(queries.begin(),queries.end(),[](const Query&x,const Query&y) {
        if (x.l/BLOCK != y.l/BLOCK) {
            return x.l/BLOCK < y.l/BLOCK;
        }
        if ((x.l / BLOCK) & 1) return x.r < y.r;
        else return x.r>y.r;
    });
    vector<int>ans(q+1,0);
    int L = 1,R=0;
    auto add=[&](int pos){
        int v=at[pos];
        ++mp[color[v]];
        f[mp[color[v]]]++;
    };
    auto remove=[&](int pos){
        int v=at[pos];
        --f[mp[color[v]]];
        --mp[color[v]];
    };
    for (auto &[l, r, k, id]: queries) {
        while (L > l) {
            --L;
            add(L);
        }
        while (R < r) {
            ++R;
            add(R);
        }
        while (L < l) {
            remove(L);
            ++L;
        }
        while (R > r) {
            remove(R);
            --R;
        }
        ans[id]=f[k];
    }

    for(int i =1 ; i <= q;i++) {
        cout << ans[i]<<el;
    }
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}