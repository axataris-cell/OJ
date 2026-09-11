#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "xayhangrao"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
void testcase() {
    int n, q; cin >> n >> q;
    vector<int> ans(n + 1, 0);
    struct Dat {int a, b;};
    vector<Dat> obj(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> obj[i].a;
    }
    for(int i = 1; i <= n; i++) cin >> obj[i].b;
    sort(obj.begin() + 1, obj.end(), [](const Dat &x, const Dat &y) {
        return x.a > y.a;
    });
    vector<int> prefBest(n + 1, 1), sufmx(n + 3, -INF), prefmn(n + 1, INF), f(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        int l = prefBest[i - 1];
        if (obj[i].b - obj[i].a > obj[l].b - obj[l].a) {
            l = i;
        }
        prefBest[i] = l;
        prefmn[i] = min(prefmn[i - 1], obj[i].a);
        f[i] = f[i - 1] + obj[i].a;
    }
    for(int i = n; i >= 1; i--) {
        sufmx[i] = max(sufmx[i + 1], obj[i].b);
    }
    for(int i = 1; i < n; i++) {
        ans[i] = max(f[i] + obj[prefBest[i]].b - obj[prefBest[i]].a, f[i] - prefmn[i] + sufmx[i + 1]);
    }
    ans[n] = f[n] + obj[prefBest[n]].b - obj[prefBest[n]].a;
    while (q--) {
        int k; cin >> k;
        cout << ans[k] << ' ';
    }
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}