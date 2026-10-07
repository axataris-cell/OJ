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
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
void testcase() {
	int n, k, x; cin >> n >> k >> x;
	
	vector<bool> dp(n + 1, 0);
	dp[0] = true;
	for (int i = 1; i <= k; i++) {
		if (i == x) continue;
		for (int j = 1; j <= n; j++) {
			if (j - i >= 0) dp[j] = dp[j] || dp[j - i];
		}
	}
	if (dp[n] == false) {
		cout << "NO" << el;
		return;
	}
	
	vector<int> res;
	int cur = n;
	while (cur > 0) {
		for (int i = 1; i <= k; i++) {
			if (i == x) continue;
			if (cur - i >= 0 && dp[cur - i]) {
				res.push_back(i);
				cur -= i;
				break;
			}
		}
	}
	
	cout << "YES" << el;
	cout << res.size() << el;
	for (auto u : res) cout << u << ' ';
	
	cout << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}


