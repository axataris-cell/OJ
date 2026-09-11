#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "DuDoan"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
struct S{int idx, other;};struct C{int idx;};
struct cmp{
    bool operator()(const S&x, const S&y) const {
        return x.other < y.other;
    }
};
vector<S>stt[MAXN];
vector<C>cll[MAXN];
void testcase() {
    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        int l, r; cin >> l >> r;
        stt[l].push_back({i, r});
        cll[r].push_back({i});
    }
    int curopen = 0;
    vector<int>res;
    vector<bool>del(n +1,false);
    pqueue<S,vector<S>,cmp>pq;
    for(int pos = 1; pos < MAXN; pos++) {
        for(auto &[idx, other] : stt[pos]) {
            pq.push({idx, other});
            ++curopen;
        }
        while (curopen > k) {
            auto [idx, r] = pq.top();pq.pop();
            if (r < pos) continue;
            del[idx]=true;
            --curopen;
            res.push_back(idx);
        }
        for(auto &[idx] : cll[pos]) {
            if (del[idx]) continue;
            --curopen;
        }
    }

    cout << res.size() << el;
    for(auto pos : res) cout << pos << ' ' ;
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}