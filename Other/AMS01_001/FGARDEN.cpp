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
// Created: 2026-06-30 09:20

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "FGARDEN"

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

const int MAXN = 3e6 + 5;

vector<ll> bit(MAXN, 0);

int n;

void update(int pos, ll val) {
	for (; pos <= n; pos += pos & -pos) {
		bit[pos] += val;
	}
}

ll query(int i) {
	ll res = 0;
	for (; i > 0; i -= i & -i) {
		res += bit[i];
	}
	return res;
}

void testcase() {
    cin >> n;
    ll T; cin >> T; // limi

    vector<pll> a(n + 1, {0, 0});
    for (int i = 1; i <= n; i++) {
        cin >> a[i].fi;
        a[i].se = i; // idx;
    }

    sort(a.begin() + 1, a.end());

    int res = 1; // ud[pated?]
    int l = 0;

    for (int r = 1; r <= n; r++) {
        while (a[r].fi - a[l + 1].fi > T) {
            ++l;
            update((int)a[l].se, 1LL);
        }
        if (l == 0) {
            res = r;
            continue;
        }

        //bs
        int cur = r;
        int goal = query(a[r].se - 1);
        int bl = 1, br = a[r].se;
        while (bl <= br) {
            int mid = (bl + br) / 2;
            if (query(mid) < goal) {
                bl = mid + 1;
            } else {
                br = mid - 1;
                cur = min(mid, cur);
            }
        }

        res = max(res, r - cur);
    }
 
    cout << res;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}