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
// Created: 2026-04-03 16:00

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "RAILGUN"

using namespace std;
using pii = pair<ll, ll>;
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

#define int long long

const int MAXN = 1e3 + 5;

int n;
pii s, t;

char g[MAXN][MAXN];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool valid(int x, int y) {
    return x >= 1 && y >= 1 && x <= n && y <= n;
}

void solve(int a, int b) {
    
}

vector<vector<int>> dist(MAXN, vector<int>(MAXN, INF));
vector<vector<bool>> vis(MAXN, vector<bool>(MAXN, 0));

void sub2() {
    queue<pii> q;

    q.emplace(s.fi, s.se);
    dist[s.first][s.second] = 0;

    while (q.size()) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!valid(nx, ny) || vis[nx][ny] || g[nx][ny] == '#') continue;
            vis[nx][ny] = true;
            dist[nx][ny] = dist[x][y] + 1;
            q.emplace(nx, ny);
        }
    }
}

void testcase() {
    cin >> n;
    cin >> s.fi >> s.se >> t.fi >> t.se;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> g[i][j];
        }
    }
    // if (n == 2) {
    //     bool bruh = false;
    //     for (int i = 0; i < 4; i++) {
    //         int x = s.fi + dx[i];
    //         int y = s.se + dy[i];
    //         if (make_pair(x, y) == t) {
    //             bruh = true;
    //         }
    //     }
    //     int q; cin >> q;
    //     while (q--) {
    //         int a, b; cin >> a >> b;
    //         if (bruh) cout << 2 * b << el;
    //         else {
    //             cout << a + 2 * b << el;
    //         }
    //     }
    //     return;
    // }
    sub2();
    int q; cin >> q;
    while (q--) {
        int a, b; cin >> a >> b;
        cout << dist[t.fi][t.se] * b << el;
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