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
// Created: 2026-08-07 09:01

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "B"

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
    if (FILE *f = fopen(FILENAME".INP", "r")) {
        fclose(f);
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
}

const int B = 1000;

struct Query {
    int l, r, id;
};

const int MAXN = 1e6 + 5;

int mp[MAXN];

void testcase() {
    int n; cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<Query> queries;
    int q; cin >> q;
    vector<int> ans(q + 1, 0);
    for (int i = 1; i <= q; i++) {
        int l, r; cin >> l >> r;
        queries.pb({l, r, i});
    }
    sort(all(queries), [](const Query &x, const Query &y) {
        if (x.l / B != y.l / B) return x.l / B < y.l / B;
        if ((x.l / B) & 1) return x.r < y.r;
        else return x.r > y.r;
    });
    int L = 1;
    int R = 0;
    int curres = 0;
    auto remove = [&](int pos) -> void {
        --mp[a[pos]];
        if (mp[a[pos]] == 0) --curres;
    };
    auto add = [&](int pos) -> void {
        if (mp[a[pos]] == 0) ++curres;
        ++mp[a[pos]];
    };
    for (auto &[l, r, id] : queries) {
        while (L < l) {
            remove(L);
            ++L;
        }
        while (L > l) {
            --L;
            add(L);
        }
        while (R < r) {
            ++R;
            add(R);
        }
        while (R > r) {
            remove(R);
            --R;
        }
        ans[id] = curres;
    }

    for (int i = 1; i <= q; i++) {
        cout << ans[i] << el;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}