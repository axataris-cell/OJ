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
// Created: 2026-06-18 13:39

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "kmex"

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

void testcase() {
    int n, q; 
    cin >> n >> q;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a.begin() + 1, a.end());
    
    while (q--) {
        int k; 
        cin >> k;
        
        int l = 1, r = n;
        int ans_idx = 0;

        while (l <= r) {
            int mid = (l + r) / 2;
            int missing = a[mid] - mid + 1;
            
            if (missing < k) {
                ans_idx = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        cout << k + ans_idx - 1 << ' ';
    }
    cout << el;
}
/*
4 1
1 2 6 7
1
*/

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}