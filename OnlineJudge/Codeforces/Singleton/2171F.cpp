#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "2171F"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;

void testcase() {
    int n; cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    set<int> S;
    vector<pii> res;

    for (int x : p) {
        auto it = S.lower_bound(x);
        
        if (it == S.begin()) {
            S.insert(x);
        } else {
            vector<int> smaller(S.begin(), it);
            
            int m = smaller[0];
            
            for (int s : smaller) {
                res.push_back({s, x});
                if (s != m) {
                    S.erase(s);
                }
            }
        }
    }

    if (S.size() != 1) {
        cout << "NO" << el;
        return;
    }

    cout << "YES" << el;
    for (auto &[u, v] : res) {
        cout << u << ' ' << v << el;
    }
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}