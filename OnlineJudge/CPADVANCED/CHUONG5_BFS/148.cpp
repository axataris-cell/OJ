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
// Created: 2026-03-25 09:16

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "148"

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

char g[MAXN][MAXN];
bool vis[MAXN][MAXN];
char par[MAXN][MAXN];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char mov[4] = {'L', 'R', 'U', 'D'};

bool valid(int x, int y) {
    return x >= 1 && y >= 1 && x <= n && y <= m;
}

void bfs(pii s) {
    queue<pii> q;

    q.push(s);
    vis[s.fi][s.se] = true;
    par[s.fi][s.se] = 'X';
    
    while (q.size()) {
        pii u = q.front(); q.pop();
        int x = u.fi, y = u.se;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (valid(nx, ny) && !vis[nx][ny] && g[nx][ny] != '#') {
                par[nx][ny] = mov[i];
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
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
    bfs(s);

    if (!vis[t.fi][t.se]) {
        cout << "NO" << el;
        return;
    }
    
    vector<char> path;
    char cur = par[t.fi][t.se];
    pii curpos = t;
    while (cur != 'X') {
        if (cur == 'L') {
            path.pb('R');
            --curpos.se;
        } else if (cur == 'D') {
            path.pb('U');
            ++curpos.fi;
        } else if (cur == 'U') {
            path.pb('D');
            --curpos.fi;
        } else if (cur == 'R') {
            path.pb('L');
            ++curpos.se;
        }
        cur = par[curpos.fi][curpos.se];
    }
    reverse(all(path));

    cout << "YES" << el;
    cout << path.size() << el;
    for (auto x : path) cout << x;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}