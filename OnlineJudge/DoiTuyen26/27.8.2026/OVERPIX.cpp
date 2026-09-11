#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "OVERPIX"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
int a[MAXN], pos[MAXN];
int ST[LOG][MAXN];
void pre(int n) {
    for(int i = 1; i <= n; i++) ST[0][i] = a[i];
    for(int l = 1; l < LOG; l++) {
        for(int i= 1; i + (1 << l) - 1 <= n; i++) {
            ST[l][i] = max(ST[l - 1][i], ST[l - 1][i + (1 << (l - 1))]);
        }
    }
}
int query(int l, int r) {
    int k = __lg(r - l + 1);
    return max(ST[k][l], ST[k][r - (1 << k) + 1]);
}
int solve(int l, int r) {
    if (l == r) return 0;
    int cnt =0;
    int mid = (l + r) / 2;
    // max nam trai
    for(int i = mid; i >= l; i--) {
        int mx = query(i, mid);
        int target = mx - a[i];
        if (target <= 0 || pos[target] <= mid || pos[target] > r || query(i, pos[target]) != mx) {
            continue;
        }
        ++cnt;
    }
    // haoi
    for(int i = mid + 1; i <= r; i++) {
        int mx = query(mid + 1, i);
        int target = mx - a[i];
        if (target <= 0 || pos[target] < l || pos[target] > mid || query(pos[target], i) != mx) {
            continue;
        }
        ++cnt;
    }
    return cnt + solve(l, mid) + solve(mid + 1, r);
}
void testcase() {
    int n; cin >> n;
    for(int i = 1;i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    pre(n);
    cout << solve(1, n);
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}