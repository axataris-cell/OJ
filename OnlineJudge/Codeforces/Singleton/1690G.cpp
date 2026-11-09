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

struct Node {
    int mn, mx, lz, tr, lval, rval;
};
int n, m;
vector<Node> ST;

void apply(int id, int v, int len) {
    ST[id].mn = ST[id].mx = ST[id].lz = ST[id].lval = ST[id].rval = v;
    ST[id].tr = 0;
}

void push(int id, int l, int r) {
    if (ST[id].lz == -1) return;
    int mid = (l + r) / 2;

    apply(id << 1, ST[id].lz, mid - l + 1);
    apply(id << 1| 1, ST[id].lz, r - mid);
    ST[id].lz = -1;
}

Node merge(const Node &l, const Node &r) {
    Node res;
    res.mn = min(l.mn, r.mn);
    res.mx = max(l.mx, r.mx);
    res.lz = -1;
    res.lval = l.lval;
    res.rval = r.rval;
    res.tr = l.tr + r.tr + (r.lval < l.rval ? 1 : 0);
    return res;
}

void build (int id, int l, int r, vector<int> &b) {
    ST[id].lz = -1;
    if (l == r) {
        ST[id] = {b[l], b[l], -1, 0, b[l], b[l]};
        return;
    }
    int mid = (l + r) / 2;
    build(id << 1 , l, mid, b);
    build(id << 1 | 1, mid + 1, r, b);
    ST[id] = merge(ST[id << 1] , ST[id << 1 | 1]);
}

void update(int id, int l, int r, int ql, int qr, int v) {
    if (l > qr || r < ql || ST[id].mx <= v) return;
    if (ql <= l && r <= qr && ST[id].mn >= v) {
        apply(id, v, r - l + 1);
        return;
    }
    int mid = (l + r) / 2;
    push(id, l, r);
    update(id << 1, l, mid, ql, qr, v);
    update(id << 1 | 1, mid + 1, r, ql, qr, v);
    ST[id] = merge(ST[id << 1] , ST[id << 1 | 1]);
}


void testcase() {
    cin >> n >> m;
    vector<int> a(n + 1, 0);
    vector<int> b(n + 1, INF);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = min(b[i - 1], a[i]);
    }

    ST.resize(4 * n + 1);
    build(1, 1, n, b);

    while (m--) {
        int k, d; cin >> k >> d;
        a[k] -= d;
        update(1, 1, n, k, n, a[k]);
        cout << ST[1].tr + 1 << ' ';
    }

    cout << el;

}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}