struct DSU{
    vector<int> par, sz;

    DSU(int n) : par(n), sz(n) {};

    void make_set(int v) {
        par[v] = v;
        sz[v] = 1;
    }

    int find_set(int v) {
        return v == par[v] ? v : par[v] = find_set(par[v]);
    }

    void join_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sz[a] < sz[b]) swap(a,b);
            par[b] = a;
            sz[a] += sz[b];
        }
    }
};