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
// Created: 2026-07-31 08:46

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "REVNUM"

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

void testcase() {
    int n, k; cin >> n >> k;
    vector<string> normal;
    vector<string> zeros;

    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        reverse(all(s));
        if (s[0] == '0') zeros.pb(s);
        else normal.pb(s);
    }

    sort(all(normal), [](const string &x, const string &y) {
        return x + y < y + x;
    });

    sort(all(zeros), [](const string &x, const string &y) {
        return x + y < y + x;
    });

    if (!normal.size()) {
        cout << -1;
        return;
    }

    cout << normal[0];
    for (auto &s : zeros) cout << s;
    for (int i = 1; i < normal.size(); i++) cout << normal[i];

    // vector<string> a(n + 1);
    // for (int i = 1; i <= n; i++) {
    //     cin >> a[i];
    //     reverse(all(a[i]));
    // }
    // sort(a.begin() + 1, a.end(), [](const string &x, const string &y) {
    //     if (x[0] == '0') return false;
    //     if (y[0] == '0') return true;
    //     return x + y < y + x;
    // });

    // for (int i = 1; i <= n; i++) {
    //     cout << a[i];
    // }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}