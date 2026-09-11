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
    int n; cin >> n;
    string s;cin >> s;

    if (s[0] == '0') {
        cout << -1 << el;
        return;
    }
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == '0' && s[i + 1] == '0') {
            cout << -1 << el;
            return;
        }
    }

    int OFFSET = 15;
    for (int C = 1; C <= 5; ++C) {
        vector<bool> cur(31, false);
        cur[0 + OFFSET] = true;

        bool ok = true;
        for (int i = 0; i < n; ++i) {
            vector<bool> nxt(31, false);
            bool any = false;

            for (int v = -15; v <= 15; ++v) {
                if (!cur[v + OFFSET]) continue;

                for (int a = -C; a <= C; ++a) {
                    if (a == 0) continue;
                    int u = v + a;
                    if (u < -15 || u > 15) continue;

                    if ((s[i] == '+' && u > 0) ||                   
                        (s[i] == '-' && u < 0) ||
                        (s[i] == '0' && u == 0)) {
                        nxt[u + OFFSET] = true;
                        any = true;
                    }
                }
            }

            if (!any) {
                ok = false;
                break;
            }
            cur = nxt;
        }

        if (ok) {
            cout << C << el;
            return;
        }
    }

    cout << -1 << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}