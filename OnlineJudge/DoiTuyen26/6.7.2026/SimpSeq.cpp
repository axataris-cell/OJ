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
// Created: 2026-07-06 11:01

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "SimpSeq"

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

const int MAXN = 3e5 + 5;
const int LOG = 30;

int n;

vector<vector<int>> ST(LOG + 1, vector<int>(MAXN, 0));
vector<int> a(MAXN, 0);

void build() {
    for (int i = 1; i <= n; i++) ST[0][i] = a[i];
    for (int l = 1; l <= LOG; l++) {
        for (int i = 1; i + (1 << l) - 1 <= n; i++) {
            ST[l][i] = __gcd(ST[l - 1][i], ST[l - 1][i + (1 << (l - 1))]);
        }
    }
}

int query(int l, int r) {
    int k = __lg(r - l + 1);
    return __gcd(ST[k][l], ST[k][r - (1 << k) + 1]);
}

void testcase() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build();

    vector<int> prev(n + 1, -1);
    vector<int> nxt(n + 1, n + 1);

    {
        map<int, int> last;
        for (int i = 1; i <= n; i++) {
            prev[i] = (last[a[i]] == 0 ? -1 : last[a[i]]);
            last[a[i]] = i;
        }
    }

    {
        map<int, int> last;
        for (int i = 1; i <= n; i++) {
            if (last[a[i]] != 0) nxt[last[a[i]]] = i;
            last[a[i]] = i;
        }
    }

    int res = 0;

    for (int i = 1; i <= n; i++) {
        int L = i;
        {
            int l = 1, r = i;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (query(mid, i) == a[i]) {
                    L = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
        int R = i;
        {
            int l = i, r = n;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (query(i, mid) == a[i]) {
                    R = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        L = max(L, prev[i] + 1);
        R = min(R, nxt[i] - 1);
        res += (i - L + 1) * (R - i + 1) - 1;
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