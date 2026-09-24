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
	if (k < n || k == 2 * n) {
		cout << -1 << el;
		return;
	}
	vector<vector<int>> res(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++) {
		res[i][i] = i;
	}
	int cnt = n + 1;
	if (k > n) {
		for (int i = 2; i <= n; i++) {
			res[i][1] = i;
			res[i][i] = cnt;
			++cnt;
			if (cnt > k) break;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (res[i][j] == 0) res[i][j] = cnt++;
			cout << res[i][j] << ' ';
		}
		cout << el;
	}
	
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}

