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
// Created: 2026-08-06 10:00

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "SQRDIGIT"

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
const int LOG = 16;

int foward[MAXN][LOG];

void testcase() {
    int n, k; cin >> n >> k;
    for (int i = 1; i < MAXN; i++) {
        int ni = 0;
        int cur = i;
        while (cur > 0) {
            ni += (cur % 10) * (cur % 10);
            cur /= 10;
        }
        foward[i][0] = ni;
    }
    for (int i = 1; i < LOG; i++) {
        for (int j = 1; j < MAXN; j++) {
            foward[j][i] = foward[foward[j][i - 1]][i - 1];
        }
    }

    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int v = a[i];
        int curk = k;
        while (curk > 0 && v >= MAXN) {
            int nv = 0;
            while (v > 0) {
                nv += (v % 10) * (v % 10);
                v /= 10;
            }
            v = nv;
            --curk;
        }
        for (int i = 0; i < LOG; i++) {
            if (curk >> i & 1) {
                v = foward[v][i];
            }
        }
        a[i] = v;
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
    }
    cout << sum;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}