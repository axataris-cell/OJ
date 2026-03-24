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
// Created: 2026-03-24 15:08

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "129"

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

const int MAXN = 1e5 + 5;
set<int> st;
bool vis[MAXN];

void bfs(int s) {
    queue<int> q;

    q.push(s);
    vis[s] = true;
    st.insert(s);

    while (q.size()) {
        int u = q.front(); q.pop();
        for (int i = 1; i <= sqrt(u); i++) {
            if (u % i) continue;
            int j = u / i;
            if (!vis[(i - 1) * (j + 1)]) {
                vis[(i - 1) * (j + 1)] = true;
                st.insert((i - 1) * (j + 1));
                q.push((i - 1) * (j + 1));
            }
        }
    }
}

void testcase() {
    int n; cin >> n;
    bfs(n);
    cout << st.size() - 1 << el;
    for (auto x : st) {
        if (x == n) continue;
        cout << x << ' ';
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