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
// Created: 2026-07-17 17:41

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "B"

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

inline int64_t hilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int64_t subSquareSize = int64_t(1) << (2*pow - 2);
	int64_t ans = seg * subSquareSize;
	int64_t add = hilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}   

struct Query {
    int l, r;
    int id;
    int64_t ord;
};

int cnt[100005];

void testcase() {
    int n, q; cin >> n >> q;
    vector<int> val(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }

    vector<pii> a(n + 1);
    {
        vector<int> b = val;
        sort(b.begin() + 1, b.end());
        for (int i = 1; i <= n; i++) {
            int pos = lower_bound(b.begin() + 1, b.end(), val[i]) - b.begin();
            a[i] = {val[i], pos};
        }
    }

    int pw = 0;
    while ((1 << pw) <= n) ++pw;
    
    vector<ll> ans(q + 1, 0);
    vector<Query> queries;

    for (int i = 1; i <= q; i++) {
        int l, r; cin >> l >> r;
        queries.push_back({l, r, i, hilbertOrder(l, r, pw, 0)});
    }

    sort(all(queries), [](const Query &x, const Query &y) {
        return x.ord < y.ord;
    });
    
    int L = 1, R = 0;
    ll cur = 0;

    auto add = [&](const int &pos) {
        auto &[val, id] = a[pos];
        if (cnt[id] == val) --cur;
        ++cnt[id];
        if (cnt[id] == val) ++cur;
    };

    auto remove = [&](const int &pos) {
        auto &[val, id] = a[pos];
        if (cnt[id] == val) --cur;
        --cnt[id];
        if (cnt[id] == val) ++cur;
    };

    for (auto &[l, r, id, ord] : queries) {
        while (L < l) {
            remove(L);
            ++L;
        }
        while (L > l) {
            --L;
            add(L);
        }
        while (R < r) {
            ++R;
            add(R);
        }
        while (R > r) {
            remove(R);
            --R;

        }
        ans[id] = cur;
    }

    for (int i = 1; i <= q; i++) cout << ans[i] << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}