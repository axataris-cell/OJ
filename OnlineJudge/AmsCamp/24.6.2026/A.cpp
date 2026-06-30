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
// Created: 2026-06-24 08:37

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

const int MAXA = 1e7 + 5;
bool p[MAXA];

void sieve() {
    for (int i = 2; i < MAXA; i++) p[i] = true;
    for (int i = 2; i * i < MAXA; i++) {
        if (p[i]) {
            for (int j = i * i; j < MAXA; j += i) p[j] = false;
        }
    }
}

void testcase() {
    int n; cin >> n;
    int k; cin >> k;
    if (k == 1) {
        cout << n;
        return;
    }
    if (n <= 20) {
        
        int cnt = 0;
        for (int mask = 0; mask < (1 << n); ++mask) {
            if (__builtin_popcount(mask) != k) continue;
            vector<int> cur;
            for (int i = 0; i < n; i++) {
                if (mask >> i & 1) {
                    cur.pb(i + 1);
                }
            }
            
            bool v = true;
            for (int i = 1; i < cur.size(); i++) {
                for (int j = i - 1; j >= 0; j--) {
                    if (!p[abs(cur[i] - cur[j])]) {
                        v = false;
                        break;
                    }
                }
                if (!v) break;
            }

            cnt += (v ? 1 : 0);
        }

        cout << cnt << el;
        return;
    }

    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    sieve();

    int t = 1; cin >> t;
    while (t--) testcase();

    return 0;
}