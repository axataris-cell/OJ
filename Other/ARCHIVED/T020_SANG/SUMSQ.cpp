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
// Created: 2026-06-25 09:27

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "SUMSQ"

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

const int MAXN = 1e4 + 5;
int n, d;

vector<int> C(MAXN, 0);
vector<int> cur(MAXN, 0);

int res = INF;

void bt(int s, int pos, int sum) { // pos <= n
    cur[pos] = s;
    if (pos == n) {
        int calc = 0;
        for (int i = 1; i <= n; i++) {
            calc += C[i] * cur[i] * cur[i];
        }
        if (sum == d) res = min(res, calc);
        cur[pos] = -1;
        return;
    }
    //prun
    if (d - sum > (n - pos) * s) {
        cur[pos] = -1;
        return;
    }
    for (int i = min(s, d - sum); i >= 0; i--) {
        bt(i, pos + 1, sum + i);
    }
    cur[pos] = -1;
}

void testcase() {
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        C[i] = 0;
        cur[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> C[i];
    }
    sort(C.begin() + 1, C.begin() + n + 1); // uu tien nho nhat
    // x1 >= x2 >= x3 >= ...
    for (int i = d; i >= d / n - 1; i--) {
        bt(i, 1, i);
    }

    cout << res << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; cin >> t;
    while (t--) testcase();

    return 0;
}