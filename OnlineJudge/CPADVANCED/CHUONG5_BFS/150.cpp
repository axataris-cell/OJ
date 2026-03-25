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
// Created: 2026-03-25 20:30

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "150"

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

const int MAXN = 105;

int n, m;
pii s;
pii t = {-1, -1};

char g[MAXN][MAXN];
bool vis[MAXN][MAXN];
int par[MAXN][MAXN];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool valid(int x, int y) {
    return x >= 1 && y >= 1 && x <= n && y <= m;
}

void bfs(pii s) {
    queue<pii> q;

    q.push(s);
    vis[s.first][s.second] = true;
    par[s.first][s.second] = -1;
    
    while (q.size()) {
        pii u = q.front(); q.pop();
        int x = u.first;
        int y = u.second;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (valid(nx, ny)) {
                if (g[nx][ny] != 'X' && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    par[nx][ny] = i;
                    q.push({nx, ny});
                }
            } else {
                t = {nx, ny};
                par[nx][ny] = i;
                return;
            }
        }
    }
}
void testcase() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'E') s = {i, j};
        }
    }
    bfs(s);
    if (t.fi == -1 || t.se == -1) {
        cout << "NO";
        return;
    }

    cout << "YES" << el;

    vector<pii> path;
    pii cur = t;
    while (cur != s) {
        int p = par[cur.fi][cur.se];
        if (p == 0) {
            --cur.fi;
        } else if (p == 1) {
            ++cur.fi;
        } else if (p == 2) {
            --cur.se;
        } else if (p == 3) {
            ++cur.se;
        }
        path.pb(cur);
    }
    reverse(all(path));

    for (auto x : path) {
        cout << x.fi << ' ' << x.se << el;
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