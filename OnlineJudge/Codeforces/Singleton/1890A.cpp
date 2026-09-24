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
	vector<int> a(n + 1, 0);
	map<int, int> mp;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		++mp[a[i]];
	}
	
	if (mp.size() > 2) {
		cout << "NO" << el;
		return;
	}
	
	if (mp.size() == 1) {
		cout << "YES" << el;
		return;
	}
	
	for (auto &p : mp) {
		int v = p.second;
		if (v == n / 2) {
			cout << "YES" << el;
			return;
		}
	}
	
	cout << "NO" << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}

