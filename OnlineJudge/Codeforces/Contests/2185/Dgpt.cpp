#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    vector<long long> st;

    SegTree(int n): n(n), st(4*n, 0) {}

    void update(int p, long long val, int id, int l, int r) {
        if (l == r) {
            st[id] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if (p <= mid) update(p, val, id<<1, l, mid);
        else update(p, val, id<<1|1, mid+1, r);
        st[id] = max(st[id<<1], st[id<<1|1]);
    }

    void update(int p, long long val) {
        update(p, val, 1, 1, n);
    }

    long long queryMax() {
        return st[1];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        long long h;
        cin >> n >> m >> h;

        vector<long long> a(n+1), limit(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            limit[i] = h - a[i];
        }

        vector<int> b(m+1);
        vector<long long> c(m+1);
        for (int i = 1; i <= m; i++) {
            cin >> b[i] >> c[i];
        }

        vector<long long> add(n+1, 0);
        SegTree st(n);

        int start = m + 1;

        for (int i = m; i >= 1; i--) {
            add[b[i]] += c[i];
            st.update(b[i], add[b[i]] - limit[b[i]]);
            if (st.queryMax() > 0) {
                break;
            }
            start = i;
        }

        // apply valid suffix
        for (int i = start; i <= m; i++) {
            a[b[i]] += c[i];
        }

        for (int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}
