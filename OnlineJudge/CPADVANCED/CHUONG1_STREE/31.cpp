#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define null nullptr
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-17 21:49

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME ""

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

const int MAXN = 3e5 + 5;

int n, q;
ll a[MAXN];
ll st[2 * MAXN];

ll get_val(int i) {
    if (i <= 1) return 0;
    return max(0LL, a[i] - a[i - 1]);
}

void build() {
    for (int i = 1; i <= n; i++)
        st[n + i - 1] = get_val(i);

    for (int i = n - 1; i >= 1; i--)
        st[i] = st[i << 1] + st[i << 1 | 1];
}

void update(int pos) {
    int i = pos + n - 1;
    st[i] = get_val(pos);
    for (i >>= 1; i; i >>= 1)
        st[i] = st[i << 1] + st[i << 1 | 1];
}

ll query() {
    return st[1];
}

void testcase() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];

    build();
    cout << a[1] + query() << el;

    while (q--) {
        int l, r;
        cin >> l >> r;

        if (l != r) {
            int pos[4] = {l, l + 1, r, r + 1};
            sort(pos, pos + 4);

            swap(a[l], a[r]);

            for (int i = 0; i < 4; i++) {
                if (i && pos[i] == pos[i - 1]) continue;
                if (pos[i] >= 1 && pos[i] <= n)
                    update(pos[i]);
            }
        }

        cout << a[1] + query() << el;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1; cin >> t;
    while (t--) testcase();

    return 0;
}