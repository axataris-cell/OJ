#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

// Cấu trúc Segment Tree hỗ trợ Range Add và Range Max Query
struct SegmentTree {
    int n;
    vector<long long> tree;
    vector<long long> lazy;

    SegmentTree(int n) : n(n) {
        tree.assign(4 * n, -INF);
        lazy.assign(4 * n, 0);
    }

    void push(int node) {
        if (lazy[node] != 0) {
            tree[2 * node] += lazy[node];
            lazy[2 * node] += lazy[node];
            tree[2 * node + 1] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
            lazy[node] = 0;
        }
    }

    void update_point(int node, int l, int r, int idx, long long val) {
        if (l == r) {
            tree[node] = val;
            lazy[node] = 0;
            return;
        }
        push(node);
        int mid = (l + r) / 2;
        if (idx <= mid)
            update_point(2 * node, l, mid, idx, val);
        else
            update_point(2 * node + 1, mid + 1, r, idx, val);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    void update_range(int node, int l, int r, int ql, int qr, long long val) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            tree[node] += val;
            lazy[node] += val;
            return;
        }
        push(node);
        int mid = (l + r) / 2;
        update_range(2 * node, l, mid, ql, qr, val);
        update_range(2 * node + 1, mid + 1, r, ql, qr, val);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    long long query_max(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return -INF;
        if (ql <= l && r <= qr) return tree[node];
        push(node);
        int mid = (l + r) / 2;
        return max(query_max(2 * node, l, mid, ql, qr),
                   query_max(2 * node + 1, mid + 1, r, ql, qr));
    }
};

void solve_query(int n, const vector<long long>& a, const vector<long long>& f, long long C) {
    // Kiểm tra nếu có phần tử lớn hơn C thì không thể chia đoạn
    for (int i = 1; i <= n; ++i) {
        if (a[i] > C) {
            cout << -1 << "\n";
            return;
        }
    }

    vector<int> K(n + 1, 0);
    vector<long long> S(n + 1, 0);

    SegmentTree st_tree(n + 1);
    vector<int> st; // Monotonic Stack lưu chỉ số (1-based)

    for (int i = 1; i <= n; ++i) {
        // 1. Thêm điểm j = i - 1 vào Segment Tree với giá trị ban đầu S[i-1] + a[i]
        st_tree.update_point(1, 0, n, i - 1, S[i - 1] + a[i]);

        // 2. Cập nhật Monotonic Stack cho a[i]
        while (!st.empty() && a[st.back()] <= a[i]) {
            int top_idx = st.back();
            st.pop_back();
            int left_j = st.empty() ? 0 : st.back();
            int right_j = top_idx - 1;
            // Cộng chênh lệch (a[i] - a[top_idx]) cho đoạn [left_j, right_j]
            st_tree.update_range(1, 0, n, left_j, right_j, a[i] - a[top_idx]);
        }
        st.push_back(i);

        // 3. Tìm L_i sao cho f[i] - f[L_i] <= C
        int L_i = lower_bound(f.begin(), f.begin() + i, f[i] - C) - f.begin();

        // 4. Tìm R_opt_i là chỉ số lớn nhất j <= i - 1 có K[j] == K[L_i]
        int R_opt_i = upper_bound(K.begin() + L_i, K.begin() + i, K[L_i]) - K.begin() - 1;

        // 5. Truy vấn giá trị S_i lớn nhất từ Segment Tree trong khoảng [L_i, R_opt_i]
        long long max_val = st_tree.query_max(1, 0, n, L_i, R_opt_i);

        K[i] = K[L_i] + 1;
        S[i] = max_val;
    }

    cout << K[n] << " " << S[n] << "\n";
}

int main() {
    // Tối ưu I/O C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    vector<long long> a(n + 1);
    vector<long long> f(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
    }

    while (q--) {
        long long C;
        cin >> C;
        solve_query(n, a, f, C);
    }

    return 0;
}