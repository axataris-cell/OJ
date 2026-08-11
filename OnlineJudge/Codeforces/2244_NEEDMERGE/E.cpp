#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "E"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5,LOG=30,MOD=1e9+7,BASE=113;
int n=1,m=1,q=1,i=0,j=0;
void solve() {
    cin>>n>>q;
    string s;cin>>s;
    s=' '+s;
    struct segment{int l,r;};
    vector<segment>comp;
    for(i=1;i<=n;i){
        j=i;
        int cur=s[i]-'0';
        while(j<=n&&s[j]-'0'==cur){++j,cur^=1;}
        comp.push_back({i,j-1});
        i=j;
    }

    m=comp.size();
    auto bsr=[&](int pos)->int{
        int l=0,r=m-1;
        int res=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(comp[mid].l>pos){
                r=mid-1;
            } else{l=mid+1,res=mid;}
        }
        return res;
    };
    auto bsl=[&](int pos)->int{
        int l=0,r=m-1;
        int res=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(comp[mid].l>pos){
                r=mid-1;
            } else {l=mid+1;res=mid;}
        }
        return res;
    };
    // cout<<bsl(1)<<' '<<bsr(5)<<el;
    // return;
    while(q--){
        int l,r,k;cin>>l>>r>>k;
        r=bsr(r);
        l=bsl(l);
        int len=r-l+1;
        cout<<(len/2>k?"NO":"YES")<<el;
    }
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}