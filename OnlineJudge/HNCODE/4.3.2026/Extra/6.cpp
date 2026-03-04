#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 4e18;

/* ================= DINIC ================= */

struct Dinic {
    struct Edge {
        int v;
        ll cap;
        int rev;
    };

    int n;
    vector<vector<Edge>> adj;
    vector<int> level, ptr;
    int s, t;

    Dinic(int n) : n(n), adj(n), level(n), ptr(n) {}

    void add_edge(int u, int v, ll cap) {
        Edge a = {v, cap, (int)adj[v].size()};
        Edge b = {u, 0, (int)adj[u].size()};
        adj[u].push_back(a);
        adj[v].push_back(b);
    }

    bool bfs() {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        q.push(s);
        level[s] = 0;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto &e : adj[u]) {
                if (e.cap > 0 && level[e.v] == -1) {
                    level[e.v] = level[u] + 1;
                    q.push(e.v);
                }
            }
        }
        return level[t] != -1;
    }

    ll dfs(int u, ll pushed) {
        if (pushed == 0) return 0;
        if (u == t) return pushed;

        for (int &cid = ptr[u]; cid < (int)adj[u].size(); cid++) {
            Edge &e = adj[u][cid];
            if (e.cap > 0 && level[e.v] == level[u] + 1) {
                ll tr = dfs(e.v, min(pushed, e.cap));
                if (tr == 0) continue;
                e.cap -= tr;
                adj[e.v][e.rev].cap += tr;
                return tr;
            }
        }
        return 0;
    }

    ll maxflow(int source, int sink) {
        s = source;
        t = sink;
        ll flow = 0;
        while (bfs()) {
            fill(ptr.begin(), ptr.end(), 0);
            while (ll pushed = dfs(s, INF)) {
                flow += pushed;
            }
        }
        return flow;
    }
};

/* ================= MAIN ================= */

int N, M;

vector<ll> costRoad;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    costRoad.resize(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> costRoad[i];

    // ===== Node indexing =====
    // 0 = source
    // 1 = sink
    // next: project nodes
    // next: segment tree nodes
    // next: road nodes

    int SOURCE = 0;
    int SINK = 1;

    int projectStart = 2;
    int segStart = projectStart + M;

    int segNodeCnt = 4 * N;
    int roadStart = segStart + segNodeCnt;

    int totalNodes = roadStart + N + 5;

    Dinic dinic(totalNodes);

    ll totalProfit = 0;

    // ===== Read projects =====
    vector<int> L(M + 1), R(M + 1);
    vector<ll> V(M + 1);

    for (int i = 1; i <= M; i++) {
        cin >> L[i] >> R[i] >> V[i];
        totalProfit += V[i];

        int projectNode = projectStart + i - 1;
        dinic.add_edge(SOURCE, projectNode, V[i]);
    }

    // ===== Build segment tree edges =====

    function<void(int,int,int)> build = [&](int id, int l, int r) {
        int nodeId = segStart + id;

        if (l == r) {
            int roadNode = roadStart + l - 1;
            dinic.add_edge(nodeId, roadNode, INF);
            return;
        }

        int mid = (l + r) >> 1;
        int leftId = id << 1;
        int rightId = id << 1 | 1;

        dinic.add_edge(nodeId, segStart + leftId, INF);
        dinic.add_edge(nodeId, segStart + rightId, INF);

        build(leftId, l, mid);
        build(rightId, mid + 1, r);
    };

    build(1, 1, N);

    // ===== Connect projects to segment tree =====

    function<void(int,int,int,int,int,int)> add_interval =
        [&](int id, int l, int r, int ql, int qr, int projNode) {

        if (qr < l || r < ql) return;

        if (ql <= l && r <= qr) {
            dinic.add_edge(projNode, segStart + id, INF);
            return;
        }

        int mid = (l + r) >> 1;
        add_interval(id << 1, l, mid, ql, qr, projNode);
        add_interval(id << 1 | 1, mid + 1, r, ql, qr, projNode);
    };

    for (int i = 1; i <= M; i++) {
        int projNode = projectStart + i - 1;
        add_interval(1, 1, N, L[i], R[i], projNode);
    }

    // ===== Road to sink =====
    for (int i = 1; i <= N; i++) {
        int roadNode = roadStart + i - 1;
        dinic.add_edge(roadNode, SINK, costRoad[i]);
    }

    ll maxFlow = dinic.maxflow(SOURCE, SINK);

    cout << totalProfit - maxFlow << "\n";

    return 0;
}