#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "MAJORNUM"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=3e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
int a[MAXN];
vector<int> pos[MAXN];
struct Segtree{
    vector<int> ST;
    Segtree(int n):ST(4*n + 1,0){}
    void update(int id, int l, int r, int pos, int val) {
        if (l == r) {
            ST[id]+=val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)update(id << 1, l, mid,pos,val);
        else update(id <<1|1,mid+1,r,pos,val);
        ST[id]=ST[id<<1]+ST[id<<1|1];
    }
    int query(int id, int l, int r, int ql, int qr) {
        if (l > qr || r < ql) return 0;
        if (ql <= l && r <= qr) {
            return ST[id];
        }
        int mid = (l +r)/2;
        return query(id<<1,l,mid,ql,qr)+query(id<<1|1,mid+1,r,ql,qr);
    }
};
void testcase() {
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    int res =n;
    for(int val= 1; val <= n; val++) {
        if (!pos[val].size()) continue;
        auto &v = pos[val];
        vector<int>comp;
        for(int i =0;i<v.size();i++){
            comp.push_back(2*i-v[i]);
        }
        sort(comp.begin(),comp.end());
        comp.erase(unique(comp.begin(),comp.end()),comp.end());
        int m = comp.size();
        Segtree ST(m);
        for(int i=0;i<v.size();i++){
            int find=lower_bound(comp.begin(),comp.end(),2*i-v[i])-comp.begin();
            res+=ST.query(1,0,m-1,0,find);
            ST.update(1,0,m-1,find,1);
        }
    }
    cout<<res;
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}