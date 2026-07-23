#include<bits/stdc++.h>

using namespace std;

const int N = 200005;

int n, k, child[N], del[N]; // del[u] để kiểm tra đỉnh u có bị xóa hay chưa
vector<int> adj[N];

void countChild(int u, int parent) {
    child[u] = 1;
    for (int v : adj[u]) if (v != parent && !del[v]) {
        countChild(v, u);
        child[u] += child[v];
    }
}

int centroid(int u, int parent, int n) {
    for (int v : adj[u])
        if (v != parent && child[v] > n/2 && !del[v])
            return centroid(v, u, n);
    return u;
}

void updateAns(int root, int n) {
    //hàm thực hiện bước 2
}

long long solve(int u) {
    countChild(u, 0);

    int n = child[u];
    int root = centroid(u, 0, n); // bước 1

    updateAns(root, n); // bước 2

    ans = 0;
    del[root] = 1;
    for (int v : adj[root]) if (!del[v])
            ans += solve(v); // bước 3

    return ans;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << solve(1);

    return 0;
}