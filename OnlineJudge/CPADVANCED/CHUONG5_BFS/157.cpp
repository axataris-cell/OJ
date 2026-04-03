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
// Created: 2026-04-02 17:32

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "157"

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

const int MAXN = 55;

int n, m;
int g[MAXN][MAXN];
bool vis[4][MAXN][MAXN];
int dista[4][MAXN][MAXN];
int par[4][MAXN][MAXN];

int dx[] = {0, -1, 0, 1, 0};
int dy[] = {1,  0, 0, 0, -1};
char dc[] = {'E','N','P','S','W'};

int rdx[] = {0, 1, 0, -1, 0};
int rdy[] = {-1, 0, 0, 0, 1};

bool valid(int x, int y) {
    return x >= 1 && y >= 1 && x <= n && y <= m;
}

struct Dat {
    int x, y, k;
};

void bfs(int sx, int sy) {
    queue<Dat> q;

    vis[3][sx][sy] = true;
    dista[3][sx][sy] = 0;
    par[3][sx][sy] = -1;
    q.push({sx, sy, 3});

    while (!q.empty()) {
        Dat cur = q.front(); q.pop();
        int x = cur.x;
        int y = cur.y;
        int k = cur.k;

        int t = dista[k][x][y];
        int nt = t + 1;

        for (int i = 0; i < 5; i++) {
            if (i == 2) {
                int nk = ((g[x][y] - nt) % 4 + 4) % 4;
                if (nk == 0 || vis[nk][x][y]) continue;

                vis[nk][x][y] = true;
                dista[nk][x][y] = nt;
                par[nk][x][y] = i;
                q.push({x, y, nk});
            } else {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (!valid(nx, ny)) continue;

                int nk = ((g[nx][ny] - nt) % 4 + 4) % 4;
                if (nk == 0 || vis[nk][nx][ny]) continue;

                vis[nk][nx][ny] = true;
                dista[nk][nx][ny] = nt;
                par[nk][nx][ny] = i;
                q.push({nx, ny, nk});
            }
        }
    }
}

void testcase() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
            for (int k = 0; k < 4; k++) {
                vis[k][i][j] = false;
                dista[k][i][j] = INF;
                par[k][i][j] = -1;
            }
        }
    }

    bfs(n, 1);

    int mn = INF;
    int best_k = -1;

    for (int k = 0; k < 4; k++) {
        if (dista[k][1][m] < mn) {
            mn = dista[k][1][m];
            best_k = k;
        }
    }

    cout << mn << el;

    vector<char> path;

    int cx = 1, cy = m, ck = best_k;

    while (!(cx == n && cy == 1)) {
        int dir = par[ck][cx][cy];
        int d = dista[ck][cx][cy];

        path.pb(dc[dir]);

        int px, py;

        if (dir == 2) {
            px = cx;
            py = cy;
        } else {
            px = cx + rdx[dir];
            py = cy + rdy[dir];
        }

        int pk = ((g[px][py] - (d - 1)) % 4 + 4) % 4;

        cx = px;
        cy = py;
        ck = pk;
    }

    reverse(all(path));

    for (char c : path) cout << c;
    cout << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}