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
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=10000,BASE=113,BLOCK=400;
int modpow(int base, int pw) {
	int res = 1;
	for (; pw > 0; pw >>= 1) {
		if (pw & 1) {
			res *= base;
			res %= MOD;
		}
		base = (base * base) % MOD;
	}
	return res % MOD;
}
void testcase() {
	int n; cin >> n;
	cout << modpow(5, n) % 100;
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}

