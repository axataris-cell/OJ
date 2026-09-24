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
	int n; cin >> n;
	vector<int> a(n + 1, 0);
	vector<int> mark(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	for (int i = 1; i <= n; i++) {
		int l = min(a[i] * i, n);
		int r = min((a[i] + 1) * i - 1, n - 1);
		if (l > n - 1 || l > r) continue;
		mark[l]++;
		mark[r + 1]--;
	}
	
	int cur = 0;	
	vector<int> res;
	for (int i = 0; i <= n - 1; i++) {
		cur += mark[i];
		if (cur == 0) res.push_back(i);
	}
	
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

