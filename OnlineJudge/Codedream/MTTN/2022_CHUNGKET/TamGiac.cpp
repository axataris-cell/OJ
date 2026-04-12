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
// Created: 2026-04-10 09:16

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "TamGiac"

using namespace std;
using pii = pair<int, int>;
using pll = pair<int, int>;

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
    int n, t;
    cin >> n >> t;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a.begin() + 1, a.end());

    int ans = 0;

    for (int i = 1; i <= n - 2; i++) {
        int p1 = i + 2; 
        int p2 = i + 2; 
        int p3 = i + 2; 

        for (int j = i + 1; j <= n - 1; j++) {
            p1 = max(p1, j + 1);
            p2 = max(p2, j + 1);
            p3 = max(p3, j + 1);

            int sum_edge = a[i] + a[j];
            int sum_sq = a[i] * a[i] + a[j] * a[j];

            while (p3 <= n && a[p3] < sum_edge) {
                p3++;
            }

            while (p1 < p3 && a[p1] * a[p1] < sum_sq) {
                p1++;
            }

            while (p2 < p3 && a[p2] * a[p2] <= sum_sq) {
                p2++;
            }

            if (t == 1) {
                ans += (p1 - j - 1); 
            } 
            else if (t == 2) {
                ans += (p2 - p1);     
            } 
            else if (t == 3) {
                ans += (p3 - p2);     
            }
        }
    }

    cout << ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}