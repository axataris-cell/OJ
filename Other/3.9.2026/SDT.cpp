#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "SDT"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".inp","r")) fclose(f),freopen(FILENAME".inp","r", stdin),freopen(FILENAME".out","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
void testcase() {
    int n; cin >> n;
    string s; cin >> s;
    map<char, int> mp;
    for(auto c : s) {
        ++mp[c];
    }
    int cnt=0;
    int mp8=mp['8'];
    for(int c = '0'; c <= '9'; c++) {
        if (c == '8') continue;
        cnt += mp[c];
    }
    // cout << mp8 << ' ' << cnt;
    // return;
    int res = 0;
    while (cnt >= 10 && mp8) {
        ++res;
        --mp8;
        cnt -= 10;
    }
    if (mp8) {
        int rest = mp8 + cnt;
        res += rest / 11;
    }

    cout << res;

}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}