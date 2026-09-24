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

int spf[MAXN], C[MAXN];
vector<int> divs[MAXN];

void pre() {
    for (int i = 2; i < MAXN; i++) spf[i] = i;
    for (int i = 2; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }

    C[1] = 0;
    for (int i = 2; i < MAXN; i++) {
        int p = spf[i];
        C[i] = 1 + p * C[i / p];
    }

    for (int i = 1; i < MAXN; i++) {
        for (int j = i; j < MAXN; j += i) {
            divs[j].push_back(i);
        }
    }
}

void testcase() {
	int n, k; cin >> n >> k;
	
	vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> memo(n + 1, -1);
    int res = 0;

    for (int x : a) {
        if (x <= k) continue;

        if (memo[x] != -1) {
            res += memo[x];
            continue;
        }

        int mn = INF;

        for (int d : divs[x]) {
            if (d >= (x + k - 1) / k) {
                mn = min(mn, C[d]);
            }
        }

        memo[x] = mn;
        res += mn;
    }

    cout << res << el;
}
int32_t main() {
    fastio file();
    
    pre();
    
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}

