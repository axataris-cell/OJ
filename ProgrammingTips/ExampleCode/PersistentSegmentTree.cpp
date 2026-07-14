const int MAXN = 1e5 + 5;

// lưu ý cách dùng: phải build cây gốc đầu tiên trống trước.

struct Node {
    int val;
    int l_id, r_id;
} pool[20 * MAXN];

struct PersistentSegmentTree {
    vector<int> roots;
    int nodeCnt;
    int n;
    
    PersistentSegmentTree(int sz) : n(sz), roots(sz + 1), nodeCnt(0) {}

    int create(int val = 0, int l_id = 0, int r_id = 0) {
        int cur_id = ++nodeCnt;
        pool[cur_id] = {val, l_id, r_id};
        return cur_id;  
    }
    
    int build(int l, int r) {
        int cur_id = create();
        if (l == r) {
            return cur_id;
        }
        int mid = (l + r) / 2;
        pool[cur_id].l_id = build(l, mid);
        pool[cur_id].r_id = build(mid + 1, r);
        pool[cur_id].val = pool[pool[cur_id].l_id].val + pool[pool[cur_id].r_id].val;
        return cur_id;
    }
    
    int update(int tree_id, int l, int r, int pos, int val) {
        int cur_id = create(pool[tree_id].val, pool[tree_id].l_id, pool[tree_id].r_id);
        if (l == r) {
            pool[cur_id].val += val;
            return cur_id;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) {
            pool[cur_id].l_id = update(pool[cur_id].l_id, l, mid, pos, val);
        } else {
            pool[cur_id].r_id = update(pool[cur_id].r_id, mid + 1, r, pos, val);
        }
        pool[cur_id].val = pool[pool[cur_id].l_id].val + pool[pool[cur_id].r_id].val;
        return cur_id;
    }
    
    int query(int tree_id, int l, int r, int ql, int qr) {
        if (!tree_id) return 0;
        if (l > qr || r < ql) return 0;
        if (ql <= l && r <= qr) {
            return pool[tree_id].val;
        }
        int mid = (l + r) / 2;
        return query(pool[tree_id].l_id, l, mid, ql, qr) + query(pool[tree_id].r_id, mid + 1, r, ql, qr);
    }
};