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
    string s; cin >> s;
    deque<char> dq;
    for (auto ch : s) dq.push_back(ch);

    while (dq.size() && dq.front() == '0') dq.pop_front();
    while (dq.size() && dq.front() == '1') dq.pop_front();
    while (dq.size() && dq.back() == '0') dq.pop_back();
    while (dq.size() && dq.back() == '1') dq.pop_back();

    int res = 0;
    while (dq.size()) {
        auto u = dq.front(); dq.pop_front();
        if (u == '0') ++res;
    }

    cout << res << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}