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
const int INF=4e18,MAXN=2e5+5,LOG=20,MOD=1e9+7,BASE=113,BLOCK=400;
void testcase() {
    int n; cin >> n;
    vector<string> s[3];
    map<string, int> mp;
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= n; j++) {
            string t; cin >> t;
            s[i].push_back(t);
            ++mp[t];
        }
    }

    int res[3] = {0, 0, 0};

    for (int i = 0; i < 3; i++) {
        for (auto t : s[i]) --mp[t];
        for (auto t : s[i]) {
            if (mp[t] == 0) res[i] += 3;
            if (mp[t] == 1) res[i]++;
        }
        for (auto t : s[i]) ++mp[t];
    }

    cout << res[0] << ' ' << res[1] << ' ' << res[2] << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}