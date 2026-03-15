#include <bits/stdc++.h>
using namespace std;

struct Query{
    int l,r,id;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;
    cin>>n>>q;

    vector<int>a(n);
    for(int &x:a) cin>>x;

    vector<Query> qs(q);
    for(int i=0;i<q;i++){
        cin>>qs[i].l>>qs[i].r;
        qs[i].l--; qs[i].r--;
        qs[i].id=i;
    }

    int block = sqrt(n);

    sort(qs.begin(),qs.end(),[&](Query A,Query B){
        if(A.l/block != B.l/block)
            return A.l < B.l;
        return A.r < B.r;
    });

    vector<int> freq(n+1,0);
    vector<int> ans(q);

    int cur=0;
    int L=0,R=-1;

    auto add=[&](int x){
        if(x>n) return;
        if(freq[x]==x) cur--;
        freq[x]++;
        if(freq[x]==x) cur++;
    };

    auto remove=[&](int x){
        if(x>n) return;
        if(freq[x]==x) cur--;
        freq[x]--;
        if(freq[x]==x) cur++;
    };

    for(auto &qr:qs){
        while(R<qr.r) add(a[++R]);
        while(R>qr.r) remove(a[R--]);
        while(L<qr.l) remove(a[L++]);
        while(L>qr.l) add(a[--L]);

        ans[qr.id]=cur;
    }

    for(int x:ans) cout<<x<<"\n";
}