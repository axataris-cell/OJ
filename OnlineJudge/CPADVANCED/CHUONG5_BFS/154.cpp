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
// Created: 2026-03-25 21:14

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "154"

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

int g[MAXN][MAXN];
vector<vector<int>> dist(MAXN, vector<int>(MAXN, INF));

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool valid(int x, int y) {
    return x >= 1 && y >= 1 && x <= n && y <= m;
}

void bfs() {
    deque<pii> q;

    for (int i = 1; i <= n; i++) {
        q.push_front({i, 1});
        dist[i][1] = 1;
    }

    while (q.size()) {
        pii u = q.front(); q.pop_front();
        int x = u.fi, y = u.se;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (valid(nx, ny)) {
                if (g[nx][ny] != g[x][y]) {
                    if (dist[nx][ny] > dist[x][y] + 1) {
                        dist[nx][ny] = dist[x][y] + 1;
                        q.push_back({nx, ny});
                    }
                } else {
                    if (dist[nx][ny] > dist[x][y]) {
                        dist[nx][ny] = dist[x][y];
                        q.push_front({nx, ny});
                    }
                }
            }
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
    bfs();
    int res = INF;
    for (int i = 1; i <= n; i++) {
        res = min(dist[i][m], res);
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