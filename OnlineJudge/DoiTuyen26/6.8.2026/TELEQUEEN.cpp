#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define pb push_back

constexpr int INF = 1e9;
const int MAXN = 1005;

char g[MAXN][MAXN];
int dist[MAXN][MAXN];
bool vis[MAXN][MAXN][8];
bool used_portal[10];
vector<pii> portal[10];

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

struct Dat {
    int x, y, d;
};

void file() {
    if (FILE *f = fopen("TELEQUEEN.INP", "r")) {
        fclose(f);
        freopen("TELEQUEEN.INP", "r", stdin);
        freopen("TELEQUEEN.OUT", "w", stdout);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int n, m;
    if (!(cin >> n >> m)) return 0;

    pii s, t;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'S') s = {i, j};
            else if (g[i][j] == 'E') t = {i, j};
            else if (isdigit(g[i][j])) {
                portal[g[i][j] - '0'].pb({i, j});
            }
            dist[i][j] = INF;
        }
    }

    auto valid = [&](int x, int y) -> bool {
        return x >= 1 && x <= n && y >= 1 && y <= m;
    };

    deque<Dat> dq;
    dq.push_back({s.first, s.second, 0});
    dist[s.first][s.second] = 0;

    while (!dq.empty()) {
        auto [x, y, d] = dq.front();
        dq.pop_front();

        if (d > dist[x][y]) continue;

        if (isdigit(g[x][y])) {
            int p = g[x][y] - '0';
            if (!used_portal[p]) {
                used_portal[p] = true;
                for (auto [nx, ny] : portal[p]) {
                    if (dist[nx][ny] > d) {
                        dist[nx][ny] = d;
                        dq.push_front({nx, ny, d});
                    }
                }
            }
        }

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            while (valid(nx, ny) && g[nx][ny] != '#') {
                if (vis[nx][ny][i]) break;
                vis[nx][ny][i] = true;

                if (dist[nx][ny] > d + 1) {
                    dist[nx][ny] = d + 1;
                    dq.push_back({nx, ny, d + 1});
                }

                nx += dx[i];
                ny += dy[i];
            }
        }
    }

    cout << (dist[t.first][t.second] == INF ? -1 : dist[t.first][t.second]) << '\n';

    return 0;
}