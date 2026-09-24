#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME ""
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
void testcase() {
	int n; cin >> n;
	map<int, int> mp;
	int p; cin >> p;
	for (int i = 1; i <= p; i++) {
		int x; cin >> x;
		++mp[x];
	}
	int q; cin >> q;
	for (int i = 1; i <= q; i++) {
		int x; cin >> x;
		++mp[x];
	}
	cout << (mp.size() >= n ? "I become the guy." : "Oh, my keyboard!");
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}

