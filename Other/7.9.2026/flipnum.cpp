#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "flipnum"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
void testcase() {
    int n; cin >> n;
    // auto flip=[&](int val)->int {
    //     string s = to_string(val);
    //     reverse(s.begin(),s.end());
    //     return stoll(s);
    // };
    // for(int i = 1; i <= n; i++) {
    //     cout << i << ' ';
    //     if (flip(i) > n) {
    //         cout << "YES" << el;
    //     } else cout << "NO" << el;
    // }

    stack<int> res;
    string s = to_string(n);
    if (s[s.size() - 1] == '0') {
        s[s.size() - 1] = '1';
        reverse(s.begin(),s.end());
        cout << s;
        return;
    }

    bool changed = false;
    for(int i = 0; i < s.size(); i++) {
        auto c = s[i];
        if (changed) {
            if (i != s.size() - 1) res.push(0);
            else res.push(1);
            continue;
        }
        if (c == '9') res.push(9);
        else {
            res.push(c - '0' + 1);
            changed = true;
        }
    }
    if (!changed) {
        cout << 1;
        for(int i = 0; i < s.size()-1; i++) cout<<0;
        cout<<1;
        return;
    }
    while (res.size()) {
        cout << res.top();
        res.pop();
    }
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}