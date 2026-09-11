#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "FLIGHT"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
struct Segtree {
    vector<int> ST;
    Segtree(int n) : ST(4 * n + 1, 0) {}
    void update(int id, int l, int r, int pos, int val) {
        if (l == r) {
            ST[id] = max(ST[id], val);
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) update(id << 1, l, mid, pos, val);
        else update(id << 1 | 1, mid + 1, r, pos, val);
        ST[id] = max(ST[id << 1], ST[id << 1 | 1]); 
    }
    int query(int id, int l, int r, int ql, int qr) {
        if (l > qr || r < ql) return -INF;
        if (ql <= l && r <= qr) return ST[id];
        int mid = (l + r) / 2;
        return max(query(id<<1,l,mid,ql,qr),query(id<<1|1,mid+1,r,ql,qr));
    }
}; 
void testcase() {
    int n; cin >> n;
    vector<int>b(n+1,0),l(n+1,0);
    for(int i = 1; i <= n; i++) cin >> b[i];

    vector<int>comp;
    for(int i = 1; i <= n; i++) {
        cin >> l[i];
        comp.push_back(l[i]);
    }
    sort(comp.begin(),comp.end());
    comp.erase(unique(comp.begin(),comp.end()),comp.end());
    auto get_id=[&](int val)->int {
        return lower_bound(comp.begin(),comp.end(),val)-comp.begin();
    };

    int m = comp.size();
    Segtree ST(m);

    vector<int> dp(n + 1, 0);
    int res=0;
    for(int i = 1; i <= n; i++) {
        int id = get_id(l[i]);
        dp[i] = (id==0?0:ST.query(1, 0, m - 1, 0, id - 1)) + b[i];
        ST.update(1,0,m-1,id,dp[i]);
        res=max(res,dp[i]);
    }

    cout << res;

}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}