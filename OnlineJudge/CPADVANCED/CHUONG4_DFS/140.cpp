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
// Created: 2026-03-24 17:21

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "140"

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

const int MAXN = 1e2 + 5;

int n, m;

char g[MAXN][MAXN];
bool visGrass[MAXN][MAXN];
bool visMachi[MAXN][MAXN];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int movx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int movy[8] = {1, -1, 0, 0, 1, 1, -1, -1};

bool valid(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

void dfs(pii u) {
    int x = u.first;
    int y = u.second;
    visMachi[x][y] = true;
    
    bool ok = true;
    for (int i = 0; i < 8; i++) {
        int nx = x + movx[i];
        int ny = y + movy[i];
        if (!valid(nx, ny)) {
            ok = false;
            break;
        } else {
            if (g[nx][ny] == '+') {
                ok = false;
                break;
            }
        }
    }
    if (!ok) return;
    
    for (int i = 0; i < 8; i++) {
        int nx = x + movx[i];
        int ny = y + movy[i];
        if (valid(nx, ny)) {
            visGrass[nx][ny] = true;
            // g[nx][ny] = 'O';
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         if (i == x && j == y) cout << 'M';
    //         else cout << g[i][j];
    //     }
    //     cout << el;
    // }
    // cout << el;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (valid(nx, ny) && !visMachi[nx][ny]) {
            dfs({nx, ny});
        }
    }
}
void testcase() {
    cin >> n >> m;
    pii s;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'M') s = {i, j};
        }
    }
    dfs(s);
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // cout << g[i][j];
            if (visGrass[i][j]) ++res;
        }
        // cout << el;
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