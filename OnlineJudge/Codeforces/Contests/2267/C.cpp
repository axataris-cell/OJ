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
const int INF=2e9,MAXN=3e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
void testcase() {
	int n, x; cin >> n >> x;
	vector<int> a(n + 1, 0);
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	int res = 0;
	
	vector<int> uoc;
	for (int i = 1; i * i <= x; i++) {
		if (x % i) continue;
		if (i != 1) uoc.push_back(i);
		if (x / i != 1) uoc.push_back(x / i);
	}
	
	sort(uoc.begin(), uoc.end());
	
	vector<bool> vis(x + 1, false);
	
	for (auto u : uoc) {
		if (vis[u]) continue;
		int cur = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] % u == 0) cur += a[i];
		}
		res = max(res, cur);
		for (int i = u * 2; i <= x; i += u) vis[u] = true;
	}
	
	cout << res << el;
	
//	vector<int> dp(x + 1, 0);
//	int res = 0;
//	
//	for (int i = 2; i <= x; i++) {
//		if (x % i) continue;
//		
//		for (int u = 1; u * u <= i; u++) {
//			if (i % u) continue;
//			dp[i] = max(dp[i], max(dp[u], dp[i / u]));
//		}	 
//		
//		dp[i] += i * mp[i];
//		
//		res = max(res, dp[i]);
//	}
//	
//	cout << res << el;
	
	
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}


