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
// Created: 2026-07-06 21:59

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "11"

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

struct Fenwick {
    int n;
    vector<int> bit;

    Fenwick(int sz) : n(sz), bit(sz + 1) {}

    void update(int pos, int val) {
        for (; pos <= n; pos += pos & (-pos)) bit[pos] += val;
    }

    int query(int pos) {
        int res = 0;
        for (; pos > 0; pos -= pos & (-pos)) {
            res += bit[pos];
        }
        return res;
    }
};

void testcase() {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1, 0);
    vector<int> f(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
    }

    vector<int> b = f;
    sort(all(b)); // tinh ca f[0]
    for (int i = 0; i <= n; i++) {
        f[i] = lower_bound(all(b), f[i]) - b.begin();
    }
    
    auto check = [&](int val) {
        Fenwick BIT(n + 1); 
        int cnt = 0;
        
        BIT.update(f[0] + 1, 1); 
        
        for (int i = 1; i <= n; i++) {
            int original_fi = b[f[i]];
            int target = original_fi - val;

            int idx = upper_bound(all(b), target) - b.begin(); 
            
            cnt += BIT.query(idx);

            BIT.update(f[i] + 1, 1);
        }
        return cnt >= k;
    };

    int L = -1e15;
    int R = 1e15;
    int ans = L;
    
    while (L <= R) {
        int mid = L + (R - L) / 2;
        if (check(mid)) {
            ans = mid;
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }
    
    cout << ans << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}