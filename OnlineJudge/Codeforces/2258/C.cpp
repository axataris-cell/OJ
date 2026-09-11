#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "C"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;

int ask(int u, int v, int d) {
    cout << "? " << u << ' ' << v << ' ' << d << el;
    cout.flush();
    int res; cin >> res;
    return res;
}
void testcase() {
    int n; cin >> n;
    int u = 1, v = 1;
    int d1 = 0;

    for (int x = 1; x <= n; ++x) {
        if (x == u) continue;
        while (ask(u, x, d1 + 1) == 1) {
            d1++;
            v = x;
        }
    }
    int s = v;
    int w = u;
    int d2 = d1;

    for (int x = 1; x <= n; ++x) {
        if (x == s) continue;
        while (ask(s, x, d2 + 1) == 1) {
            d2++;
            w = x;
        }
    }

    cout << "! " << s << " " << w << " " << d2 << el;
    cout.flush();
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}