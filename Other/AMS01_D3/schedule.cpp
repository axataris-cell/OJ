#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fi first
#define se second
#define null nullptr
#define pb push_back
#define len length
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-07-14 09:21

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "schedule"

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

#ifdef LOCAL
   #define debug(x) cerr << x << '\n'
#else
   #define debug(x)
#endif

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

void file() {
    if (FILE *f = fopen(FILENAME".inp", "r")) {
        fclose(f);
        freopen(FILENAME".inp", "r", stdin);
        freopen(FILENAME".out", "w", stdout);
    }
}

const int MAXN = 2e5 + 5;

struct Fenwick {
    int n;
    vector<int> bit;

    Fenwick(int _n) : n(_n), bit(n + 1, 0) {}

    void update(int pos, int val) {
        for (; pos <= n; pos += pos & -pos)
            bit[pos] += val;
    }

    int query(int pos) {
        int res = 0;
        for (; pos; pos -= pos & -pos)
            res += bit[pos];
        return res;
    }

    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

bool vis[30];
vector<int> bruh(30);
int ressub1 = INF;

void dfs(int pos, vector<int> &a, int &n) {
    if (pos == n + 1) {
        for (int i = 1; i <= n; i++) {
            if (a[bruh[i]] < i) return;
        }
        Fenwick BIT(n);
        int curres = 0;
        for (int i = 1; i <= n; i++) {
            curres += BIT.query(n) - BIT.query(bruh[i]);
            BIT.update(bruh[i], 1);
        }
        if (ressub1 > curres) {
            ressub1 = curres;
        }
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = true;
            bruh[pos] = i;
            dfs(pos + 1, a, n);
            vis[i] = false;
        }
    }
}


void testcase() {
    int n; cin >> n;
    vector<int> a(n + 1, 0);
    umap<int, int> mp; // for sub 2;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ++mp[a[i]];
    }

    // check for -1

    int curbruh = 0;
    for (int i = 1; i <= n; i++) {
        curbruh += mp[i];
        if (curbruh > i) {
            cout << -1;
            return;
        }
    }
    
    //sub 2
    
    bool sub2 = true;
    for (int i = 1; i <= n; i++) {
        if (!mp[i]) {
            sub2 = false;
            break;
        }
    }
    
    if (sub2) {
        Fenwick BIT(n + 1);
        vector<pii> b(n + 1);
        for (int i = 1; i <= n; i++) {
            b[i].fi = a[i];
            b[i].se = i;
        }
        sort(b.begin() + 1, b.end());
        ll res = 0;
        for (int i = 1; i <= n; i++) {
            res += BIT.query(n) - BIT.query(b[i].se);
            BIT.update(b[i].se, 1);
        }
        cout << res;
        return;
    }
    
    //sub 1
    
    if (n <= 9) {
        dfs(1, a, n);
        cout << (ressub1 == INF ? -1 : ressub1);
        return;
    }
    
    // sub 3: greeduuuu sub 4 if lucky

    vector<int> res(n + 1, 0);
    vector<pii> b(n + 1);
    for (int i = 1; i <= n; i++) {
        b[i].fi = a[i];
        b[i].se = i;
    }
    sort(b.begin() + 1, b.end(), [](const pii &x, const pii &y) {
        if (x.fi != y.fi) return x.fi < y.fi;
        else return x.se > y.se;
    });
    for (int idx = 1; idx <= n; idx++) {
        auto [limit, pos] = b[idx];
        int best = INF;
        int bestpos = -1;
        for (int i = 1; i <= limit; i++) {
            if (res[i]) continue;
            if (best > abs(pos - i)) {
                best = abs(pos - i);
                bestpos = i;
            }
        }
        if (bestpos == -1) {
            cout << -1;
            return;
        }
        res[bestpos] = pos;
    }
    ll cnt = 0;
    Fenwick BIT(n);
    for (int i = 1; i <= n; i++) {
        cnt += BIT.query(n) - BIT.query(res[i]);
        BIT.update(res[i], 1);
    }

    cout << cnt;
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();
    
    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}