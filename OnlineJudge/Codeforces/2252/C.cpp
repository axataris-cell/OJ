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

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "C"

using namespace std;
using pii = pair<int, int>;
using pll = pair<int, int>;

#ifdef LOCAL
#define debug(x) cerr << x << '\n'
#else
#define debug(x)
#endif

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

void file() {
    if (FILE *f = fopen(FILENAME ".INP", "r")) {
        fclose(f);
        freopen(FILENAME ".INP", "r", stdin);
        freopen(FILENAME ".OUT", "w", stdout);
    }
}

#define int long long

struct SegTree {
    int n;
    vector<int> STsum;
    vector<int> STcnt;

    void init(int sz) {
        n = sz;
        STsum.assign(4 * n, 0);
        STcnt.assign(4 * n, 0);
    }

    void update(int id, int l, int r, int idx, int val) {
        STcnt[id]++;
        STsum[id] += val;
        if (l == r) return;
        int mid = (l + r) / 2;
        if (idx <= mid) update(id << 1, l, mid, idx, val);
        else update(id << 1 | 1, mid + 1, r, idx, val);
    }

    int query(int id, int l, int r, int target, const vector<int> &vals) {
        if (STsum[id] < target) return -1;
        if (l == r) {
            int val = vals[l];
            return (target + val - 1) / val;
        }

        int mid = l + (r - l) / 2;
        int lnode = id << 1;
        int rnode = id << 1 | 1;

        if (STsum[rnode] >= target) {
            return query(rnode, mid + 1, r, target, vals);
        } else {
            int rem = target - STsum[rnode];
            int left = query(lnode, l, mid, rem, vals);
            return STcnt[rnode] + left;
        }
    }
};

void testcase() {
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int nm = n * m;
    vector<int> a(nm);
    for (int i = 0; i < nm; i++) cin >> a[i];

    vector<int> vals = a;
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    SegTree ST;
    ST.init(vals.size());

    int ans = m;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            int val = a[i * m + j];
            int idx = lower_bound(all(vals), val) - vals.begin();
            ST.update(1, 0, (int)vals.size() - 1, idx, val);
        }

        int res = ST.query(1, 0, vals.size() - 1, v[i], vals);
        if (res != -1) ans = min(ans, res);
    }

    cout << ans << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1;
    cin >> t;
    while (t--) testcase();

    return 0;
}