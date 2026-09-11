#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "E"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
void testcase() {
    int n; cin >> n;
    vector<int> b(n + 1);
    vector<int> diff(n + 2, 0);

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        if (b[i] > 0) {
            int l = max(1, i - b[i] + 1);
            int r = min(n, i + b[i] - 1);
            if (l <= r) {
                diff[l]++;
                diff[r + 1]--;
            }
        }
    }

    vector<int> res(n + 1, 0);
    int cur = 0;
    bool possible = false;

    for (int i = 1; i <= n; i++) {
        cur += diff[i];
        if (cur == 0) {
            res[i] = 1;
            possible = true;
        }
    }

    if (!possible) {
        cout << -1 << el;
        return;
    }

    vector<int> left(n + 1, -1), right(n + 1, -1);

    int last = -1;
    for (int i = 1; i <= n; i++) {
        if (res[i] == 1) last = i;
        left[i] = last;
    }

    last = -1;
    for (int i = n; i >= 1; i--) {
        if (res[i] == 1) last = i;
        right[i] = last;
    }

    for (int i = 1; i <= n; i++) {
        if (b[i] != -1) {
            int mn = INF;
            if (left[i] != -1) mn = min(mn, i - left[i]);
            if (right[i] != -1) mn = min(mn, right[i] - i);

            if (mn != b[i]) {
                cout << -1 << el;
                return;
            }
        }
    }

    for (int i = 1; i <= n; i++) cout << res[i];
    cout << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}