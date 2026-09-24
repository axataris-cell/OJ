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

// Author: Fua

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

#ifdef LOCAL
   #define debug(x) cerr << x << '\n'
#else
   #define debug(x)
#endif

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

void testcase() {
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<int> urgent;
    vector<int> div2, div3;
    vector<int> normal;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] % 6 == 0) {
            urgent.pb(a[i]);
        } else if (a[i] % 2 == 0) {
            div2.pb(a[i]);
        } else if (a[i] % 3 == 0) {
            div3.pb(a[i]);
        } else normal.pb(a[i]);
    }
    vector<int> left;
    vector<int> right;
    for (const auto &x : urgent) cout << x << ' ';
    for (const auto &x : div2) cout << x << ' ';
    for (const auto &x : normal) cout << x << ' ';
    for (const auto &x : div3) cout << x << ' ';
    cout << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1; cin >> t;
    while (t--) testcase();

    return 0;
}