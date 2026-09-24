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
	int n, x; cin >> n >> x;
	vector<int> a(n + 1, 0);
	
	vector<pqueue<int>> pq(n + 1);
	
	vector<int> f(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f[i] = f[i - 1] + a[i];
	}
	
	for (int len = 1; len <= n; len++) {
		for (int i = 1; i + len - 1 <= n; i++) {
			pq[len].push(f[i + len - 1] - f[i - 1]);
		}
	}
	pq[0].push(0);
	
	for (int k = 0; k <= n; k++) {
		int res = 0;
		for (int len = 0; len <= n; len++) {
			res = max(res, pq[len].top() + min(k, len) * x);
		}
		
		cout << res << ' ';
	}
	cout << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}

