#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 31011;

struct Edge {
    int u, v, w;
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.w < b.w;
}

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        for (int i = 1; i <= n; ++i) parent[i] = i;
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return find(parent[i]); // Không dùng path compression để giữ nguyên cấu trúc khi backtracking
    }
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            return true;
        }
        return false;
    }
};

int n, m;
vector<Edge> edges;
struct Group {
    int l, r, count;
};
vector<Group> groups;

int temp_count;
void backtrack(int edge_idx, int target_r, int needed, DSU& dsu) {
    if (needed == 0) {
        temp_count++;
        return;
    }
    if (edge_idx > target_r) return;

    // Thử chọn cạnh edge_idx
    int u = edges[edge_idx].u;
    int v = edges[edge_idx].v;
    int root_u = dsu.find(u);
    int root_v = dsu.find(v);

    if (root_u != root_v) {
        int old_root = dsu.parent[root_u];
        dsu.parent[root_u] = root_v;
        backtrack(edge_idx + 1, target_r, needed - 1, dsu);
        dsu.parent[root_u] = old_root; // Backtrack
    }

    // Thử không chọn cạnh edge_idx
    backtrack(edge_idx + 1, target_r, needed, dsu);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> m)) return 0;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    sort(edges.begin(), edges.end(), compareEdges);

    DSU dsu_main(n);
    for (int i = 0; i < m; ) {
        int j = i;
        while (j < m && edges[j].w == edges[i].w) j++;
        
        int needed = 0;
        DSU dsu_temp = dsu_main;
        for (int k = i; k < j; ++k) {
            if (dsu_temp.unite(edges[k].u, edges[k].v)) {
                needed++;
            }
        }
        
        if (needed > 0) {
            groups.push_back({i, j - 1, needed});
            // Cập nhật dsu_main cho các nhóm trọng số sau
            for (int k = i; k < j; ++k) {
                int root_u = dsu_main.find(edges[k].u);
                int root_v = dsu_main.find(edges[k].v);
                if (root_u != root_v) dsu_main.parent[root_u] = root_v;
            }
        }
        i = j;
    }

    if (groups.empty() && n > 1) {
        cout << 0 << endl;
        return 0;
    }

    // Kiểm tra tính kết nối của đồ thị
    int components = 0;
    for (int i = 1; i <= n; ++i) if (dsu_main.parent[i] == i) components++;
    if (components > 1) {
        cout << 0 << endl;
        return 0;
    }

    long long total_mst = 1;
    DSU dsu_final(n);
    for (const auto& g : groups) {
        temp_count = 0;
        backtrack(g.l, g.r, g.count, dsu_final);
        total_mst = (total_mst * temp_count) % MOD;
        
        // Sau khi tính số cách cho nhóm này, gộp các đỉnh trong dsu_final
        for (int k = g.l; k <= g.r; ++k) {
            int root_u = dsu_final.find(edges[k].u);
            int root_v = dsu_final.find(edges[k].v);
            if (root_u != root_v) dsu_final.parent[root_u] = root_v;
        }
    }

    cout << total_mst << endl;

    return 0;
}