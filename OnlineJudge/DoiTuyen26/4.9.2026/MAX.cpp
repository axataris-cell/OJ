#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "MAX"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
void testcase() {
    int n, q, k; cin >> n >> q >> k;

    vector<int> a(n + 1);
    int gt = 0;
    int eq = 0;
    int c = 0;

    auto add = [&](int val) {
        if (val == -1) {
            c++;
        } else if (val > k) {
            gt++;
        } else if (val == k) {
            eq++;
        }
    };

    auto remove = [&](int val) {
        if (val == -1) {
            c--;
        } else if (val > k) {
            gt--;
        } else if (val == k) {
            eq--;
        }
    };

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        add(a[i]);
    }

    auto get_ans = [&]() {
        if (gt > 0) {
            return 0LL;
        }
        if (eq > 0) {
            if (c == 0) return 1LL;
            return k % 2;
        } else {
            if (c == 0) return 0LL;
            return 1LL;
        }
    };

    while (q--) {
        int idx;
        int x;
        cin >> idx >> x;

        remove(a[idx]);
        a[idx] = x;
        add(a[idx]);

        cout << get_ans() << el;
    }
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}