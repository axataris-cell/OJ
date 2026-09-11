#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define int long long
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "G"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
void testcase() {
    int n, k; 
    cin >> n >> k;
    vector<int> a(n + 1, 0), diff(n + 1, 0);
    vector<int> inv(n + 1, 0), finv(n + 1, 0);
    vector<int> fG(n + 1, 0);

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 2; i <= n; i++) {
        diff[i] = a[i] - a[i - 1];
        inv[i] = k - diff[i];
        finv[i] = finv[i - 1] + inv[i];
        fG[i] = fG[i - 1] + i * inv[i];
    }

    vector<int> res(n + 1, 0);

    for(int i = 2; i < n; i++) {
        int tot = diff[i] + diff[i + 1];
        if (tot <= k) continue;
        int D = tot - k;

        int idx = i + 1;
        auto it = lower_bound(finv.begin() + idx, finv.begin() + n + 1, finv[idx] + D);
        int r = (it - finv.begin()) - 1;
        int cap = finv[r] - finv[idx];
        int S = (fG[r] - fG[idx]) - idx * cap;
        int rem = D - cap;
        
        res[i] = S + rem * (r - i);
    }

    for(int i = 1; i <= n; i++) {
        cout << res[i] << ' ';
    }
    cout << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}