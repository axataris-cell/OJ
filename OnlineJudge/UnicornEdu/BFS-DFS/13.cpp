#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300000 + 5;

int n, m;
vector<int> adj[MAXN];

int tin[MAXN], low[MAXN]; // tin là num
bool visited[MAXN];
int timer = 0;

/*
 compCnt[u]: số thành phần liên thông tạo ra
 khi xóa đỉnh u (DFS component hiện tại)
*/
int compCnt[MAXN];

void dfs(int u, int parent) {
    visited[u] = true;
    tin[u] = low[u] = ++timer;

    int children = 0;      // số con DFS
    int cutParts = 0;      // số nhánh bị tách

    for (int v : adj[u]) {
        if (v == parent) continue;

        if (!visited[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            children++;

            if (low[v] >= tin[u]) {
                cutParts++;
            }
        } else {
            low[u] = min(low[u], tin[v]);
        }
    }

    if (parent == -1) {
        // u là gốc DFS
        compCnt[u] = children;
    } else {
        if (cutParts > 0)
            compCnt[u] = cutParts + 1;
        else
            compCnt[u] = 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int initialComponents = 0;

    // DFS trên từng thành phần liên thông
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            initialComponents++;
            dfs(i, -1);
        }
    }

    int bestC = -1;
    int bestNode = 1;

    for (int i = 1; i <= n; i++) {
        int totalComponents;

        if (initialComponents == 1) {
            // đồ thị ban đầu liên thông
            totalComponents = compCnt[i];
        } else {
            /*
             Khi xóa i:
             - thành phần chứa i bị tách thành compCnt[i]
             - các thành phần khác giữ nguyên
            */
            totalComponents = compCnt[i] + (initialComponents - 1);
        }

        if (totalComponents > bestC) {
            bestC = totalComponents;
            bestNode = i;
        }
    }

    cout << bestC << " " << bestNode << "\n";
    return 0;
}
