//#pragma GCC target("popcnt")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define el '\n'
#define BIT(x,i) (((x) >> (i)) & 1)
#define MASK(i) (1 << (i))
template<class X, class Y>
bool minimize(X &x, const Y &y) {
    if (x > y)
    {
        x = y;
        return true;
    }
    return false;
}
template<class X, class Y>
bool maximize(X &x, const Y &y) {
    if (x < y)
    {
        x = y;
        return true;
    }
    return false;
}

const ll lim = 2e5 + 1;

int a[lim];

struct DSU {
    vector<int> sz,p;

    DSU(int _n): sz(_n),p(_n) {}

    void make_set(int u) {
        sz[u] = 1;
        p[u] = u;
    }
    int find_set(int u) {
        return u == p[u] ? u : p[u] = find_set(p[u]);
    }
    void merge(int u,int v) {
        u = find_set(u);
        v = find_set(v);

        if (u != v) {
            if (sz[u] < sz[v]) swap(u,v);

            sz[u] += sz[v];
            p[v] = u;
        }
    }
    int get_size(int u) {
        return sz[find_set(u)];
    }
};

int n,q;
struct Edge {
    int u,v,w;
};

struct query {
    int u,id,k,state;
};


vector<Edge> tree;
vector<query> queries;
int cnt[lim][2];
int ans[lim];


void solve() {
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        Edge x;
        cin >> x.u >> x.v >> x.w;
        tree.push_back(x);
    }
    sort(tree.begin(),tree.end(),[](const Edge a, const Edge b) {
        return a.w > b.w;;
    });
    for (int i = 1; i <= q; i++) {
        int u,k;
        cin >> u >> k;
        query x1,x2;
        x1.u = x2.u = u;
        x1.id = x2.id = i;
        x1.k = k;
        x2.k = k + 1;
        x1.state = 0;
        x2.state = 1;

        queries.push_back(x1);
        queries.push_back(x2);
    }

    sort(queries.begin(),queries.end(),[](const query a, const query b) {
        return a.k > b.k;
    });

    DSU dsu(n + 1);
    for (int i = 1; i <= n; i++) {
        dsu.make_set(i);
    }

    int j = 0;
    for (auto &qq: queries) {
        while (j < tree.size() && tree[j].w >= qq.k) {
            dsu.merge(tree[j].u,tree[j].v);
            j++;
        }
        cnt[qq.id][qq.state] = dsu.get_size(qq.u);
    }
    for (int i = 1; i <= q; i++) {
        ans[i] = cnt[i][0] - cnt[i][1];
    }
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << el;
    }
}
int main() {
  cin.tie(0)->sync_with_stdio(false);
  int t = 1;
  // cin >> t; //(use for multitestcases)
  for (int tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ":" << el;
    solve();
  }
}