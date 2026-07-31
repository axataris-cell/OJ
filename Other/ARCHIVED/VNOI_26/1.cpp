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
// Created: 2026-07-24 09:17

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "1"

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
    if (n <= 4) {
        cout << -1 << el;
        return;
    }
    vector<bool> vis(n + 1, false);
    vis[1] = vis[5] = vis[4] = vis[2] = true;
    deque<int> bruh;
    bruh.pb(1);
    bruh.pb(5);
    bruh.pb(4);
    bruh.pb(2);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (i & 1) {
                bruh.push_front(i);
            } else bruh.push_back(i);
            vis[i] = true;
        }
    }
    while (bruh.size()) {
        cout << bruh.front() << ' ';
        bruh.pop_front();
    }
    cout << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; cin >> t;
    while (t--) testcase();

    return 0;
}