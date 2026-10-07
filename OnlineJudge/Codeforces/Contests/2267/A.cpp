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
	char c ; cin >> c;
	string s; cin >> s;
	int i = 0; int j = n - 1;
	int res = 0;
	while (i <= j) {
		if (s[i] != s[j]) {
			res += (s[i] != c ? 1 : 0) + (s[j] !=  c? 1 : 0);
		}
		++i;
		--j;
	}
	cout << res << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}

