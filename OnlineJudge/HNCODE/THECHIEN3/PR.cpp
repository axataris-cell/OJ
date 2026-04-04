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
// Created: 2026-04-03 15:04

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "PR"

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

void testcase() {
    int n; cin >> n;
    vector<int> x(n + 1), e(n + 1);
    vector<pii> points;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> e[i];
        points.pb({x[i], e[i]});
    }

    {
        umap<int, int> mp;
        for (int i = 1; i <= n; i++) {
            ++mp[e[i]];
        }
        if (mp.size() == 1) {
            map<int, int> pos;
            for (int i = 1; i <= n; i++) {
                ++pos[x[i]];
            }
            cout << pos.size() << el;
            return;
        }
    }

    {
        bool check = true;
        for (int i = 2; i <= n; i++) {
            if (x[i] < x[i - 1] || e[i] < e[i - 1]) {
                check = false;
                break;
            }
        }
        if (check) {
            sort(all(points), [](pii x, pii y) {return x.se > y.se;}); //greedy theo e
            vector<pii> res;
            for (auto& p : points) {
                bool already = false;
                for (auto &g : res) {
                    if (g.se - p.se >= abs(g.fi - p.fi)) {
                        already = true;
                        break;
                    }
                }
                if (already) continue;
                res.pb(p);
            }
            cout << res.size(); return;
        }
    }
    vector<int> deg(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (abs(x[i] - x[j]) <= e[i] - e[j]) {
                ++deg[j];
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) ++res;
    }

    cout << res;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}