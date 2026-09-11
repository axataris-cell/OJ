#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "AUTOMAT"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
int a[MAXN];
int K;
struct Node{
    int cnt[20], lz[20];
    bool hslz;
    Node() {
        for(int i =0 ;i < 20; i++){
            cnt[i]=0;
            lz[i]=i;
        }
        hslz=false;
    }
};
vector<Node> ST(4 * MAXN + 1,Node());
inline void pull(int id) {
    for (int i = 0; i < K; i++) {
        ST[id].cnt[i] = ST[id << 1].cnt[i] + ST[id << 1 | 1].cnt[i];
    }
}
void build(int id, int l, int r) {
    if (l == r) {
        ++ST[id].cnt[a[l]];
        return;
    }
    int mid = (l + r) / 2;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    pull(id);
}
void apply(int id, int mp[]) {
    int nxt[K]={0};
    for(int i = 0; i < K; i++) {
        nxt[mp[i]] += ST[id].cnt[i];
    }
    for(int i =0; i < K; i++) {
        ST[id].cnt[i] = nxt[i];
        ST[id].lz[i] = mp[ST[id].lz[i]];
    }
    ST[id].hslz = true;
}
void push(int id, int l, int r) {
    if(!ST[id].hslz) return;
    apply(id << 1, ST[id].lz);
    apply(id << 1 | 1, ST[id].lz);
    for(int i = 0; i < K; i++) ST[id].lz[i] = i;
    ST[id].hslz= false;
}
void updateSet(int id, int l, int r, int ql, int qr, int v1, int v2) {
    if (l > qr || r < ql) return;
    if (ST[id].cnt[v1] == 0) return;
    if (ql <= l && r <= qr) {
        int mapping[K];
        for (int i = 0; i < K; i++) mapping[i] = i;
        mapping[v1] = v2;
        apply(id, mapping);
        return;
    }
    int mid = (l + r) / 2;
    push(id, l, r);
    updateSet(id << 1, l, mid, ql, qr, v1, v2);
    updateSet(id << 1 | 1, mid + 1, r, ql, qr, v1, v2);
    pull(id);
}
int query(int id, int l, int r, int pos) {
    if (l == r) {
        for(int i = 0; i < K; i++) if (ST[id].cnt[i]){
            return i;
        }
    }
    int mid = (l + r) / 2;
    push(id, l, r);
    if (pos <= mid) return query(id << 1, l, mid, pos);
    else return query(id << 1 | 1, mid + 1, r, pos);
}
void testcase() {
    int n, q;
    cin >> n >> K >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while(q--) {
        int l, r, x, y; cin >> l >> r >> x >> y;
        updateSet(1, 1, n, l, r, x, y);
    }
    for(int i = 1; i <= n; i++) cout << query(1, 1, n, i) << ' ';
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}