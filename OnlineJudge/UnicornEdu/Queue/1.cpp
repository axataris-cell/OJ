#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
vector<pair<int,int>> adj[N];
int n, m;
int timer = 0;
int low[N], tin[N];
bool visitedEdge[5005];

// lưu cạnh để tạo BCC
stack<pair<int,int>> st;

vector<int> compNodes;
vector<pair<int,int>> compEdges;

vector<vector<pair<int,int>>> BCC; // tập các cạnh trong từng BCC

void addBCC(pair<int,int> e) {
    vector<pair<int,int>> bcc;
    while (!st.empty()) {
        auto x = st.top(); st.pop();
        bcc.push_back(x);
        if (x == e) break;
    }
    BCC.push_back(bcc);
}

void dfs(int u, int parent) {
    tin[u] = low[u] = ++timer;

    for (auto [v, id] : adj[u]) {
        if (id == parent) continue;
        if (!tin[v]) {
            st.push({u, v});
            dfs(v, id);
            low[u] = min(low[u], low[v]);
            if (low[v] >= tin[u]) {
                addBCC({u, v});
            }
        } else if (tin[v] < tin[u]) {
            st.push({u, v});
            low[u] = min(low[u], tin[v]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; 
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    for (int i = 1; i <= n; i++)
        if (!tin[i]) dfs(i, -1);

    long long answer = 0;

    for (auto &bcc : BCC) {
        // đếm đỉnh / cạnh
        unordered_set<int> nodes;
        for (auto &e : bcc) {
            nodes.insert(e.first);
            nodes.insert(e.second);
        }
        int E = bcc.size();
        int V = nodes.size();

        if (E >= V) {
            answer += (E - V + 1);
        }
    }

    cout << answer << "\n";
    return 0;
}
