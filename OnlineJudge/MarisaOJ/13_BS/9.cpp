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
// Created: 2026-04-14 20:03

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "9"

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

vector<int> C2(70, 1), C3(70, 1), C5(70, 1);

void pre() {
    for (int i = 1; i < 65; i++) {
        if (C2[i - 1] < 1e18) C2[i] = C2[i - 1] * 2;
        if (C3[i - 1] < 1e18) C3[i] = C3[i - 1] * 3;
        if (C5[i - 1] < 1e18) C5[i] = C5[i - 1] * 5;
    }
}

void testcase() {
    pre();
    vector<int> hamming_her_in_da_walls;
    for (int i = 0; i <= 64; i++) {
        for (int j = 0; C3[j] <= 1e18 / C2[i]; j++) {
            for (int k = 0; k <= 28; k++) {
                if (C2[i] * C3[j] * C5[k] > 1e18) break;
                hamming_her_in_da_walls.pb(C2[i] * C3[j] * C5[k]);
            }
        }
    }
    sort(all(hamming_her_in_da_walls));
    hamming_her_in_da_walls.erase(unique(all(hamming_her_in_da_walls)), hamming_her_in_da_walls.end());

    // for (int i = 0; i < 10; i++) {
    //     cout << hamming_her_in_da_walls[i] << el;
    // }

    int q; cin >> q;
    while (q--) {
        int m; cin >> m;
        if (!binary_search(all(hamming_her_in_da_walls), m)) {
            cout << -1 << el;
        } else {
            cout << lower_bound(all(hamming_her_in_da_walls), m) - hamming_her_in_da_walls.begin() + 1 << el;
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