#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'
#define INF 2e9
#define LINF 4e18

#define FILENAME ""

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void file() {
    if (FILE *f = fopen(FILENAME".INP", "r")) {
        fclose(f);
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
}

const int MAXN = 505;

int n, m, s, k;

char g[MAXN][MAXN];
bool vis[MAXN][MAXN];
int h[MAXN][MAXN];
bool deac[MAXN][MAXN];

struct dat{
    int x; int y;
    int height;
};

vector<dat> node;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

bool valid(int x, int y) {
    return x > 0 && x <= n && y > 0 && y <= m;
}

void dfs(int x, int y) {
    vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (!valid(nx, ny) || g[nx][ny] != '.') continue;

        if (!vis[nx][ny]) {
            h[nx][ny] = h[x][y] + 1;
            dfs(nx, ny);
        }
    }
    node.push_back({x, y, h[x][y]});
}

void testcase() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> g[i][j];
    }

    for (int i = 1; i <= n; i++) {
        bool br = false;
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == '.') {
                dfs(i, j);
                br = true;
                break;
            }
        }
        if (br) break;
    }

    sort(node.begin(), node.end(), [](dat a, dat b) {
        return a.height > b.height;
    });

    int cnt = 0;
    for (auto x : node) {
        deac[x.x][x.y] = true;
        ++cnt;
        if (cnt == k) break;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] != '.') {
                cout << g[i][j]; continue;
            } else {
                if (deac[i][j]) cout << 'X';
                else cout << '.';
            }
        }
        cout << el;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}
