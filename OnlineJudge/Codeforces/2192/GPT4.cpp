#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = (ll)4e18;

struct LiChao {
    struct Line {
        ll m, b; // y = m*x + b
        Line(ll _m = 0, ll _b = -INF) : m(_m), b(_b) {}
        ll get(ll x) const {
            return m * x + b;
        }
    };

    struct Node {
        Line line;
        Node *l = nullptr, *r = nullptr;
        Node(Line v) : line(v) {}
    };

    ll s, e;
    Node* root;

    LiChao(ll _s, ll _e) : s(_s), e(_e), root(nullptr) {}

    void add_line(Line nw, ll l, ll r, Node*& node) {
        if (!node) {
            node = new Node(nw);
            return;
        }
        ll mid = (l + r) >> 1;

        bool left = nw.get(l) > node->line.get(l);
        bool middle = nw.get(mid) > node->line.get(mid);

        if (middle) {
            swap(nw, node->line);
        }

        if (r - l == 1) return;

        if (left != middle) {
            add_line(nw, l, mid, node->l);
        } else {
            add_line(nw, mid, r, node->r);
        }
    }

    void add_line(ll m, ll b) {
        Line nw(m, b);
        add_line(nw, s, e, root);
    }

    ll query(ll x, ll l, ll r, Node* node) const {
        if (!node) return -INF;
        ll res = node->line.get(x);
        if (r - l == 1) return res;
        ll mid = (l + r) >> 1;
        if (x < mid && node->l)
            return max(res, query(x, l, mid, node->l));
        if (x >= mid && node->r)
            return max(res, query(x, mid, r, node->r));
        return res;
    }

    ll query(ll x) const {
        return query(x, s, e, root);
    }

    // merge another LiChao into this
    void merge(Node* node, ll l, ll r) {
        if (!node) return;
        add_line(node->line.m, node->line.b);
        if (node->l) merge(node->l, l, (l + r) >> 1);
        if (node->r) merge(node->r, (l + r) >> 1, r);
    }

    void merge(LiChao& other) {
        merge(other.root, s, e);
    }
};

const int MAXN = 200005;

int n;
ll a[MAXN];
vector<int> adj[MAXN];

ll depth_[MAXN];
ll sz[MAXN];
ll base_cost[MAXN];
ll maxDepth[MAXN];
ll ans[MAXN];

void dfs1(int u, int p, ll d) {
    depth_[u] = d;
    sz[u] = a[u];
    base_cost[u] = 0;
    maxDepth[u] = d;

    for (int v : adj[u]) {
        if (v == p) continue;
        dfs1(v, u, d + 1);
        sz[u] += sz[v];
        base_cost[u] += base_cost[v] + sz[v];
        maxDepth[u] = max(maxDepth[u], maxDepth[v]);
    }
}

LiChao* dfs2(int u, int p) {
    LiChao* cur = new LiChao(0, n + 5);

    for (int v : adj[u]) {
        if (v == p) continue;
        LiChao* child = dfs2(v, u);
        if (child->root) {
            if (cur->root == nullptr) {
                swap(cur, child);
            } else {
                cur->merge(*child);
            }
        }
    }

    ll bestGain = 0;
    if (cur->root) {
        bestGain = cur->query(maxDepth[u]);
        bestGain = max(bestGain, 0LL);
    }

    ans[u] = base_cost[u] + bestGain;

    // add line of u after query (u cannot move itself)
    ll m = sz[u];
    ll b = -depth_[u] * sz[u];
    cur->add_line(m, b);

    return cur;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            adj[i].clear();
        }

        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs1(1, 0, 0);
        dfs2(1, 0);

        for (int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}