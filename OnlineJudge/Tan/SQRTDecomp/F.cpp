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
// Created: 2026-07-27 16:05

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "F"

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

const int BLOCK = 750;

struct Query {
    int l, r, id;
};

vector<int> history; // luu vi tri anh xa

int mp[666666];

void testcase() {
    int n, q; cin >> n >> q;
    vector<int> a(n + 1, 0);
    history.reserve(q + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> ans(q + 1, 0);
    int numBlock = (n + BLOCK - 1) / BLOCK;
    vector<vector<Query>> queries(numBlock);    
    for (int i = 1; i <= q; i++) {
        int l, r; cin >> l >> r;
        int B = (l - 1) / BLOCK;
        queries[B].pb({l, r, i});
    }
    for (int B = 0; B < numBlock; B++) {
        if (queries[B].empty()) continue;
        vector<Query> heavy;
        for (auto &[l, r, id] : queries[B]) {
            // light qury
            if (r - l + 1 <= BLOCK) {
                for (int i = l; i <= r; i++) ++mp[a[i]];
                for (int i = 1; i <= BLOCK + 1; i++) {
                    if (!mp[i]) {
                        ans[id] = i;
                        break;
                    }
                }
                for (int i = l; i <= r; i++) mp[a[i]] = 0;
            } else heavy.pb({l, r, id});

        }
        sort(all(heavy), [](const Query &x, const Query &y) {
            return x.r < y.r;
        });

        // heavy queries
        int E = ((B + 1) * BLOCK); // ria ngoai
        int cur_R = E;
        int curAns = 1;

        for (auto &[l, r, id] : heavy) {
            while (cur_R < r) {
                ++cur_R;
                mp[a[cur_R]]++;
            }
            while (mp[curAns]) ++curAns;

            // tempo updat
            for (int i = E; i >= l; i--) {
                ++mp[a[i]];
                history.pb(a[i]);
            }
            while (mp[curAns]) ++curAns;

            ans[id] = curAns;

            // reverse tempo
            while (history.size()) {
                int u = history.back();
                --mp[u];
                if (mp[u] == 0 && curAns > u) curAns = u;
                history.pop_back();
            }
        }
        
        // rolllback history
        for (int i = E + 1; i <= cur_R; i++) {
            --mp[a[i]];
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