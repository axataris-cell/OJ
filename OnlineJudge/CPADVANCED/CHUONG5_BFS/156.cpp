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
// Created: 2026-03-26 19:52

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "156"

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
int cs, ct;
pii s, t;

char g[MAXN][MAXN];
int dist[5][4][MAXN][MAXN];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool valid(int x, int y) {
    return x >= 1 && y >= 1 && x <= n && y <= m;
}

void bfs() {
    pqueue<tuple<int,int,int,int,int>, vector<tuple<int,int,int,int,int>>, greater<>> q;
    // dist, x, y, direction, color

    q.push({0, s.fi, s.se, 0, cs - 1});
    dist[cs - 1][0][s.fi][s.se] = 0;

    while (q.size()) {
        auto [d, x, y, k, c] = q.top(); q.pop();
        if (d > dist[c][k][x][y]) continue;

        int nc = (c + 1) % 5;

        // forward
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (valid(nx, ny) && g[nx][ny] != '#') {
                if (dist[nc][k][nx][ny] > d + 1) {
                    dist[nc][k][nx][ny] = d + 1;
                    q.push({d + 1, nx, ny, k, nc});
                }
            }
        }

        // turn right
        {
            int nk = (k + 1) % 4;
            if (dist[c][nk][x][y] > d + 1) {
                dist[c][nk][x][y] = d + 1;
                q.push({d + 1, x, y, nk, c});
            }
        }

        // turn left
        {
            int nk = (k + 3) % 4;
            if (dist[c][nk][x][y] > d + 1) {
                dist[c][nk][x][y] = d + 1;
                q.push({d + 1, x, y, nk, c});
            }
        }
    }
}

void testcase() {
    cin >> n >> m;
    cin >> cs >> ct;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'S') s = {i, j};
            if (g[i][j] == 'T') t = {i, j};
            for (int lon = 0; lon < 5; lon++) {
                for (int bruh = 0; bruh < 4; bruh++) {
                    dist[lon][bruh][i][j] = INF;
                }
            }
        }
    }
    bfs();
    int res = INF;
    for (int i = 0; i < 4; i++) res = min(res, dist[ct - 1][i][t.fi][t.se]);
    
    cout << (res == INF ? -1 : res);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}