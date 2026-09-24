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
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<int>>mx(n+1,vector<int>(n+1,0)), mn(n+1,vector<int>(n+1,0));
    for(int i = 1; i <= n; i++) {
        mx[i][i] = mn[i][i] = a[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            mx[i][j] = max(a[j], mx[i][j - 1]);
            mn[i][j] = min(a[j], mn[i][j - 1]);
        }
    }
    vector<vector<bool>>dp(n+1,vector<bool>(n+1,false));
    for(int i=1;i<=n;i++)dp[i][i]=true;
    for(int l=1;l<=n;l++){
        multiset<int> s;
        multiset<int>diff;
        for(int r=l;r <= n;r++) {
            s.insert(a[r]);
            auto p = s.find(a[r]);
            if (next(p) != s.end() && p != s.begin()) {
                auto f = diff.find(*next(p) - *prev(p));
                diff.erase(f);
            }
            if (next(p) != s.end()) {
                diff.insert(*next(p) - *p);
            }
            if (p != s.begin()) {
                diff.insert(*p - *prev(p));
            }
            if (diff.empty() || *--diff.end() <= 1) dp[l][r] = true;
        }
    }

    int res = 0;
    struct Dat {
        int start;
        int pos, state;
    };
    for(int len = 1; len <= n; len++) {
        vector<Dat> sweep;
        for(int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            if (!dp[i][j]) continue;
            sweep.push_back({i,mn[i][j], 1});
            sweep.push_back({i,mx[i][j] + 1, -1});
        }
        sort(sweep.begin(),sweep.end(),[](const Dat&x, const Dat&y) {
            if (x.pos != y.pos)return x.pos<y.pos;
            else return x.state>y.state;
        });
        multiset<int> cur;
        for(auto &[start,pos,state]:sweep) {
            if (state == -1) {
                auto f = cur.find(start);
                cur.erase(f);
                continue;
            }
            cur.insert(start);
            if (cur.size()) {
                if (start - len >= *cur.begin() || start + len <= *--cur.end()) {
                    res = len;
                    break;
                }
            }
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