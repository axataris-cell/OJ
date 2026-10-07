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

int modpow(int val, int pw) {
	int res = 1;
	val %= MOD;
	for (;pw > 0; pw >>= 1) {
		if (pw & 1) {
			res = (res * val) % MOD;
		}
		val = (val * val) % MOD;
	}
	return res % MOD;
}

int modInverse(int val) {
	return modpow(val, MOD - 2);
}

void testcase() {
	int n,q ; cin >> n >> q;
	long double p; cin >> p;
	p = 1.0 - p;
	int pint = (p * 1e6); // out of 1e6
	vector<int> lamp(n + 1, 0);
	while (q--) {
		char c; cin >> c;
		if (c == '+' || c == '-') {
			int b, x; cin >> b >> x;
			if (c == '+') {
				lamp[x] = b;
			} else lamp[x] = 0;
		} else {
			int x; cin >> x;
			int res = 0;
			for (int i = 1; i <= n; i++) {
				if (lamp[i]) {
					int dist = abs(x - i);
					res += (lamp[i] * modpow(pint, dist) * modpow(modInverse(1e6), dist));
					res %= MOD;					
				}
			}
			cout << res % MOD << el;
		}
	}
}

/*
5 6 0.25
+ 4 2
? 1
? 2
? 3
? 4
? 5
*/

int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}


