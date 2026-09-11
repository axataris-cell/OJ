#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define ft first
#define sc second
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back

void file(){
    if (fopen("AVG.INP","r")){
       freopen("AVG.INP","r",stdin);
       freopen("AVG.OUT","w",stdout);
    }
}

const int N = 1e5+5;

int n, L;

ld ans = 0;

ld a[N], pref[N], b[N];

bool check(ld mid){
    for (int i=0;i<=n;i++){
        b[i] = pref[i] - mid * i;
    }

    ld mn = 0;

    for (int i=L;i<=n;i++){
        if (b[i] - mn >= 0) return true;

        mn = min(mn, b[i-L+1]);
    }
    
    return false;
}

void solve(){
    cin >> n >> L;

    pref[0] = 0;

    for (int i=1;i<=n;i++){
        cin >> a[i];

        pref[i] = pref[i-1] + a[i];
    }

    ld l = -1e9, r = 1e9;

    while ((r - l) > 1e-7){
        ld mid = (l + r) / 2;

        if (check(mid)){
            ans = mid;
            l = mid + 1e-7;
        } else r = mid - 1e-7;
    }

    cout << fixed << setprecision(6) << ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    file();

    solve();

    return 0;
}