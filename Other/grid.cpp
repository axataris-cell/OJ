#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;

int n;
int a[MAXN][MAXN];
bool visit[MAXN][MAXN];
pair<int,int> par[MAXN][MAXN];

// 4 hướng di chuyển
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool valid(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= n;
}

void bfs() {
    queue<pair<int,int>> q;
    q.push({1, 1});
    visit[1][1] = true;
    par[1][1] = {-1, -1};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (valid(nx, ny) && !visit[nx][ny] && a[nx][ny] == 0) {
                visit[nx][ny] = true;
                par[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    // Nếu ô đầu hoặc ô cuối là vật cản
    if (a[1][1] == 1 || a[n][n] == 1) {
        cout << "Khong co duong di\n";
        return 0;
    }

    bfs();

    // Không đi tới được đích
    if (!visit[n][n]) {
        cout << "Khong co duong di\n";
        return 0;
    }

    // Truy vết đường đi
    vector<pair<int,int>> path;
    for (int x = n, y = n; x != -1; ) {
        path.push_back({x, y});
        auto p = par[x][y];
        x = p.first;
        y = p.second;
    }
    reverse(path.begin(), path.end());

    // In kết quả
    cout << "Duong di ngan nhat:\n";
    for (auto [x, y] : path) {
        cout << "(" << x << ", " << y << ") ";
    }
    cout << "\n";

    return 0;
}
