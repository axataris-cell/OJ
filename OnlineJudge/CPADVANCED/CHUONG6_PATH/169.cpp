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
// Created: 2026-03-28 18:29

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "169"

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

int g[MAXN][MAXN];
int par[MAXN][MAXN];
int dist[MAXN][MAXN];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool valid(int x, int y) {
    return x >= 1 && y >= 1 && x <= n && y <= m;
}

void reset() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            par[i][j] = -1;
            dist[i][j] = INF;
        }
    }
}

struct State {
    int x;
    int y;
    int dist;

    bool operator()(const State &x, const State &y) {
        return x.dist > y.dist;
    }
};

void dijkstra(pii s) {
    pqueue<State, vector<State>, State> pq;

    pq.push({s.fi, s.se, 0});
    dist[s.fi][s.se] = g[s.fi][s.se];

    while (pq.size()) {
        auto [x, y, d] = pq.top(); pq.pop();
        if (d > dist[x][y]) continue;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (valid(nx, ny)) {
                int w = g[nx][ny];
                if (dist[nx][ny] > dist[x][y] + w) {
                    dist[nx][ny] = dist[x][y] + w;
                    par[nx][ny] = i;
                    pq.push({nx, ny, dist[nx][ny]});
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
    int bestdist = INF;
    pii bestnode;
    pii endnode;
    for (int i = 1; i <= n; i++) {
        reset();
        dijkstra({i, 1});
        int mn = INF;
        pii end;
        for (int j = 1; j <= n; j++) {
            if (dist[j][m] < mn) {
                end = {j, m};
                mn = dist[j][m];
            }
        }
        if (mn < bestdist) {
            bestdist = mn;
            bestnode = {i, 1};
            endnode = end;
        }
    }
    reset();
    dijkstra(bestnode);
    pii cur = endnode;
    vector<pii> path;
    while (par[cur.fi][cur.se] != -1) {
        path.pb(cur);
        auto [x, y] = cur;
        int k = par[x][y];
        if (k == 0) --cur.fi;
        if (k == 1) ++cur.fi;
        if (k == 2) --cur.se;
        if (k == 3) ++cur.se;
    }
    path.pb(bestnode);
    reverse(all(path));
    cout << bestdist << el;
    for (auto x : path) cout << x.fi << ' ' << x.se << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}