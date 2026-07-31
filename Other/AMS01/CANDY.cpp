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
// Created: 2026-07-31 11:28

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "CANDY"

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

const int MAXN = 1e6 + 5;

vector<int> ST(4 * MAXN, 0);
vector<int> lz(4 * MAXN, 0);

void push(int id, int l, int r) {
	if (!lz[id]) return;
	
	int mid = (l + r) / 2;
	
	ST[id << 1] += lz[id] * (mid - l + 1);
	lz[id << 1] += lz[id];
	
	ST[id << 1 | 1] += lz[id] * (r - mid);
	lz[id << 1 | 1] += lz[id];
	
	lz[id] = 0;
}

void update(int id, int l, int r, int a, int b, int val) {
	if (l > b || r < a) return;
	if (l >= a && r <= b) {
		ST[id] += (r - l + 1) * val;
		lz[id] += val;
		return;
	}
	push(id, l, r);
	
	int mid = (l + r) / 2;
	update(id << 1, l, mid, a, b, val);
	update(id << 1 | 1, mid + 1, r, a, b, val);
	
	ST[id] = ST[id << 1] + ST[id << 1 | 1];
}

int query(int id, int l, int r, int a, int b) {
	if (l > b || r < a) return 0;
	if (l >= a && r <= b) {
		return ST[id];
	}
	
	push(id, l, r);
	
	int mid = (l + r) / 2;
	return query(id << 1, l, mid, a, b) + query(id << 1 | 1, mid + 1, r, a, b);
}

void testcase() {
    int n; cin >> n;
    int m; cin >> m; // m hoc sinh
    vector<int> a(n + 1, 0), b(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    ll N = n;
    ll M = m;
    if (N * M <= 1e8) {
        vector<ll> res(m + 1, 0);

        pqueue<pll, vector<pll>, greater<pll>> pq;

        for (int i = 1; i <= m; i++) {
            pq.emplace(res[i], i);
        }

        for (int i = 1; i <= n; i++) {
            queue<pll> add;
            for (int j = 1; j <= b[i]; j++) {
                auto [v, id] = pq.top(); pq.pop();
                v += a[i];
                add.emplace(v, id);
            }
            while (add.size()) {
                auto [v, id] = add.front(); add.pop();
                pq.emplace(v, id);
            }
        }

        while (pq.size()) {
            auto [v, id] = pq.top(); pq.pop();
            res[id] = v;
        }

        for (int i = 1; i <= m; i++) {
            cout << res[i] << ' ';
        }
        return;
    }

    int cur = 1;
    for (int i = 1; i <= n; i++) {
        if (cur + b[i] - 1 > m) {
            int x = b[i] - (n - cur + 1);
            update(1, 1, m, cur, m, a[i]);
            update(1, 1, m, 1, x, a[i]);
            cur = x + 1;
        } else {
            update(1, 1, m, cur, cur + b[i] - 1, a[i]);
            cur = cur + b[i];
        }
    }

    for (int i = 1; i <= m; i++) {
        cout << query(1, 1, m, i, i) << ' ';
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