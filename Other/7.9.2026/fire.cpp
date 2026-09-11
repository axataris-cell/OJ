#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define int long long
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "fire"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=4e18,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
struct Segtree {
    vector<int> ST;
    Segtree(int n) : ST(4 * n + 1, INF) {}
    void reset(int n) {
        for(int i = 0; i <= 4 * n; i++) {
            ST[i] = INF;
        }
    }
    void update(int id, int l, int r, int pos, int val) {
        if (l > pos || r < pos) return;
        if (l == r) {
            ST[id] = min(ST[id], val);
            return;
        }
        
        int mid = (l + r) / 2;
        update(id << 1, l, mid, pos, val);
        update(id << 1 | 1, mid + 1, r, pos, val);
        
        ST[id] = min(ST[id << 1], ST[id << 1 | 1]);
    }
    
    int query(int id, int l, int r, int x, int y) {
        if (l > y || r < x) return INF;
        if (x <= l && r <= y) {
            return ST[id];
        }
        int mid = (l + r) / 2;
        return min(query(id << 1, l, mid, x, y), query(id << 1 | 1, mid + 1, r, x, y));
    }
};
void testcase() {
    int n, k; cin >> n >> k;
    vector<int> h(n + 1, 0), t(n + 1, 0);
    vector<int> num(n + 1, 0);
    map<int, int> mp;
    for(int i = 1; i <= n; i++) {
        cin >> h[i];
        ++mp[h[i]];
        num[i] = mp[h[i]];
    }
    for(int i = 1; i < n; i++) cin >> t[i];
    vector<int> f(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        f[i] = f[i - 1] + t[i - 1];
    }
    auto query=[&](int l, int r)->int {
        if (l > r) return 0;
        return f[r] - f[l];
    };
    vector<int> prev(n + 1, 1), nxt(n + 1, n);// prev[i]..nxt[i]
    {
        stack<int> st;
        stack<int> st2;
        for(int i = 1; i <= n; i++) {
            if (i != 1) prev[i] = i - 1;
            if (i != n) nxt[i] = i + 1;
            while (st.size() && h[st.top()] < h[i]) {
                nxt[st.top()] = i;
                st.pop();
            }
            if (st.size()) prev[i] = st.top();
            int last = i;
            while (st.size() && h[st.top()] == h[i]) {
                nxt[st.top()] = last;
                last = st.top();
                st.pop();
            }
            st.push(i);
        }
    }

    Segtree ST(n);
    
    auto check=[&](int val) -> bool {
        ST.reset(n);

        vector<int> trai(n + 1, 0), phai(n + 1, 0);
        vector<int> dp(n + 1, INF);
        vector<vector<int>> doan(n + 1);

        for(int i = 1; i <= n; i++) {
            trai[i] = phai[i] = i;
            {
                int l = prev[i];
                int r = i;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (query(mid, i) <= val) {
                        r = mid - 1;
                        trai[i] = mid;
                    } else l = mid + 1;
                }
            }
            {
                int l = i;
                int r = nxt[i];
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (query(i, mid) <= val) {
                        l = mid + 1;
                        phai[i] = mid;
                    } else r = mid - 1;
                }
            }
            doan[phai[i]].push_back(trai[i]);
        }
        dp[0] = 0;
        ST.update(1, 0, n, 0, 0);
        for(int i = 1; i <= n; i++) {
            for(auto l : doan[i]) {
                int best = ST.query(1, 0, n, l - 1, i - 1);
                if (best == INF) continue;
                dp[i] = min(dp[i], best + 1);
            }
            ST.update(1, 0, n, i, dp[i]);
        }

        // cout << "DEB: " << val << el;
        // for(int i = 1; i <= n; i++) cout << dp[i] << ' ';
        // cout << el;
        // for(int i = 1; i <= n; i++) {
        //     cout << i << ' ' << trai[i] << ' ' << phai[i] << el;
        // }
        // cout << el << el;

        return dp[n] <= k;
    };

    if (!check(query(1, n))) {
        cout << -1;
        return;
    }

    int l = 0, r = query(1, n);
    int res = -1;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid - 1;
            res = mid;
        } else l = mid + 1;
    }

    cout << res;
}

/*
8 3
4 4 3 4 3 2 5 4
3 5 4 7 5 9 5
*/

/*
8 1
2 4 2 4 1 2 4 1
1 1 1 1 1 1 1
*/

int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}