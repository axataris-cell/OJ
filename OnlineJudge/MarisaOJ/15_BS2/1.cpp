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
// Created: 2026-04-14 21:26

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "1"

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

const int MAXN = 1e5 + 5;
int n, k;

vector<int> a(MAXN, 0);

bool check(int v) {
    int cur = a[1];
    int cnt = 1;
    for (int i = 2; i <= n; i++) {
        // cerr << a[i] << ' ' << cur << el;
        if (a[i] - cur < v) continue;
        ++cnt;
        cur = a[i];
    }
    cerr << v << ' ' << cnt << el;
    return cnt >= k;
}

void testcase() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.begin() + n + 1);

    check(4);

    int res = 0;
    int l = 0, r = 1e9 + 1;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            res = max(res, mid);
            l = mid + 1;
        } else {
            r = mid - 1;
        }
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