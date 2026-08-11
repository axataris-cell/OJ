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
// Created: 2026-08-07 08:08

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "A"

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

const int BLOCK = 450;
umap<int, int> mp[500];

void testcase() {
    int n, q; cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ++mp[i / BLOCK][a[i]];
    }

    while (q--) {
        int t; cin >> t;
        if (t == 0) {
            int k, v; cin >> k >> v;
            int b = k / BLOCK;
            auto it = mp[b].find(a[k]);
            if (it != mp[b].end()) {
                it->second--;
                if (it->second == 0) {
                    mp[b].erase(it);
                }
            }
            a[k] = v;
            mp[b][v]++;
        } else {
            int l, r, x; cin >> l >> r >> x;
            
            if (l >= r) {
                cout << 0 << el;
                continue;
            }

            int leftB = l / BLOCK;
            int rightB = (r - 1) / BLOCK;
            int cnt = 0;

            if (leftB == rightB) {
                for (int i = l; i < r; i++) {
                    if (a[i] == x) ++cnt;
                }
            } else {
                for (int i = l; i < (leftB + 1) * BLOCK; i++) {
                    if (a[i] == x) ++cnt;
                }
                for (int i = leftB + 1; i < rightB; i++) {
                    auto it = mp[i].find(x);
                    if (it != mp[i].end()) {
                        cnt += it->second;
                    }
                }
                for (int i = rightB * BLOCK; i < r; i++) {
                    if (a[i] == x) ++cnt;
                }
            }

            cout << cnt << el;
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