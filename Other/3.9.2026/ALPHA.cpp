#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "ALPHA"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
int power(int base, int exp) {
    int res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}
int modInverse(int n) {
    return power(n, MOD - 2);
}
void testcase() {
    string s; cin >> s;
    int n = s.length();
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'A']++;
    }
    vector<int> fact(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    int ans = fact[n];
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 1) {
            int inv = modInverse(fact[freq[i]]);
            ans = (ans * inv) % MOD;
        }
    }
    cout << ans;
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}