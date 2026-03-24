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
// Created: 2026-03-24 16:59

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "138"

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

const int MAXN = 1e3 + 5;

int n, m;
pii s, t;

bool ok = false;

char g[MAXN][MAXN];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char mov[4] = {'R', 'L', 'D', 'U'};

map<pii, bool> vis;

stack<char> st;

bool valid(int x, int y) {
    return x <= n && x >= 1 && y <= m && y >= 1;
}

void dfs(pii u) {
    int x = u.first;
    int y = u.second;
    vis[{x, y}] = true;
    if (t.fi == x && t.se == y) {
        ok = true;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        bool go = false;
        if (valid(nx, ny) && !vis[{nx, ny}] && g[nx][ny] != '#') {
            st.push(mov[i]);
            go = true;
            dfs({nx, ny});
        }
        if (ok) return;
        if (go) st.pop();
    }
}

void testcase() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'A') s = {i, j};
            if (g[i][j] == 'B') t = {i, j};
        }
    }
    dfs(s);

    if (!ok) {
        cout << "NO" << el;
        return;
    }
    string res = "";
    while (st.size()) {
        res.pb(st.top());
        st.pop();
    }
    reverse(all(res));

    cout << "YES" << el;
    cout << res.len() << el;
    cout << res;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}