#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "2"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=4e18,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
vector<pii>g[MAXN];
void testcase() {
    int n, m; cin >> n >> m;
    for(int u = 1; u <= m; u++) {
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    vector<int> dist1(n + 1, INF), distN(n + 1, INF), cnt1(n + 1, 0), cntN(n + 1 ,0);
    cnt1[1]=1;
    cntN[n]=1;
    {
        pqueue<pii,vector<pii>,greater<pii>>pq;
        pq.emplace(0,1);
        dist1[1]=0;
        while(pq.size()){
            auto [d, u]=pq.top();pq.pop();
            if(d>dist1[u])continue;
            for(auto&[v,w]:g[u]){
                if(dist1[v]>dist1[u]+w){
                    dist1[v]=dist1[u]+w;
                    cnt1[v]=cnt1[u];
                    pq.emplace(dist1[v],v);
                } else if(dist1[v]==dist1[u]+w)cnt1[v]+=cnt1[u];
            }
        }
    }
    {
        pqueue<pii,vector<pii>,greater<pii>>pq;
        pq.emplace(0,n);
        distN[n]=0;
        while(pq.size()){
            auto [d, u]=pq.top();pq.pop();
            if(d>distN[u])continue;
            for(auto&[v,w]:g[u]){
                if(distN[v]>distN[u]+w){
                    distN[v]=distN[u]+w;
                    cntN[v]=cntN[u];
                    pq.emplace(distN[v],v);
                } else if(distN[v]==distN[u]+w)cntN[v]+=cntN[u];
            }
        }
    }

    
    vector<int>res;
    for(int u = 1; u <= n; u++) {
        if (dist1[u] + distN[u] > dist1[n]) {
            res.push_back(u);
            continue;
        }
        int ways = cnt1[u] * cntN[u];
        if (ways < cnt1[n]) res.push_back(u);
    }
    cout << res.size() << el;
    for(auto u : res) {
        cout << u << el;
    }
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}