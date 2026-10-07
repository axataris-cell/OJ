#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME ""
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
void testcase() {
    int n, q; cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> ans;
    vector<int> b(n * (n - 1) / 2);

    while (true) {
        int mnval = a[0];
        int mxval = a[0];
        for (int i = 1; i < n; i++) {
            mnval = min(mnval, a[i]);
            mxval = max(mxval, a[i]);
        }

        ans.push_back(mxval - mnval);

        if (mxval == mnval) {
            break;
        }

        int idx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                b[idx++] = a[i] ^ a[j];
            }
        }

        nth_element(b.begin(), b.begin() + n, b.end());

        for (int i = 0; i < n; i++) {
            a[i] = b[i];
        }
    }

    for (int i = 0; i < q; i++) {
        int x; cin >> x;
        cout << (x < ans.size() ? ans[x] : 0) << el;
    }
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}


