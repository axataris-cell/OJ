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

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "D"

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

void testcase() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<string> grid(n);
    int sx = -1, sy = -1;
    
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'X') {
                sx = i;
                sy = j;
            }
        }
    }
    
    if (k % 2 != 0) {
        cout << "IMPOSSIBLE" << el;
        return;
    }
    
    vector<vector<int>> dist(n, vector<int>(m, INF));
    queue<pii> q;
    
    q.push({sx, sy});
    dist[sx][sy] = 0;
    
    int dx[] = {1, 0, 0, -1};
    int dy[] = {0, -1, 1, 0};
    char dch[] = {'D', 'L', 'R', 'U'};
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '*' && dist[nx][ny] == INF) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    string ans = "";
    int cx = sx, cy = sy;
    
    for (int step = 1; step <= k; ++step) {
        bool moved = false;w
        for (int i = 0; i < 4; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '*') {
                if (dist[nx][ny] <= k - step) {
                    cx = nx;
                    cy = ny;
                    ans += dch[i];
                    moved = true;
                    break;
                }
            }
        }
        if (!moved) {
            cout << "IMPOSSIBLE" << el;
            return;
        }
    }
    
    cout << ans << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1;
    while (t--) testcase();

    return 0;
}