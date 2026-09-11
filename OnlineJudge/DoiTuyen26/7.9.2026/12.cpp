#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "12"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=4e18,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
const int MAXT = 1e8;
bool able[MAXT];
void testcase() {
    int n, T; cin >> n >> T;
    vector<int>a(n + 1, 0);
    int s = INF;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        s = min(s, a[i]);
    }
    
    vector<int> dist(s, INF);
    dist[0] = 0;
    pqueue<pii,vector<pii>,greater<pii>>pq;
    pq.emplace(0,0);
    while(pq.size()){
        auto [d,u]=pq.top();pq.pop();
        if(d>dist[u])continue;
        for(int i=  1; i <= n; i++) {
            int nxt = (a[i] + u) % s;
            if (dist[nxt] > dist[u] + a[i]) {
                dist[nxt] = dist[u] + a[i];
                pq.emplace(dist[nxt],nxt);
            }
        }
    }

    int res = 0;
    for(int i = 0; i < s; i++) {
        if (dist[i] == INF || dist[i] > T) continue;
        res += (T - dist[i]) / s + 1;
    }

    cout << res;
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}