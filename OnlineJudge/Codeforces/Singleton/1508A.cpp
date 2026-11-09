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
    string s[3]; cin >> s[0] >> s[1] >> s[2];
    int cnt[3][2];
    for (int i = 0; i < 3; i++) {
        cnt[i][0] = 0;
        cnt[i][1] = 0;
        for (int j = 0; j < 2 * n; j++) {
            ++cnt[i][s[i][j] - '0'];
        }
    }
    auto good = [&](int k, int l) -> int {
        if (cnt[k][0] >= n && cnt[l][0] >= n) return 0;
        if (cnt[k][1] >= n && cnt[l][1] >= n) return 1;
        return -1;
    };

    for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
            if (k == l) continue;
            int target = good(k, l);
            if (target == -1) continue;
            
            char c = (target == 0 ? '0' : '1');
            string res = "";
            int i = 0, j = 0;
            while (i < 2 * n && j < 2 * n) {
                if (s[k][i] == s[l][j]) {
                    res += s[k][i];
                    ++i;
                    ++j;
                } else if (s[k][i] != c) {
                    res += s[k][i];
                    ++i;
                } else {
                    res += s[l][j];
                    ++j;
                }
            }
            while (i < 2 * n) {
                res += s[k][i];
                ++i;
            }
            while (j < 2 * n) {
                res += s[l][j];
                ++j;
            }
            
            cout << res << el;
            return;
        }
    }
    
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}