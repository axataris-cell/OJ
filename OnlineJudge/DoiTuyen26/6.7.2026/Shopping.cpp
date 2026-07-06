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
// Created: 2026-07-06 10:26

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "Shopping"

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
const int LOG = 20;

int n, q;

vector<vector<int>> ST(LOG + 1, vector<int>(MAXN, LINF));
vector<int> a(MAXN, 0);

void build() {
    for (int i = 1; i <= n; i++) {
        ST[0][i] = a[i];
    }
    for (int i = 1; i <= LOG; i++) {
        for (int j = 1; j + (1 << i) - 1 <= n; j++) {
            ST[i][j] = min(ST[i - 1][j], ST[i - 1][j + (1 << (i - 1))]);
        }
    }
}

int query(int l, int r) {
    int lg = __lg(r - l + 1);
    return min(ST[lg][l], ST[lg][r - (1 << lg) + 1]);
}

int find_next(int L, int R, int val) {
    int low = L, high = R;
    int ans = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (query(L, mid) <= val) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

void testcase() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build();
    while (q--) {
        int t, l, r; 
        cin >> t >> l >> r;
        
        int curpos = l;
        while (curpos <= r) {
            int npos = find_next(curpos, r, t);
            
            if (npos == -1) break;
            
            t %= a[npos];
            
            curpos = npos + 1;
        }
        cout << t << el;
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