#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME ""
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=4e18,MAXN=2e5+5,LOG=20,MOD=1e9+7,BASE=113,BLOCK=400;
void testcase() {
	int n; cin >> n;
	map<int, int> mp;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		++mp[x];
	}
	int cnt[2]={0,0};
	for (auto &[k, v] : mp) {
		++cnt[v & 1];
	}
	cout << cnt[1] + cnt[0] - (cnt[0] & 1) << '\n';
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}



