#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define null nullptr
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-21 15:35

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME ""

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

void file() {
    if (FILE *f = fopen(FILENAME".INP", "r")) {
        fclose(f);
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
}

void testcase() {
    string s, t; cin >> s >> t;
    string c = s + '$' + t; // pi func on c

    int n = c.size();
    vector<int> p(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        int j = p[i - 1];

        while (j != 0 && c[j] != c[i - 1]) j = p[j];
        if (c[j] == c[i - 1]) ++j;

        p[i] = j;
    }

    vector<int> bruh;

    int res = 0;
    for (int i = s.length() + 1; i <= n; i++) {
        if (p[i] == s.length()) {
            ++res;
            bruh.push_back(i - 2 * (int)s.length());
        }
    }
    cout << res << el;
    // for (auto x : bruh) cout << x << ' ';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}