#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "MAGI"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
void testcase() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int res = 0;

    for (int s = 0; s < 2; ++s) {
        vector<int> c(n);
        c[0] = s;
        bool ok = true;

        for (int i = 0; i < n - 1; ++i) {
            int diff = a[i + 1] - a[i];
            
            if (diff == 1) {
                if (c[i] != 0) {
                    ok = false;
                    break;
                }
                c[i + 1] = 0;
            } else if (diff == -1) {
                if (c[i] != 1) {
                    ok = false;
                    break;
                }
                c[i + 1] = 1;
            } else if (diff == 0) {
                c[i + 1] = 1 - c[i];
            } else {
                ok = false;
                break;
            }
        }

        if (!ok) continue;

        int cnt = 0;
        for (int x : c) {
            if (x == 1) cnt++;
        }

        int cc = (c[0] == 0 ? 1 : 0) + cnt;

        if (cc == a[0]) {
            res++;
        }
    }

    cout << res << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}