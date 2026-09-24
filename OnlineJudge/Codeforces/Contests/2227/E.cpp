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

// Author: Fua

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

#ifdef LOCAL
   #define debug(x) cerr << x << '\n'
#else
   #define debug(x)
#endif

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

#define int long long

const int MAXN = 2e5 + 5;

vector<pll> ST(4 * MAXN, {0, 0});

void update(int id, int l, int r, int pos, int val) {
   if (l == r) {
      ST[id].fi += val;
      ST[id].se = pos * ST[id].fi;
      return;
   }
   int mid = (l + r) / 2;
   if (pos <= mid) update(id << 1, l, mid, pos, val);
   else update(id << 1 | 1, mid + 1, r, pos, val);
   ST[id].fi = ST[id << 1].fi + ST[id << 1 | 1].fi;
   ST[id].se = ST[id << 1].se + ST[id << 1 | 1].se;
}

int query(int id, int l, int r, int ql, int qr) {
   if (ql > r || qr < l) return 0;
   if (ql <= l && r <= qr) {
      return ST[id].se;
   }
   int mid = (l + r) / 2; 
   return query(id << 1, l, mid, ql, qr) + query(id << 1 | 1, mid + 1, r, ql, qr);
}

int query2(int id, int l, int r, int ql, int qr) {
   if (ql > r || qr < l) return 0;
   if (ql <= l && r <= qr) {
      return ST[id].fi;
   }
   int mid = (l + r) / 2; 
   return query(id << 1, l, mid, ql, qr) + query(id << 1 | 1, mid + 1, r, ql, qr);
}

void testcase() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }

    for (int i = 1; i < 4 * MAXN; i++) ST[i] = {0, 0};

    vector<int> f(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      
    }

    for (int i = 1; i < 4 * MAXN; i++) ST[i] = {0, 0};

    cout << f[n] << el;
    return;

    int res = 0;
    for (int i = 1; i <= n; i++) {
      // số block nếu chặt đầu thằng i query(1, 1, n, a[i], n) - query2(1, 1, n, a[i], n) * (a[i] - 1);
      // số block bên phải, không ảnh hưởng: f[n] - f[i]
      res = max(res, query(1, 1, n, a[i], n) - query2(1, 1, n, a[i], n) * (a[i] - 1) + f[n] - f[i]);
      update(1, 1, n, a[i], 1);
    }

    cout << res << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1; cin >> t;
    while (t--) testcase();

    return 0;
}