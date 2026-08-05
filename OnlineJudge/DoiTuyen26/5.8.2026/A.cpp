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
// Created: 2026-08-05 08:19

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "A"

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

#define int long long

const int MAXN = 1e5 + 5;

struct Node {
    int mx;
    int best;
};

Node mergeNode(const Node &x, const Node &y) {
    Node res;
    if (x.mx < y.mx) res = {y.mx, y.best};
    if (x.mx > y.mx) res = {x.mx, x.best};
    if (x.mx == y.mx) res = {x.mx, max(x.best, y.best)};
    return res;
}

vector<Node> ST(2 * MAXN, {-LINF, 0});

void update(int n, int pos, int val, int og) {
    pos += n - 1;
    if (ST[pos].mx > val) return;
    ST[pos] = {val, max(og, ST[pos].best)};
    for (; (pos >> 1) > 0; pos >>= 1) {
        ST[pos >> 1] = mergeNode(ST[pos], ST[pos ^ 1]);
    }
}

Node query(int n, int l, int r) {
    if (l > r) return {-LINF, 0};
    Node res = {-LINF, 0};
    for (l += n - 1, r += n - 1; l <= r; l >>= 1, r >>= 1) {
        if (l & 1) res = mergeNode(res, ST[l++]);
        if (!(r & 1)) res = mergeNode(res, ST[r--]);
    }
    return res;
}

void testcase() {
    int n, D; cin >> n >> D;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    vector<int> comp = a;
    sort(comp.begin() + 1, comp.end());
    comp.erase(unique(all(comp)), comp.end());

    auto get_id = [&](int val) -> int {
        return lower_bound(comp.begin() + 1, comp.end(), val) - comp.begin();
    };
    
    vector<int> dp(n + 1, 1); // ket thuc tai i
    vector<int> par(n + 1, -1);

    for (int i = 1; i <= n; i++) {
        int v = get_id(a[i]);
        int L = max((int)(upper_bound(comp.begin() + 1, comp.end(), a[i] - D) - comp.begin() - 1), 1LL);
        int R = min((int)(lower_bound(comp.begin() + 1, comp.end(), a[i] + D) - comp.begin()), n);
        Node bruh = mergeNode(query(n, 1, L), query(n, R, n));
        if (bruh.mx != -LINF) {
            dp[i] = bruh.mx + 1;
            par[i] = bruh.best;
        }
        update(n, v, dp[i], i);
    }

    // for (int i = 1; i <= n; i++) {
    //     cout << get_id(a[i] - D) - 1 << ' ' << get_id(a[i]) << ' ' << upper_bound(comp.begin() + 1, comp.end(), a[i] + D) - comp.begin() << el;
    // }
    // return;

    int best = 1;
    for (int i = 1; i <= n; i++) {
        if (dp[i] > dp[best]) best = i;
    }

    vector<int> res;
    while (best != -1) {
        res.pb(best);
        best = par[best];
    }
    reverse(all(res));

    cout << res.size() << el;
    for (auto x : res) cout << x << ' ';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}