#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define endl "\n"
#define ft first
#define sc second

ll mod = 1e9+7;

ll n, m, k;

ll available[1000006];
ll uocm[1000006];
ll uocn[1000006];

void sieve(){
    for (ll i=1;i<=k;i++){
        for (ll j=i;j<=k;j+=i){
            if (i <= m) uocm[j]++;
            if (i <= n) uocn[j]++;	
        }
    }
}

void cal(){
    for (ll i=1;i<=k;i++){
        available[i]=(uocm[i]*uocn[i])%mod;
    }
}

void reset(){
    for (ll i=1;i<=k;i++){
        available[i]=0;
        uocm[i]=0;
        uocn[i]=0;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    reset();
    sieve();
    cal();

    ll ans = 0;
    for (ll i=1;i<=k;i++){
        ans=(ans+(available[i]%mod)*i)%mod;
    }

    cout << ans;

    return 0;
}