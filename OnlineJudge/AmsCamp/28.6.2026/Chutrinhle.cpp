#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "Chutrinhle"

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

struct Edge {
    int u, v;
};

struct Query {
    int l, r, id, blk;
};

struct RollbackDSU {
    struct Event {
        int v, u, rku;
    };
    vector<int> par, rk, diff;
    vector<Event> hist;

    RollbackDSU(int n) {
        par.resize(n + 1);
        iota(all(par), 0);
        rk.assign(n + 1, 0);
        diff.assign(n + 1, 0);
        hist.reserve(400005);
    }

    inline int find(int u, int &d) {
        d = 0;
        while (u != par[u]) {
            d ^= diff[u];
            u = par[u];
        }
        return u;
    }

    inline bool unite(int u, int v) {
        int du = 0, dv = 0;
        int ru = find(u, du);
        int rv = find(v, dv);
        if (ru == rv) return (du ^ dv);
        if (rk[ru] < rk[rv]) swap(ru, rv);
        hist.pb({rv, ru, rk[ru]});
        par[rv] = ru;
        diff[rv] = du ^ dv ^ 1;
        if (rk[ru] == rk[rv]) rk[ru]++;
        return true;
    }

    inline int get_time() { return hist.size(); }

    inline void rollback(int t) {
        while ((int)hist.size() > t) {
            Event e = hist.back();
            hist.pop_back();
            par[e.v] = e.v;
            diff[e.v] = 0;
            rk[e.u] = e.rku;
        }
    }
};

void testcase() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<Edge> edges(2 * m + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> edges[i].u >> edges[i].v;
        edges[i + m] = edges[i];
    }

    vector<int> ans(q + 1, 0);
    vector<Query> queries;
    queries.reserve(q);

    int B = max(1, (int)(2.0 * m / sqrt(max(1, q))));

    for (int i = 1; i <= q; ++i) {
        int L, R;
        cin >> L >> R;
        int l = R + 1;
        int r = m + L - 1;
        if (l > r) {
            ans[i] = 0;
        } else {
            queries.pb({l, r, i, l / B});
        }
    }

    sort(all(queries), [](const Query& a, const Query& b) {
        if (a.blk != b.blk) return a.blk < b.blk;
        return a.r < b.r;
    });

    RollbackDSU dsu(n);

    int cur_block = -1;
    int r_ptr = 0;
    bool persist_ok = true;

    for (const auto& qry : queries) {
        int blk = qry.blk;
        int r_base = min(2 * m, (blk + 1) * B - 1);

        if (blk != cur_block) {
            cur_block = blk;
            dsu.rollback(0);
            r_ptr = r_base;
            persist_ok = true;
        }

        if (qry.r <= r_base) {
            int cp = dsu.get_time();
            bool ok = true;
            for (int j = qry.l; j <= qry.r; ++j) {
                if (!dsu.unite(edges[j].u, edges[j].v)) {
                    ok = false;
                    break;
                }
            }
            ans[qry.id] = ok ? 0 : 1;
            dsu.rollback(cp);
        } else {
            while (r_ptr < qry.r) {
                r_ptr++;
                if (!dsu.unite(edges[r_ptr].u, edges[r_ptr].v)) {
                    persist_ok = false;
                }
            }

            int cp = dsu.get_time();
            bool ok = persist_ok;
            if (ok) {
                for (int j = qry.l; j <= r_base; ++j) {
                    if (!dsu.unite(edges[j].u, edges[j].v)) {
                        ok = false;
                        break;
                    }
                }
            }
            ans[qry.id] = ok ? 0 : 1;
            dsu.rollback(cp);
        }
    }

    for (int i = 1; i <= q; ++i) {
        cout << ans[i] << el;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1;
    while (t--) testcase();

    return 0;
}