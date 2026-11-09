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

string BIT(int x) {
	string res = "";
	while (x > 0) {
		if (x & 1) res = "1" + res;
		else res = "0" + res;
		x >>= 1;
	}
	return res;
}

void testcase() {
	int n; cin >> n;
	vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; i++) cin >> a[i];
	
}
int32_t main() {
    fastio file();
    
//    cout << BIT(5523 - 4);
//    return 0;
    
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}



