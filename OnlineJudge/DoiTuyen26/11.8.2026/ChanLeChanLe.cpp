#include <bits/stdc++.h>
#define int long long
#define el '\n'
#define FILENAME "ChanLeChanLe"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5,LOG=30,MOD=1e9+7,BASE=113;
int n=1,m=1,q=1,i=0,j=0;
using namespace std;
struct Segtree{
    vector<int>ST;
    Segtree(int n):ST(4*n+1,0){}
    void update(int id,int l, int r,int pos,int val){
        if(l==r){
            ST[id]+=val;
            return;
        }
        int mid=(l+r)/2;
        if(pos<=mid)update(id<<1,l,mid,pos,val);
        else update(id<<1|1,mid+1,r,pos,val);
        ST[id]=ST[id<<1]+ST[id<<1|1];
    }
    int query(int id, int l,int r, int ql, int qr){
        if(l>qr||r<ql)return 0;
        if(ql<=l&&r<=qr){
            return ST[id];
        }
        int mid=(l+r)/2;
        return query(id<<1,l,mid,ql,qr)+query(id<<1|1,mid+1,r,ql,qr);
    }
};
void solve() {
    cin>>n>>m;
    vector<int>a(n+1,0);
    for(i=1;i<=n;i++)cin>>a[i];
    vector<vector<int>>f(2,vector<int>(n+1,0));
    for(i=1;i<=n;i++){
        f[0][i]=f[0][i-1];
        f[1][i]=f[1][i-1];
        if(a[i]&1){f[1][i]+=a[i];}
        else {f[0][i]+=a[i];}
    }
    auto getf=[&](int l,int r,int p)->int{
        return f[p][r]-f[p][l-1];
    };

    vector<int>comp;
    for(i=0;i<=n;i++){
        comp.push_back({f[1][i]-f[0][i]});
    }
    sort(comp.begin(),comp.end());
    comp.erase(unique(comp.begin(),comp.end()),comp.end());
    auto getid=[&](int val)->int{
        return lower_bound(comp.begin(),comp.end(),val)-comp.begin();
    };
    int k=comp.size();
    Segtree ST(k+1);

    int p=0;
    int lodd=0,leven=0;
    int res=0;
    for(i=1;i<=n;i++){
        if(a[i]&1)lodd=i;
        else leven=i;
        int lim=min(lodd,leven);
        while(p<lim){
            int id=getid(f[1][p]-f[0][p]);
            ST.update(1,0,k-1,id,1);
            ++p;
        }
        if(lim>0){
            int l=lower_bound(comp.begin(),comp.end(),f[1][i]-f[0][i])-comp.begin();
            int r=upper_bound(comp.begin(),comp.end(),f[1][i]-f[0][i]+m)-comp.begin()-1;
            if(l<=r&&r>=0)res+=ST.query(1,0,k-1,l,r);
        }
    }
    cout<<res;
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}