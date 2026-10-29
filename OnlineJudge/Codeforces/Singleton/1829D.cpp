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
    int n, m; cin >> n >> m;
    int cnt[2][2] = {{0, 0}, {0, 0}};
    int r[2];
    {
        int cur = n;
        while (cur > 0 && cur % 3 == 0) {
            ++cnt[0][0];
            cur /= 3;
        }
        while (cur > 0 && cur % 2 == 0) {
            ++cnt[0][1];
            cur /= 2;
        }
        r[0] = cur;
    }
    {
        int cur = m;
        while (cur > 0 && cur % 3 == 0) {
            ++cnt[1][0];
            cur /= 3;
        }
        while (cur > 0 && cur % 2 == 0) {
            ++cnt[1][1];
            cur /= 2;
        }
        r[1] = cur;
    }
    if (r[0] != r[1]) {
        cout << "NO" << el;
        return;
    }
    if (cnt[0][0] < cnt[1][0]) {
        cout << "NO" << el;
        return;
    }
    int op = cnt[0][0] - cnt[1][0];
    if (cnt[0][1] + op < cnt[1][1] || cnt[0][1] > cnt[1][1]) {
        cout << "NO" << el;
        return;
    }
    cout << "YES" << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}