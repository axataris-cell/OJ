struct DSU{
    vector<int> parent, sz, sum;

    DSU(int n) : parent(n), sz(n), sum(n) {};

    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1;
        sum[v] = a[v];
    }

    int find_set(int v) {
        return v == parent[v] ? v : parent[v] = find_set(parent[v]);
    }

    void join_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sz[a] < sz[b]) swap(a,b);
            parent[b] = a;
            sz[a] += sz[b];
            sum[a] += sum[b];
        }
    }
};