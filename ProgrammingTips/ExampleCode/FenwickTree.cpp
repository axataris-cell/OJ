struct Fenwick {
    int n;
    vector<int> bit;

    Fenwick(int _n) : n(_n), bit(n + 1, 0) {}

    void update(int pos, int val) {
        for (; pos <= n; pos += pos & -pos)
            bit[pos] += val;
    }

    int query(int pos) {
        int res = 0;
        for (; pos; pos -= pos & -pos)
            res += bit[pos];
        return res;
    }

    int query(int l, int r) {
        return query(r) - query(l - 1);
    }

    int walk(int k) {
        int pos = 0;

        int pw = 1;
        while ((pw << 1) <= n) pw <<= 1;

        for (; pw; pw >>= 1) {
            if (pos + pw <= n && bit[pos + pw] < k) {
                k -= bit[pos + pw];
                pos += pw;
            }
        }

        return pos + 1;
    }
};