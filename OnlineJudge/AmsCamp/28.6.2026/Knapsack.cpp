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
// Created: 2026-06-28 10:13

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "Knapsack"

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

const int MAXN = 10005;
const int MAXQ = 100005;
const int MAXW = 105;

int n, q;
int w[MAXN], v[MAXN];
int ql[MAXQ], qr[MAXQ], qw[MAXQ], ans[MAXQ];
int dpL[MAXN][MAXW], dpR[MAXN][MAXW];

void solve(int L, int R, const vector<int>& q_list) {
    if (q_list.empty()) return;
    if (L == R) {
        for (int idx : q_list) {
            ans[idx] = (w[L] <= qw[idx]) ? v[L] : 0;
        }
        return;
    }

    int M = (L + R) >> 1;
    vector<int> q_left, q_right, q_cross;

    for (int idx : q_list) {
        if (qr[idx] <= M) q_left.pb(idx);
        else if (ql[idx] > M) q_right.pb(idx);
        else q_cross.pb(idx);
    }

    for (int j = 0; j <= 100; ++j) {
        dpL[M][j] = (w[M] <= j) ? v[M] : 0;
    }
    for (int i = M - 1; i >= L; --i) {
        for (int j = 0; j <= 100; ++j) {
            dpL[i][j] = dpL[i + 1][j];
            if (j >= w[i]) {
                dpL[i][j] = max(dpL[i][j], dpL[i + 1][j - w[i]] + v[i]);
            }
        }
    }

    for (int j = 0; j <= 100; ++j) {
        dpR[M + 1][j] = (w[M + 1] <= j) ? v[M + 1] : 0;
    }
    for (int i = M + 2; i <= R; ++i) {
        for (int j = 0; j <= 100; ++j) {
            dpR[i][j] = dpR[i - 1][j];
            if (j >= w[i]) {
                dpR[i][j] = max(dpR[i][j], dpR[i - 1][j - w[i]] + v[i]);
            }
        }
    }

    for (int idx : q_cross) {
        int best = 0;
        int limit = qw[idx];
        for (int j = 0; j <= limit; ++j) {
            best = max(best, dpL[ql[idx]][j] + dpR[qr[idx]][limit - j]);
        }
        ans[idx] = best;
    }

    solve(L, M, q_left);
    solve(M + 1, R, q_right);
}

void testcase() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> v[i];
    }
    cin >> q;
    vector<int> q_list(q);
    for (int i = 0; i < q; ++i) {
        cin >> ql[i] >> qr[i] >> qw[i];
        q_list[i] = i;
    }
    solve(1, n, q_list);
    for (int i = 0; i < q; ++i) {
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