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
// Created: 2026-05-06 08:46

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "I"

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

int n, m;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

bool valid(int x, int y) {return x < n && x >= 0 && y < m && y >= 0;}
int id(int x, int y) {return x * m + y;}

void testcase() {
    vector<vector<char>> g(n, vector<char>(m));
    pii start;
    vector<pii> pos;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'o') start = {i, j};
            if (g[i][j] == '*') pos.pb({i, j});
        }
    }

    int k = pos.size();

    if (k == 0) {
        cout << 0 << el;
        return;
    }
    vector<vector<int>> distance(k, vector<int>(k, 0));

    for (int i = 0; i < k; i++) {
        int idx = id(pos[i].fi, pos[i].se);

        vector<int> dist(m * n, -1);
        vector<bool> vis(m * n, false);
        queue<pii> q;
        
        q.emplace(pos[i].fi, pos[i].se);
        vis[idx] = true;
        dist[idx] = 0;

        while (q.size()) {
            auto [x, y] = q.front(); q.pop();
            for (int ro = 0; ro < 4; ro++) {
                int nx = x + dx[ro];
                int ny = y + dy[ro];
                if (valid(nx, ny) && g[nx][ny] != 'x' && !vis[id(nx, ny)]) {
                    vis[id(nx, ny)] = true;
                    dist[id(nx, ny)] = dist[id(x, y)] + 1;
                    q.emplace(nx, ny);
                }
            }
        }

        for (int j = 0; j < k; j++) {
            if (i == j) continue;
            if (dist[id(pos[j].fi, pos[j].se)] == -1) {
                cout << -1 << el;
                return;
            }
            distance[i][j] = dist[id(pos[j].fi, pos[j].se)];
        }
    }

    vector<vector<int>> dp(k, vector<int>(1 << k, INF));

    // base
    {
        int idx = id(start.fi, start.se);
        vector<int> dist(m * n, -1);
        vector<bool> vis(m * n, false);
        queue<pii> q;
        
        q.emplace(start.fi, start.se);
        vis[idx] = true;
        dist[idx] = 0;

        while (q.size()) {
            auto [x, y] = q.front(); q.pop();
            for (int ro = 0; ro < 4; ro++) {
                int nx = x + dx[ro];
                int ny = y + dy[ro];
                if (valid(nx, ny) && g[nx][ny] != 'x' && !vis[id(nx, ny)]) {
                    vis[id(nx, ny)] = true;
                    dist[id(nx, ny)] = dist[id(x, y)] + 1;
                    q.emplace(nx, ny);
                }
            }
        }

        for (int i = 0; i < k; i++) {
            if (dist[id(pos[i].fi, pos[i].se)] == -1) {
                cout << -1 << el;
                return;
            }
            dp[i][1 << i] = dist[id(pos[i].fi, pos[i].se)];
        }
    }

    for (int mask = 0; mask < (1 << k); mask++) {
        for (int i = 0; i < k; i++) {
            if (!((mask >> i) & 1)) continue;
            for (int j = 0; j < k; j++) {
                if (!((mask >> j) & 1) || i == j) continue;
                dp[i][mask] = min(dp[i][mask], dp[j][mask ^ (1 << i)] + distance[j][i]);
            }
        }
    }

    int res = INF;
    for (int i = 0; i < k; i++) {
        res = min(res, dp[i][(1 << k) - 1]);
    }

    cout << res << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    // cin >> m >> n;
    // testcase();
    // return 0;

    while (cin >> m >> n) {
        if (n == 0 || m == 0) return 0;
        testcase();
    }

    return 0;
}