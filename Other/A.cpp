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
// Created: 2026-04-06 19:24

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

const int MAXN = 2e5 + 5;
int n, q;

struct Node {
    int pos;
    int maxpos;
    int minpos;
    int lwb; // low
};

vector<int> a(MAXN, 0);
vector<int> ST(4 * MAXN, 0);

void update(int id, int l, int r, int pos) {

}

Node query(int id, int l, int r, int ql, int qr) {

}

void testcase() {
    cin >> n >> q;
    vector<int> b;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b.pb(a[i]);
    }

    sort(all(b));
    b.erase(unique(all(b)), b.end());
    for (int i = 1; i <= n; i++) a[i] = lower_bound(all(b), a[i]) - b.begin();

    while (q--) {
        int l, r; cin >> l >> r;
        l = lower_bound(all(b), l) - b.begin();
        r = upper_bound(all(b), r) - b.begin() - 1;
        assert(l <= n);
        Node res = query(1, 1, n, l, r);
        cout << a[res.maxpos] - a[res.minpos - 1];
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