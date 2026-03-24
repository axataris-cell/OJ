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
// Created: 2026-03-24 17:45

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "141"

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
pii s;

bool g[MAXN][MAXN];
bool vis[MAXN][MAXN];

int comp[MAXN][MAXN]; // danh dau component cua tung o
int area[MAXN]; // area cua tung compononet

int best = 0;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

bool valid(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

int compcnt = 0;
void bfs(pii s) {
    queue<pii> q;

    q.push(s);
    vis[s.fi][s.se] = true;
    comp[s.fi][s.se] = compcnt;
    int ara = 0;

    while (q.size()) {
        pii u = q.front();
        int x = u.fi, y = u.se;
        comp[x][y] = compcnt;
        q.pop(); ++ara;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (valid(nx, ny) && !vis[nx][ny] && g[nx][ny] == 1) {
                vis[nx][ny] = true;
                q.emplace(nx, ny);
            }
        }
    }

    area[compcnt] = ara;
}

stack<pii> st;
bool fin = false;
void dfs(pii u) {
    int x = u.fi, y = u.se;
    vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        bool go = false;
        if (valid(nx, ny) && !vis[nx][ny]) {
            if (g[nx][ny] == 0) {
                go = true;
                st.push({nx, ny});
                dfs({nx, ny});
            } else {
                if (area[comp[nx][ny]] == best) {
                    st.push({nx, ny});
                    fin = true;
                    return;
                }
            }
        }
        if (fin) return;
        if (go) st.pop();
    }
}

void testcase() {
    cin >> n >> m >> s.fi >> s.se;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == 1 && !vis[i][j]) {
                ++compcnt;
                bfs({i, j});
                if (area[compcnt] > best) {
                    best = area[compcnt];
                }
            }
        }
    }

    cerr << el;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cerr << area[comp[i][j]] << ' ';
        }
        cerr << el;
    }
    cerr << el;

    cerr << best << el << el;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) vis[i][j] = false;
    }
    dfs(s);

    vector<pii> res;
    while (st.size()) {
        res.pb(st.top()); st.pop();
    }
    reverse(all(res));
    
    cout << res.size() << el;
    
    cout << s.fi << ' ' << s.se << el;
    for (auto x : res) {
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