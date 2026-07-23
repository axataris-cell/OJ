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
// Created: 2026-07-22 16:46

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "D"

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

const int MAXN = 1e5 + 5;
const int BLOCK = 400;

struct History {
    int v;
    int fipos, lapos;
};

struct Query {
    int l, r, id;
};

void testcase() {
    int n; cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int q; cin >> q;
    vector<int> ans(q + 1, 0);
    vector<Query> queries;
    for (int i = 1; i <= q; i++) {
        int l, r; cin >> l >> r;
        queries.pb({l, r, i});
    }

    vector<int> firstpos(n + 1, 0);
    vector<int> lastpos(n + 1, 0);

    vector<History> history;
    vector<vector<Query>> bucket(BLOCK);
    for (auto &[l, r, id] : queries) {
        if (r - l + 1 <= BLOCK) {
            int res = 0;
            for (int i = l; i <= r; i++) {
                if (firstpos[a[i]] == 0) {
                    firstpos[a[i]] = lastpos[a[i]] = i;
                } else {
                    lastpos[a[i]] = i;
                    res = max(res, i - firstpos[a[i]]);
                }
            }
            ans[id] = res;
            for (int i = l; i <= r; i++) {
                firstpos[a[i]] = lastpos[a[i]] = 0;
            }
            continue;
        }
        int B = (l - 1) / BLOCK;
        bucket[B].pb({l, r, id});
    }
    for (int buck = 0; buck < BLOCK; buck++) {
        if (bucket[buck].empty()) continue;
        auto &query = bucket[buck];
        sort(all(query), [](const Query &x, const Query &y) {
            return x.r < y.r;
        });
        int E = (buck + 1) * BLOCK;

        int curans = 0;
        int R = E;

        for (auto &[l, r, id] : query) {
            while (R < r) {
                ++R;
                int v = a[R];
                if (firstpos[v] == 0) {
                    firstpos[v] = lastpos[v] = R;
                } else {
                    lastpos[v] = R;
                    curans = max(curans, R - firstpos[v]);
                }
            }

            int bruh = curans;

            for (int i = E; i >= l; i--) {
                int v = a[i];
                history.pb({v, firstpos[v], lastpos[v]});
                if (firstpos[v] == 0) {
                    firstpos[v] = lastpos[v] = i;
                } else {
                    firstpos[v] = i;
                    bruh = max(bruh, lastpos[v] - i);
                }
            }

            ans[id] = bruh;

            while (history.size()) {
                auto [v, fip, lap] = history.back();
                history.pop_back();
                firstpos[v] = fip;
                lastpos[v] = lap;
            }
        }
        for (int i = E + 1; i <= R; i++) {
            firstpos[a[i]] = lastpos[a[i]] = 0;
        }
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