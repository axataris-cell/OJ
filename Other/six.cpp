#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 1000000007;
const int MAXK = 200005;

ll fact[MAXK],invfact[MAXK];

ll power(ll a,ll b){
    ll r=1;
    while(b){
        if(b&1) r=r*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return r;
}

void init(){
    fact[0]=1;
    for(int i=1;i<MAXK;i++)
        fact[i]=fact[i-1]*i%MOD;

    invfact[MAXK-1]=power(fact[MAXK-1],MOD-2);
    for(int i=MAXK-2;i>=0;i--)
        invfact[i]=invfact[i+1]*(i+1)%MOD;
}

ll C_large(ll n,int k){
    if(k<0||k>n) return 0;

    ll num=1;
    for(int i=0;i<k;i++)
        num=num*(n-i)%MOD;

    return num*invfact[k]%MOD;
}

struct Mat{
    ll a[3][3];
};

Mat mul(Mat A,Mat B){
    Mat C;
    memset(C.a,0,sizeof(C.a));

    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    for(int k=0;k<3;k++)
        C.a[i][j]=(C.a[i][j]+A.a[i][k]*B.a[k][j])%MOD;

    return C;
}

Mat powerMat(Mat A,long long b){
    Mat R;
    memset(R.a,0,sizeof(R.a));
    for(int i=0;i<3;i++) R.a[i][i]=1;

    while(b){
        if(b&1) R=mul(R,A);
        A=mul(A,A);
        b>>=1;
    }
    return R;
}

ll solve_sum(long long len,int target,int cnt[3]){
    Mat M;

    M.a[0][0]=cnt[0];
    M.a[0][1]=cnt[2];
    M.a[0][2]=cnt[1];

    M.a[1][0]=cnt[1];
    M.a[1][1]=cnt[0];
    M.a[1][2]=cnt[2];

    M.a[2][0]=cnt[2];
    M.a[2][1]=cnt[1];
    M.a[2][2]=cnt[0];

    Mat R=powerMat(M,len);

    return R.a[0][target];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    init();

    long long n;
    int k,X;
    cin>>n>>k>>X;

    int cnt[3]={0};

    for(int d=0;d<=9;d++){
        if(d==X) continue;
        cnt[d%3]++;
    }

    ll ans=0;

    int target=(3-(1LL*k*X)%3)%3;

    long long m=n-k;

    // Case 1: leading digit = X
    if(X!=0 && k>=1){

        ll choose=C_large(n-1,k-1);

        ll ways=solve_sum(m,target,cnt);

        ans=(ans+choose*ways)%MOD;
    }

    // Case 2: leading digit ? X
    for(int d=1;d<=9;d++){

        if(d==X) continue;

        int mod=d%3;

        int need=(target-mod+3)%3;

        ll choose=C_large(n-1,k);

        ll ways=solve_sum(m-1,need,cnt);

        ans=(ans+choose*ways)%MOD;
    }

    cout<<ans;
}