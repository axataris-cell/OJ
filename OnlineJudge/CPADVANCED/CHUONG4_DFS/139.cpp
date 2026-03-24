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

char g[MAXN][MAXN];
int res = 0;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
map<pii, bool> vis;

bool valid(int x, int y) {
    return x <= n && x >= 1 && y <= m && y >= 1;
}

bool ok = true;
int area = 0;
void dfs(pii u) {
    int x = u.first;
    int y = u.second;
    vis[{x, y}] = true;
    // cout << x << ' ' << y << el;
    ++area;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (valid(nx, ny) && g[nx][ny] != '1' && !vis[{nx, ny}]) {
            dfs({nx, ny});
        } else if (!valid(nx, ny)) {
            ok = false;
        }
    }
}

void testcase() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!vis[{i, j}] && g[i][j] != '1') {
                area = 0;
                ok = true;
                dfs({i, j});
                if (ok) res = max(res, area);
            }
        }
    }

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