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
	vector<vector<int>> oc(101);
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		oc[x].push_back(i);
	}
	vector<int> res;
	while (true) {
		bool changed = false;
		for (int i = 100; i >= 1; i--) {
			if (oc[i].empty()) continue;
			res.push_back(i);;
			oc[i].pop_back();
			changed = true;
		}
		if (!changed) break;
	}
	
	int s = 0;
	for (auto v : res) {
		if (v == s) {
			cout << "NO" << el;
			return;
		}
		s += v;
	}
	
	cout << "YES" << el;
	for (auto v : res) cout << v << ' ';
	cout << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}


