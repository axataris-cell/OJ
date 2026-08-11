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
// Created: 2026-08-07 10:40

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "C"

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

#define int long long

const int BLOCK = 320;

struct Query {
    int l, r, id;
};

int mp[2097152];

void testcase() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n + 1, 0);
    vector<int> f(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i] = f[i - 1] ^ a[i];
    }
    vector<Query> queries;
    vector<int> ans(m + 1, 0);
    for (int i = 1; i <= m; i++) {
        int l, r; cin >> l >> r;
        queries.pb({l - 1, r, i});
    }
    sort(all(queries), [](const Query &x, const Query &y) {
        if (x.l / BLOCK != y.l / BLOCK) return x.l / BLOCK < y.l / BLOCK;
        if ((x.l / BLOCK) & 1) return x.r < y.r;
        else return x.r > y.r;
    });
    int curres = 0;
    int L = 0;
    int R = -1;
    auto add = [&](int pos) {
        int v = f[pos];
        curres += mp[v ^ k];
        ++mp[v];
    };
    auto remove = [&](int pos) {
        int v = f[pos];
        --mp[v];
        curres -= mp[v ^ k];
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

    for (int i = 1; i <= m; i++) {
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