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
	int mx = -INF, mn = INF;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
		mn = min(mn, a[i]);
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		bool bruh = false;
		if (a[i] == mx) {
			if (i == 1) break;
			for (int j = i - 1; j >= 1; j--) {
				swap(a[j], a[j + 1]);
				++res;
			}
			bruh = true;
		}
		if (bruh) break;
	}
	
	for (int i = n; i >= 1; i--) {
		bool bruh = false;
		if (a[i] == mn) {
			if (i == n) break;
			for (int j = i + 1; j <= n; j++) {
				swap(a[j], a[j - 1]);
				++res;
			}
			bruh = true;
		}
		if (bruh) break;
	}
	
	cout << res;
	
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}

