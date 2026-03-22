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
// Created: 2026-03-22 21:31

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "52"

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
    string s; cin >> s;
    int n = s.len();

    vector<int> p(n + 1, 0);
    vector<int> z(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        int j = p[i - 1];

        while (j != 0 && s[j] != s[i - 1]) j = p[j];
        if (s[j] == s[i - 1]) ++j;

        p[i] = j;
    }

    int l = 1, r = 1;
    for (int i = 1; i < n; i++) {
        if (i <= r) z[i] = min(z[i - l], r - i);

        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];

        if (i + z[i] > r) {
            l = i; // 0 based
            r = i + z[i]; // 0
        }
    }

    for (int i = 0; i < n; i++) {
        cout << z[i] << ' ';
    }
    cout << el;
    for (int i = 1; i <= n; i++) {
        cout << p[i] << ' ';
    }
    cout << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}