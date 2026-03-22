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
// Created: 2026-03-22 17:03

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "48"

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

const int BASE = 113;
const int MOD = 1e9 + 7;

void testcase() {
    int np, nt; cin >> np >> nt;
    vector<int> a(np + 1, 0);
    vector<int> b(nt + 1, 0);

    for (int i = 1; i <= np; i++) cin >> a[i];
    for (int j = 1; j <= nt; j++) cin >> b[j];

    if (np > nt) {
        cout << -1;
        return;
    }

    vector<int> H(nt + 1, 0), P(nt + 1, 1);
    for (int i = 1; i <= nt; i++) {
        H[i] = (H[i - 1] * BASE % MOD + b[i]) % MOD;
        P[i] = (P[i - 1] * BASE) % MOD;
    }

    vector<int> T(np + 1, 0);
    for (int i = 1; i <= np; i++) {
        T[i] = (T[i - 1] * BASE % MOD + a[i]) % MOD;
    }

    auto get = [&](int l, int r) {
        return ((H[r] - H[l - 1] * P[r - l + 1] % MOD) % MOD + MOD) % MOD;
    };

    auto get2 = [&](int l, int r) {
        return ((T[r] - T[l - 1] * P[r - l + 1] % MOD) % MOD + MOD) % MOD;
    };

    for (int i = 1; i + np - 1 <= nt; i++) {

        int l = 1, r = np;
        bool diff = false;

        while (l <= r) {
            int mid = (l + r) / 2;
            int right = i + mid - 1;

            if (get(i, right) != get2(1, mid)) {
                r = mid - 1;
                diff = true;
            } else l = mid + 1;
        }

        if (!diff) {
            cout << i;
            return;
        }

        int pos = l; // vị trí khác đầu tiên

        if (pos == np) {
            cout << i;
            return;
        }

        if (get(i + pos, i + np - 1) == get2(pos + 1, np)) {
            cout << i;
            return;
        }
    }

    cout << -1;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1;
    while (t--) testcase();

    return 0;
}