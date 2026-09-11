#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "XORQUERY"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=20,MOD=1e9+7,BASE=113,BLOCK=400;

int ST[4 * MAXN][LOG];
int lz[4 * MAXN];

void apply(int id, int len, int x) {
    lz[id] ^= x;
    for (int i = 0; i < LOG; i++) {
        if ((x >> i) & 1) {
            ST[id][i] = len - ST[id][i];
        }
    }
}

void push(int id, int l, int r) {
    if (!lz[id]) return;
    int mid = (l + r) / 2;
    apply(id << 1, mid - l + 1, lz[id]);
    apply(id << 1 | 1, r - mid, lz[id]);
    lz[id] = 0;
}

void combine(int id) {
    for (int i = 0; i < LOG; i++) {
        ST[id][i] = ST[id << 1][i] + ST[id << 1 | 1][i];
    }
}

void build(int id, int l, int r, const vector<int>& a) {
    lz[id] = 0;
    if (l == r) {
        for (int i = 0; i < LOG; i++) {
            ST[id][i] = (a[l] >> i) & 1;
        }
        return;
    }
    int mid = (l + r) / 2;
    build(id << 1, l, mid, a);
    build(id << 1 | 1, mid + 1, r, a);
    combine(id);
}

void update(int id, int l, int r, int ql, int qr, int x) {
    if (ql <= l && r <= qr) {
        apply(id, r - l + 1, x);
        return;
    }
    push(id, l, r);
    int mid = (l + r) / 2;
    if (ql <= mid) update(id << 1, l, mid, ql, qr, x);
    if (qr > mid) update(id << 1 | 1, mid + 1, r, ql, qr, x);
    combine(id);
}

int query(int id, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        int sum = 0;
        for (int i = 0; i < LOG; i++) {
            sum += ST[id][i] * (1LL << i);
        }
        return sum;
    }
    push(id, l, r);
    int mid = (l + r) / 2;
    int res = 0;
    if (ql <= mid) res += query(id << 1, l, mid, ql, qr);
    if (qr > mid) res += query(id << 1 | 1, mid + 1, r, ql, qr);
    return res;
}

void testcase() {
    int n; cin >> n;
    
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    build(1, 1, n, a);

    int q; cin >> q;
    while (q--) {
        int t; cin >> t;
        if (t == 0) {
            int l, r, x; 
            cin >> l >> r >> x;
            update(1, 1, n, l, r, x);
        } else {
            int l, r; 
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << el;
        }
    }
}

int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}