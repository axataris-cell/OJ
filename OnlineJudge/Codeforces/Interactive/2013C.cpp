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
// Created: 2026-04-20 10:03

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "2013C"

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
    int n; cin >> n;
    if (n == 1) {
        cout << "? " << 0 << endl;
        int orz;
        cin >> orz;
        cout << "! " << (orz == 1 ? 0 : 1) << endl;
        return;
    }
    string s = "0";

    while (true) {
        if (s.len() >= n) break;
        {
            cout << "? " << s + "0" << endl;
            int orz; cin >> orz;
            if (orz == 1) {
                s = s + "0";
                continue;
            }
        }
        {
            cout << "? " << s + "1" << endl;
            int orz; cin >> orz;
            if (orz == 1) {
                s = s + "1";
                continue;
            }
        }
        break;
    }
    if (s.len() == n) {
        cout << "! " << s << endl;
        return;
    }
    while (true) {
        if (s.len() >= n) break;
        {
            cout << "? " << "0" + s << endl;
            int orz; cin >> orz;
            if (orz == 1) {
                s = "0" + s;
                continue;
            }
        }
        {
            cout << "? " << "1" + s << endl;
            int orz; cin >> orz;
            if (orz == 1) {
                s = "1" + s;
                continue;
            }
        }
        break;
    }
    if (s.len() < n) {
        cout << "! ";
        for (int i = 1; i <= n; i++) cout << 1;
        cout << endl;
        return;
    }
    cout << "! " << s << endl;
    return;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; cin >> t;
    while (t--) testcase();

    return 0;
}