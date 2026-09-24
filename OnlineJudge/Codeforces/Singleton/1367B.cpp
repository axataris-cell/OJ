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
	
	int cnt[2] = {0, 0};
	
	int off = 0;
	
	vector<int> a(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		++cnt[a[i] & 1];
		if ((a[i] & 1) != (i & 1)) ++off;
	}
	
	if (cnt[0] != (n + 1) / 2 || cnt[1] != n / 2) {
		cout << -1 << el;
		return;
	}
	
	cout << off / 2 << el;
	
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}

