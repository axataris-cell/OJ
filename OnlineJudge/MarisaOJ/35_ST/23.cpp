#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define el '\n'
#define FILENAME "23"

void file() {
    if (FILE *f = fopen(FILENAME".INP", "r")) {
        fclose(f);
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
}

const int MAXN = 1e5 + 5;
vector<int> a(MAXN, 0);

struct Node {
    ll sum[10];
    int lz[10];

    Node() {
        for (int i = 0; i < 10; i++) {
            sum[i] = 0;
            lz[i] = i;
        }
    }
};

vector<Node> ST(4 * MAXN);

void build(int id, int l, int r) {
    for (int i = 0; i < 10; i++) ST[id].lz[i] = i;
    if (l == r) {
        int X = a[l];
        if (X == 0) {
            ST[id].sum[0] = 1;
        } else {
            ll w = 1;
            while (X > 0) {
                ST[id].sum[X % 10] += w;
                X /= 10;
                w *= 10;
            }
        }
        return;
    }
    int mid = (l + r) / 2;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    for (int i = 0; i < 10; i++) {
        ST[id].sum[i] = ST[id << 1].sum[i] + ST[id << 1 | 1].sum[i];
    }
}

void apply(int id, int parent_lz[]) {
    ll new_sum[10] = {0};
    for (int i = 0; i < 10; i++) {
        new_sum[parent_lz[i]] += ST[id].sum[i];
    }
    for (int i = 0; i < 10; i++) {
        ST[id].sum[i] = new_sum[i];
        ST[id].lz[i] = parent_lz[ST[id].lz[i]];
    }
}

void push(int id) {
    bool has_lazy = false;
    for (int i = 0; i < 10; i++) {
        if (ST[id].lz[i] != i) {
            has_lazy = true;
            break;
        }
    }
    if (!has_lazy) return;

    apply(id << 1, ST[id].lz);
    apply(id << 1 | 1, ST[id].lz);

    for (int i = 0; i < 10; i++) ST[id].lz[i] = i;
}

void update(int id, int l, int r, int ql, int qr, int x, int y) {
    if (l > qr || r < ql) return;
    if (ql <= l && r <= qr) {
        int mapping[10];
        for (int i = 0; i < 10; i++) mapping[i] = i;
        mapping[x] = y;
        apply(id, mapping);
        return;
    }
    push(id);
    int mid = (l + r) / 2;
    update(id << 1, l, mid, ql, qr, x, y);
    update(id << 1 | 1, mid + 1, r, ql, qr, x, y);
    for (int i = 0; i < 10; i++) {
        ST[id].sum[i] = ST[id << 1].sum[i] + ST[id << 1 | 1].sum[i];
    }
}

ll query(int id, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return 0;
    if (ql <= l && r <= qr) {
        ll res = 0;
        for (int i = 0; i < 10; i++) {
            res += ST[id].sum[i] * i;
        }
        return res;
    }
    push(id);
    int mid = (l + r) / 2;
    return query(id << 1, l, mid, ql, qr) + query(id << 1 | 1, mid + 1, r, ql, qr);
}

void testcase() {
    int n, q;
    if (!(cin >> n >> q)) return;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build(1, 1, n);

    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int l, r, x, y;
            cin >> l >> r >> x >> y;
            if (x != y) {
                update(1, 1, n, l, r, x, y);
            }
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << el;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1;
    while (t--) testcase();

    return 0;
}