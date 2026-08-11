#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "6"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5,LOG=30,MOD=1e9+7,BASE=113;
int n=1,m=1,q=1,i=0,j=0;
vector<pii>g[MAXN];
void solve() {
	cin>>n>>m;
	for(i=1;i<=m;i++){
		int a,b,c;cin>>a>>b>>c;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}
	pqueue<pii,vector<pii>,greater<pii>>pq;
	vector<int>dist(n+1,INF),dist2(n+1,INF);
	pq.emplace(0,1);dist[1]=0;
	while(pq.size()){
		auto [d,u]=pq.top();pq.pop();
		if(d>dist2[u]){
			continue;
		}
		for(auto &[v,w]:g[u]){
			int nd=d+w;
			if (nd<dist[v]){
				dist2[v]=dist[v];
				dist[v]=nd;
				pq.emplace(dist[v],v);
				pq.emplace(dist2[v],v);
			} else if(nd>dist[v]&&nd<dist2[v]){
				dist2[v]=nd;
				pq.emplace(dist2[v],v);
			}
		}
	}
	cout<<dist2[n];
}
int32_t main() {
	fastio file();
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}