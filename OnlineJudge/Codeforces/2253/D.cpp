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
// Created: 2026-08-07 22:09

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

#define int long long

void testcase() {
    int x, y; cin >> x >> y;

    int total = x + y;

    int k = sqrt(2.0 * total);
    while ((k + 1) * (k + 2) / 2 <= total) {
        k++;
    }
    while (k * (k + 1) / 2 > total) {
        k--;
    }

    int S = k * (k + 1) / 2;

    int minp = max(0LL, S - y);
    int maxp = min(S, x);

    auto dist = [&](int p) {
        int q = S - p;
        return (x - p) * (x - p) + (y - q) * (y - q);
    };

    int bestp = minp;
    int mindist = dist(minp);

    int can1 = (x - y + S) / 2;
    int can2 = can1 + 1;

    for (int p : {minp, maxp, can1, can2}) {
        if (p >= minp && p <= maxp) {
            int d = dist(p);
            if (d < mindist) {
                mindist = d;
                bestp = p;
            }
        }
    }

    int cx = -1;
    for (int i = 0; i <= k; i++) {
        int L = i * (i + 1) / 2;
        int R = L + i * (k - i);
        if (bestp >= L && bestp <= R) {
            cx = i;
            break;
        }
    }

    int L = cx * (cx + 1) / 2;
    int delta = bestp - L;
    int mxmove = k - cx;

    vector<int> pos;
    for (int i = 1; i <= cx; i++) {
        int shift = min(delta, mxmove);
        delta -= shift;
        int coord = (k - cx + i) - shift;
        pos.pb(coord);
    }

    string ans(k, 'Y');
    for (int pos : pos) {
        ans[pos - 1] = 'X';
    }

    cout << ans << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; cin >> t;
    while (t--) testcase();

    return 0;
}