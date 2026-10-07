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
	int s = 0;
	int cn = 0;
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		s += x;
		cn += (x == -1 ? 1 : 0);
	}
	int res = (s >= 0 ? 0 : (int)(abs(s) + 1) / 2);
	if ((res & 1) ^ (cn & 1)) ++res;
	cout << res << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}


