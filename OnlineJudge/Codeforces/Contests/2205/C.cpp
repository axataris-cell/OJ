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
// Created: 2026-04-30 18:22

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

bool comp(const vector<int> &a, const vector<int> &b) {
    
}

void testcase() {
    int n; cin >> n;
    vector<vector<int>> user(n, vector<int>());
    for (int i = 0; i < n; i++) {
        int sz; cin >> sz;
        for (int j = 1; j <= sz; j++) {
            int x; cin >> x;
            user[i].pb(x);
        }
    }
    sort(all(user), comp);
    vector<bool> vis(1e6 + 5, false);
    // for (const auto &v : user) {
    //     cout << "debug: ";
    //     for (const auto &x : v) {
    //         cout << x << ' ';
    //     }
    //     cout << el;
    // }

    cerr << "ans: ";
    for (const auto &v : user) {
        for (int i = v.size() - 1; i >= 0; i--) {
            int x = v[i];
            if (!vis[x]) {
                cout << x << ' ';
                vis[x] = true;
            }
        }
    }
    cout << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; cin >> t;
    while (t--) testcase();

    return 0;
}