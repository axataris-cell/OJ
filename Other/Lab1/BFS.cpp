#include <bits/stdc++.h>
using namespace std;

const int maxN = 100005;

int n, m;
int d[maxN], par[maxN];
bool visit[maxN];
vector<int> g[maxN];

void bfs(int s) {
    fill_n(d, n + 1, 0);
    fill_n(par, n + 1, -1);
    fill_n(visit, n + 1, false);

    queue<int> q;
    q.push(s);
    visit[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (!visit[v]) {
                visit[v] = true;
                d[v]   = d[u] + 1;
                par[v] = u;
                q.push(v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int s;
    cin >> n >> m >> s;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u); // nếu là đồ thị có hướng thì bỏ cái này đi (vì không có đường liên thông 2 chiều)
    }

    bfs(s);

    for (int i = 1; i <= n; i++) {
        if (visit[i]) {
            cout << i << ": " << d[i] << '\n';
        } else {
        	cout << -1 << '\n';
        }
    }

    return 0;
}
