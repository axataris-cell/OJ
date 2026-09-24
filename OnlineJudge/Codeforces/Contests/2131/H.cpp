#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "H"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
const int MAXM = 1e6 + 5;
int spf[MAXM];
void sieve() {
    for(int i = 2; i < MAXM; i++) spf[i] = i;
    for(int i = 2; i * i < MAXM; i++) {
        if (spf[i] == i) {
            for(int j = i; j < MAXM; j += i) {
                spf[j] = i;
            }
        }
    }
}
vector<int> factor(int n) {
    vector<int> f;
    while (n > 1) {
        int cur = spf[n];
        f.push_back(cur);
        while (n > 1 && n % cur == 0) {
            n /= cur;
        }
    }
    sort(f.begin(), f.end());
    return f;
}
vector<int> divs[MAXN];
void testcase() {
    int n, m; cin >> n >> m;
    vector<int> a(n + 1, 0);
    vector<int> divisible(m + 1, 0);
    vector<int> deg(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        divs[i] = factor(a[i]);
        for(int j = a[i]; j <= m; j+= a[i]) divisible[j]++;
    }
    for(int _ = 1; _ <= n; _++) {
        int sz = divs[_].size();
        for(int mask = 1; mask < (1 << sz); mask++) {
            int cur = 1;
            for (int i = 0; i < sz; i++) {
                if ((mask >> i) & 1) cur *= divs[_][i];
            }
            int cnt = __builtin_popcount(mask);
            if (cnt & 1) deg[_] += divisible[cur];
            else deg[_] -= divisible[cur]; 
        }
    }
    for(int i = 1; i <= n; i++) deg[i] = n - deg[i] - (a[i] == 1);
    int mxnode = 1;
    for(int i = 1; i <= n; i++) {
        if (deg[i] > deg[mxnode]) {
            mxnode = i;
        }
    }
    int mnnode = -1;
    for(int i = 1; i <= n; i++) {
        if (i == mxnode) continue;
        if (__gcd(a[i], a[mxnode]) == 1) {
            --deg[i];
            if (mnnode == -1) {
                mnnode = i;
            } 
            if (deg[mnnode] > deg[i]) mnnode = i;
        }
    }
    if (mnnode == -1) {
        cout << 0 << el;
        return;
    }
    for(int i =1; i <= n; i++) {
        if (i == mnnode) continue;
        if (__gcd(a[i], a[mnnode]) == 1) --deg[i];
    }

    for(int i = 1; i <= n; i++) {
        if (i == mnnode || i == mxnode) continue;
        if (deg[i]) {
            for(int j = 1; j <= n; j++) {
                if (i == j || j == mxnode || j == mnnode) continue;
                if (__gcd(a[i], a[j]) == 1) {
                    cout << mxnode << ' ' << mnnode << ' ' << i << ' ' << j << el;
                    return;
                }
            }
        }
    }
    cout << 0 << el;
}
int32_t main() {
    fastio file();
    sieve();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}