#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int n;
long long a[MAXN];
long long st[4 * MAXN]; // segment tree

// Xây cây
void build(int id, int l, int r) {
    if (l == r) {
        st[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = st[id * 2] + st[id * 2 + 1];
}

// Cập nhật a[pos] = val
void update(int id, int l, int r, int pos, long long val) {
    if (l == r) {
        st[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
        update(id * 2, l, mid, pos, val);
    else
        update(id * 2 + 1, mid + 1, r, pos, val);
    st[id] = st[id * 2] + st[id * 2 + 1];
}

// Truy vấn tổng đoạn [u, v]
long long query(int id, int l, int r, int u, int v) {
    if (v < l || r < u) return 0;        // không giao
    if (u <= l && r <= v) return st[id]; // nằm trọn
    int mid = (l + r) / 2;
    return query(id * 2, l, mid, u, v)
         + query(id * 2 + 1, mid + 1, r, u, v);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    build(1, 1, n);

    // ví dụ dùng
    cout << query(1, 1, n, 2, 5) << '\n'; // tổng a[2..5]
    update(1, 1, n, 3, 10);              // a[3] = 10
    cout << query(1, 1, n, 2, 5) << '\n';

    return 0;
}
