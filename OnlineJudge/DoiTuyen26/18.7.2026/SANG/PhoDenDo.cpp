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
// Created: 2026-07-18 09:51

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "PhoDenDo"

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

const int MAXN = 2e5 + 5;

struct comp {
    bool operator()(const pii &a, const pii &b) const {
        int la = a.se - a.fi;
        int lb = b.se - b.fi;
        if (la != lb) return la < lb;
        return a > b;
    }
};

void testcase() {
    int L, n; cin >> L >> n;
    pqueue<pii, vector<pii>, comp> pq;
    set<int> s;

    pq.emplace(0, L);
    s.insert(0);
    s.insert(L);

    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        auto nxt = s.lower_bound(x);
        auto pos = prev(nxt);
        pq.emplace(*pos, x);
        pq.emplace(x, *nxt);
        s.insert(x);

        bool ok = false;
        while (!ok) {
            auto [l, r] = pq.top();
            auto posl = s.find(l);

            if (*next(posl) != r) {
                pq.pop();
            } else {
                cout << r - l << el; 
                ok = true;
            }
        }
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