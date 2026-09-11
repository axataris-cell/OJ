#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

struct lct {
    lct *l, *r, *fa;
    bool rev;

    bool isrt() {
        return fa->l != this && fa->r != this;
    }

    void D() {
        if (this == nullptr) return;
        swap(l, r);
        rev ^= 1;
    }

    void down() {
        if (!isrt()) fa->down();
        if (rev) {
            l->D();
            r->D();
            rev = 0;
        }
    }

    void rotate() {
        lct *y = fa, *z = y->fa;
        lct *k = (y->r == this) ? l : r;
        if (y->r == this) {
            l = y;
            y->r = k;
        } else {
            r = y;
            y->l = k;
        }
        if (k != nullptr) k->fa = y;
        if (!y->isrt()) {
            if (z->l == y) z->l = this;
            else z->r = this;
        }
        fa = z;
        y->fa = this;
    }

    void splay() {
        down();
        while (!isrt()) {
            lct *y = fa;
            if (!y->isrt()) {
                if ((y->fa->l == y) == (y->l == this)) y->rotate();
                else rotate();
            }
            rotate();
        }
    }
} C[MAXN], Null, *null = &Null;

lct* access(lct *x) {
    lct *y = null;
    for (; x != null; y = x, x = x->fa) {
        x->splay();
        x->r = y;
    }
    return y;
}

lct* find_root(lct *x) {
    access(x);
    x->splay();
    while (x->l != null) {
        x->down();
        x = x->l;
    }
    x->splay();
    return x;
}

void link(lct *x, lct *y) {
    access(x);
    x->splay();
    x->fa = y;
}

void cut(lct *x) {
    access(x);
    x->splay();
    x->l->fa = null;
    x->l = null;
}

int N, M, Q;
int U[MAXN], V[MAXN];
int val[MAXN];
int last[MAXN];
bool active[MAXN];
vector<pair<int, int>> adj[MAXN];
int depth[MAXN];

void bfs_orient() {
    fill(depth, depth + N + 1, -1);
    queue<int> q;
    q.push(1);
    depth[1] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto &edge : adj[u]) {
            int v = edge.first;
            int idx = edge.second;
            if (depth[v] == -1) {
                depth[v] = depth[u] + 1;
                U[idx] = u;
                V[idx] = v;
                q.push(v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M>> Q;

    null->l = null->r = null->fa = null;
    null->rev = false;

    for (int i = 1; i <= N; i++) {
        C[i].l = C[i].r = C[i].fa = null;
        C[i].rev = false;
        val[i] = 1;
    }

    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    bfs_orient();

    vector<int> edge_order(N - 1);
    iota(edge_order.begin(), edge_order.end(), 1);

    sort(edge_order.begin(), edge_order.end(), [](int e1, int e2) {
        return depth[V[e1]] > depth[V[e2]];
    });

    for (int e : edge_order) {
        int u = U[e], v = V[e];
        lct* ru = find_root(&C[u]);
        int r_u_id = ru - C;

        val[r_u_id] += val[v] - last[e];
        link(&C[v], &C[u]);
        active[e] = true;
    }

    for (int i = 1; i <= M; i++) {
        int e;
        cin >> e;
        int u = U[e], v = V[e];

        if (active[e]) {
            lct* rv = find_root(&C[v]);
            int r_v_id = rv - C;

            val[v] = val[r_v_id];
            last[e] = val[r_v_id];
            cut(&C[v]);
            active[e] = false;
        } else {
            lct* ru = find_root(&C[u]);
            int r_u_id = ru - C;

            val[r_u_id] += val[v] - last[e];
            link(&C[v], &C[u]);
            active[e] = true;
        }
    }

    while (Q--) {
        int x;
        cin >> x;
        lct* rx = find_root(&C[x]);
        cout << val[rx - C] << '\n';
    }

    return 0;
}