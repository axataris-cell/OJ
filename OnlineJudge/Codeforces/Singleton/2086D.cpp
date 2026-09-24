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
const int INF=2e9,MAXN=5e5+5,LOG=30,MOD=998244353,BASE=113,BLOCK=400;
int modpow(int val, int pw) {
	int res = 1;
	while (pw > 0) {
		if (pw & 1) res = (res * val) % MOD;
		val = (val * val) % MOD;
		pw >>= 1;
	}
	return res % MOD;
}
int invFact(int val) {
	int res = 1;
	for (int i = 1; i <= val; i++) {
		res *= i;
		res %= MOD;
	}
	return modpow(res, MOD - 2);
}
int fact(int val) {
	int res = 1;
	for (int i = 1; i <= val; i++) {
		res *= i;
		res %= MOD;
	}
	return res;
}
void testcase() {
	vector<int> c(26, 0);
	int n = 0;
	for (int i = 0; i < 26; i++) {
		cin >> c[i];
		n += c[i];
	}
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < 26; i++) {
		if (c[i] == 0) continue;
		for (int j = n; j >= 0; j--) {
			if (j - c[i] >= 0) {
				dp[j] += dp[j - c[i]];
				dp[j] %= MOD;
			}
		}
	}
	int r1 = fact(n / 2) * fact((n + 1) / 2) % MOD;
	for (int i = 0; i < 26; i++) {
		r1 *= invFact(c[i]);
		r1 %= MOD;
	}
	r1 *= dp[(n + 1) / 2];
	cout << r1 % MOD << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}

