#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fi first
#define se second
#define null nullptr
#define pb push_back
#define len length
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-07-23 14:31

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "BINSTRQ"

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

#ifdef LOCAL
   #define debug(x) cerr << x << '\n'
#else
   #define debug(x)
#endif

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

void file() {
    if (FILE *f = fopen(FILENAME".INP", "r")) {
        fclose(f);
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
}

const int MAXN = 3e5 + 5;

struct Node {
    ll sum;
    int max_val;
    int lazy;
} tree[4 * MAXN];

int N, Q;
string S;
set<pii> inter;

void push_up(int u) {
    tree[u].sum = tree[2 * u].sum + tree[2 * u + 1].sum;
    tree[u].max_val = max(tree[2 * u].max_val, tree[2 * u + 1].max_val);
}

void apply(int u, int l, int r, int val) {
    tree[u].lazy = val;
    tree[u].max_val = val;
    tree[u].sum = 1LL * val * (r - l + 1);
}

void push_down(int u, int l, int r) {
    if (tree[u].lazy != -1) {
        int mid = (l + r) / 2;
        apply(2 * u, l, mid, tree[u].lazy);
        apply(2 * u + 1, mid + 1, r, tree[u].lazy);
        tree[u].lazy = -1;
    }
}

void build(int u, int l, int r) {
    tree[u].lazy = -1;
    if (l == r) {
        tree[u].sum = l - 1;
        tree[u].max_val = l - 1;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * u, l, mid);
    build(2 * u + 1, mid + 1, r);
    push_up(u);
}

void update_range(int u, int l, int r, int ql, int qr, int val) {
    if (l > qr || r < ql) return;
    if (ql <= l && r <= qr) {
        apply(u, l, r, val);
        return;
    }
    push_down(u, l, r);
    int mid = (l + r) / 2;
    update_range(2 * u, l, mid, ql, qr, val);
    update_range(2 * u + 1, mid + 1, r, ql, qr, val);
    push_up(u);
}

int find_first(int u, int l, int r, int ql, int qr, int val) {
    if (l > qr || r < ql || tree[u].max_val < val) return -1;
    if (l == r) return l;
    push_down(u, l, r);
    int mid = (l + r) / 2;
    int res = find_first(2 * u, l, mid, ql, qr, val);
    if (res != -1) return res;
    return find_first(2 * u + 1, mid + 1, r, ql, qr, val);
}

void update_history(int L, int R) {
    int p = find_first(1, 1, N, L, N, R);
    int qr;
    if (p == -1) qr = R;
    else qr = min(R, p - 1);

    if (L <= qr) {
        update_range(1, 1, N, L, qr, R);
    }
}

void add_1(int L, int R) {
    int new_L = L, new_R = R;
    auto it = inter.lower_bound({L, -1});
    if (it != inter.begin()) {
        auto prev = it;
        --prev;
        if (prev->second >= L - 1) {
            it = prev;
        }
    }
    while (it != inter.end() && it->first <= R + 1) {
        new_L = min(new_L, it->first);
        new_R = max(new_R, it->second);
        it = inter.erase(it);
    }
    inter.insert({new_L, new_R});
    update_history(new_L, new_R);
}

void add_0(int L, int R) {
    auto it = inter.lower_bound({L, -1});
    if (it != inter.begin()) {
        auto prev = it;
        --prev;
        if (prev->second >= L) {
            it = prev;
        }
    }
    vector<pii> to_add;
    while (it != inter.end() && it->first <= R) {
        if (it->first < L) {
            to_add.push_back({it->first, L - 1});
        }
        if (it->second > R) {
            to_add.push_back({R + 1, it->second});
        }
        it = inter.erase(it);
    }
    for (auto p : to_add) {
        inter.insert(p);
    }
}

ll get_ans() {
    return tree[1].sum - 1LL * N * (N - 1) / 2;
}

void testcase() {
    cin >> N >> Q;
    cin >> S;

    build(1, 1, N);

    int start = -1;
    for (int i = 1; i <= N; ++i) {
        if (S[i - 1] == '1') {
            if (start == -1) start = i;
        } else {
            if (start != -1) {
                add_1(start, i - 1);
                start = -1;
            }
        }
    }
    if (start != -1) {
        add_1(start, N);
    }

    cout << get_ans() << el;

    for (int i = 0; i < Q; ++i) {
        int l, r, type;
        cin >> l >> r >> type;
        if (type == 1) {
            add_1(l, r);
        } else {
            add_0(l, r);
        }
        cout << get_ans() << el;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}