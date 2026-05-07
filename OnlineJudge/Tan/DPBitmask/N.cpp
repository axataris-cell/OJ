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
// Created: 2026-05-06 21:42

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "N"

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
    string s; cin >> s;

    if (n == 1) {
        cout << 0 << el;
        return;
    } else if (n == 2) {
        if (s == "AA" || s == "BB") cout << 0 << el;
        else cout << -1 << el;
        return;
    }

    int start = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') start |= (1 << i);
    }
    
    vector<int> dist(1 << n, INF);
    vector<bool> vis(1 << n, false);
    queue<int> q;

    q.emplace(start);
    dist[start] = 0;
    vis[start] = true;

    while (q.size()) {
        int u = q.front(); q.pop();
        for (int i = 0; i <= n - 3; i++) {
            int v = u ^ (7 << i);
            if (!vis[v]) {
                vis[v] = true;
                dist[v] = dist[u] + 1;
                q.emplace(v);
            }
        }
        for (int i = 0; i <= n - 2; i++) {
            int v = u ^ (3 << i);
            if (!vis[v]) {
                vis[v] = true;
                dist[v] = dist[u] + 1;
                q.emplace(v);
            }
        }
    }

    cout << min(dist[0], dist[(1 << n) - 1]);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}