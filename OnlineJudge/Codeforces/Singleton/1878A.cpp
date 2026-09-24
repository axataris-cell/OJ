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
	int n, k; cin >> n >> k;
	vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		map<int, int> mp;
		for (int j = i; j <= n; j++) {
			++mp[a[j]];
			bool ok = true;
			int cnt = mp[k];
			if (cnt <= 0) continue;
			for (auto &p : mp) {
				int ke = p.first, v = p.second;
				if (ke == k) continue;
				if (v >= cnt) {
					ok = false;
					break;
				}
			}
			if (ok) {
				cout << "YES" << el;
				return;
			}
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

