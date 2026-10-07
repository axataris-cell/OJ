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
void testcase() {
	int x[3] = {0, 0, 0}; for (int i = 0; i < 3; i++) cin >> x[i];
	sort(x, x + 3, greater<int>());
	if (x[0] != x[1]) {
		cout << "NO" << el;
		return;
	}
	cout << "YES" << el;
	cout << x[0] << ' ' << x[2] << ' ' << 1 << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}


