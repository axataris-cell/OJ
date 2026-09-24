#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "D"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
void testcase() {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    vector<pii> comp;
    for(int l = 1; l <= n;) {
        int r = l + 1;
        while (r <= n && a[r] == a[r - 1]) {
            ++r;
        } // [l, r)
        comp.push_back({a[l], r - l});
        l = r;
    }
    int m = comp.size();
    for(int i = 0; i < m;) {
        int j = i + 1;
        while (j < m && comp[j].first - comp[j - 1].first <= k) ++j;
        if (comp[j - 1].second % 2 == 0) {
            cout << "YES" << el;
            return;
        }
        if (j - i > 1) {
            cout << "YES" << el;
            return;
        }
        i = j;
    }
    cout << "NO" << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}