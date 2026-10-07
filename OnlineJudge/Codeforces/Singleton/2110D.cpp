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

vector<pii> g[MAXN];
int b[MAXN];

void testcase() {
	int n, m; cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		g[i].clear();
	}
	
	for (int i = 1; i <= n; i++) cin >> b[i];	
	for (int i = 1; i <= m; i++) {
		int a, b, w; cin >> a >> b >> w;
		g[a].push_back({b, w}); // again
	}
	
	auto check = [&](int val) -> bool {
		vector<int> dp(n + 1, 0);
		
		for (int i = 1; i <= n; i++) {
			if (i > 1 && dp[i] == 0) {
				continue;
			}
			dp[i] += b[i];
			dp[i] = min(dp[i], val);
			for (auto p : g[i]) {
				int v=p.first, w=p.second;
				if (w <= dp[i]) {
					dp[v] = max(dp[v], dp[i]);
				}
			}
		}
		return dp[n] > 0;
	};
	
	if (!check(INF)) {
		cout << -1 << el;
		return;
	}
	
	int l = 0, r = INF;
	int res = INF;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			res = mid;
			r = mid - 1;
		} else l = mid + 1;
	}
	
	cout << res << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}


