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
	vector<int> t(n + 1, 0);
	vector<vector<int>> c(4);
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
		c[t[i]].push_back(i);
	}
	
	int mx_sz = min({(int)c[1].size(), (int)c[2].size(), (int)c[3].size()});
	
	if (mx_sz == 0) {
		cout << 0 << el;
		return;
	}
	
	cout << mx_sz << el;
	for (int i = 0; i < mx_sz; i++) {
		cout << c[1][i] << ' ' << c[2][i] << ' ' << c[3][i] << el;
	}
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}

