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
struct DAT {
    int l, r;
    bool operator<(const DAT& other) const {
        if (l != other.l) return l < other.l;
        return r > other.r;
    }
};
void testcase() {
    int n; cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> mark(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		int l = min(a[i] * i, n);
		int r = min((a[i] + 1) * i - 1, n - 1);
		if (l > n - 1 || l > r) continue;
		mark[l]++;
		mark[r + 1]--;
	}

    vector<bool> cam(n, false);
    int curr = 0;
    for (int i = 0; i < n; i++) {
        curr += mark[i];
        if (curr > 0) {
            cam[i] = true;
        }
    }

    int a1 = a[1];
    vector<int> free;
    for (int i = a1; i < n; i++) {
        if (!cam[i]) {
            free.push_back(i);
        }
    }

    int p = free.size(); // say wallahi
    if (p == 0) {
        cout << 1 << el;
        return;
    }

    vector<int> f(n, 0);
    int ptr = 0;
    for (int i = 0; i < n; i++) {
        if (ptr < p && free[ptr] == i) {
            ptr++;
        }
        f[i] = ptr;
    }

    vector<DAT> inter;
    for (int k = 1; k <= n; k++) {
        int m0 = (a1 == 0) ? 0 : (a1 - 1) / k + 1;
        for (int m = m0; m < a[k]; m++) {
            int L = m * k;
            if (L >= n) break;  
            int R = min(n - 1, L + k - 1);
            
            int l = (L > 0 ? f[L - 1] : 0) + 1;
            int r = f[R];
            if (l <= r) {
                inter.push_back({l, r});
            }
        }
    }

    sort(inter.begin(), inter.end());

    vector<DAT> st;
    for (const auto& iv : inter) {
        while (!st.empty() && st.back().r >= iv.r) {
            st.pop_back();
        }
        st.push_back(iv);
    }

    vector<int> req(p + 1, 0);
    for (auto [l, r] : st) {
        req[r] = l;
    }

    vector<int> dp(p + 1, 0);
    dp[0] = 1;
    int S = 1;
    int l = 0;

    for (int x = 1; x <= p; x++) {
        dp[x] = S;
        S = (S + dp[x]) % MOD;
        while (l < req[x]) {
            S = (S - dp[l] + MOD) % MOD;
            l++;
        }
    }

    cout << S << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}