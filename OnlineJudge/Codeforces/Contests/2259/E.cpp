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
    vector<int> a(n + 1, 0);
    vector<vector<int>> swep(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > 0) {
            int l = max(1, i - a[i] + 1);
            int r = min(n, i + a[i] - 1);
            swep[l].push_back(1);
            swep[r].push_back(-1);
        }
    }
    int cur = 0;
    vector<int>res(n + 1,0);
    bool possible = false;
    for(int i = 1; i <= n; i++) {
        sort(swep[i].begin(), swep[i].end());
        for(auto p : swep[i]) {
            if (p == -1) continue;
            cur++;
        }
        if (cur == 0) {
            possible = true;
            res[i] = 1;
        }
        for(auto p : swep[i]) {
            if (p == 1) continue;
            --cur;
        }
    }
    if (!possible) {
        cout << -1 << el;
        return;
    }
    for(int i = 1; i <= n; i++) cout << res[i];
    cout << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}