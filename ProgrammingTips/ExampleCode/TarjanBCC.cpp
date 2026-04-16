#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 100005;
const int MAXM = 200005;

struct Edge {
    int v, id;
};

int n, m;
vector<Edge> adj[MAXN];
vector<pair<int, int>> edge_list;

int num[MAXN], low[MAXN], timer = 0;
bool is_bridge[MAXM];

// --- Disjoint Set Union (DSU) ---
int parent_node[MAXN];

int find_set(int v) {
    return v == parent_node[v] ? v : parent_node[v] = find_set(parent_node[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) parent_node[b] = a;
}

// --- Cây sau khi nén các 2-EBC ---
vector<int> tree_adj[MAXN];
bool visited[MAXN];

// 1. DFS tìm cầu
void dfs_bridge(int u, int p_edge) {
    num[u] = low[u] = ++timer;
    for (Edge e : adj[u]) {
        if (e.id == p_edge) continue; // Bỏ qua cạnh vừa đi tới
        
        int v = e.v;
        if (num[v]) {
            low[u] = min(low[u], num[v]);
        } else {
            dfs_bridge(v, e.id);
            low[u] = min(low[u], low[v]);
            // Nếu không có đường nào từ nhánh con đi ngược lên trên u
            if (low[v] == num[v]) {
                is_bridge[e.id] = true;
            }
        }
    }
}

// 2. BFS tìm đỉnh xa nhất để tính đường kính cây
pair<int, int> bfs(int start) {
    queue<int> q;
    vector<int> dist(n + 1, -1);
    
    q.push(start);
    dist[start] = 0;
    
    int farthest_node = start;
    int max_dist = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        visited[u] = true; // Đánh dấu đã duyệt qua đỉnh này trong rừng
        
        for (int v : tree_adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
                if (dist[v] > max_dist) {
                    max_dist = dist[v];
                    farthest_node = v;
                }
            }
        }
    }
    return {farthest_node, max_dist};
}

int main() {
    // Tối ưu I/O và cấu hình đọc/ghi file
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("BAI4.INP", "r")) {
        freopen("BAI4.INP", "r", stdin);
        freopen("BAI4.OUT", "w", stdout);
    }

    if (!(cin >> n >> m)) return 0;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
        edge_list.push_back({u, v});
    }

    // Bước 1: Tìm tất cả các cầu
    for (int i = 1; i <= n; ++i) {
        if (!num[i]) {
            dfs_bridge(i, -1);
        }
    }

    // Bước 2: Dùng DSU gộp các đỉnh không bị chia cắt bởi cầu
    for (int i = 1; i <= n; ++i) parent_node[i] = i;
    for (int i = 0; i < m; ++i) {
        if (!is_bridge[i]) {
            union_sets(edge_list[i].first, edge_list[i].second);
        }
    }

    // Bước 3: Dựng đồ thị mới (cây/rừng) chứa các siêu đỉnh
    for (int i = 0; i < m; ++i) {
        if (is_bridge[i]) {
            int u = find_set(edge_list[i].first);
            int v = find_set(edge_list[i].second);
            tree_adj[u].push_back(v);
            tree_adj[v].push_back(u);
        }
    }

    // Bước 4: Tìm đường kính lớn nhất trong các cây của rừng
    int max_diameter = 0;
    for (int i = 1; i <= n; ++i) {
        int root = find_set(i);
        // Nếu siêu đỉnh này chưa được thăm (thuộc một cây mới trong rừng)
        if (!visited[root]) {
            // Lần BFS 1: Tìm đỉnh A xa gốc nhất
            pair<int, int> p1 = bfs(root);
            
            // Lần BFS 2: Tìm đỉnh B xa đỉnh A nhất. Khoảng cách A->B là đường kính.
            pair<int, int> p2 = bfs(p1.first);
            
            max_diameter = max(max_diameter, p2.second);
        }
    }

    // Kết quả
    cout << max_diameter << "\n";

    return 0;
}