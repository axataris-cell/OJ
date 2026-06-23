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
// Created: 2026-06-22 09:14

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "A"

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
    int n, m; cin >> n >> m;

    vector<int> a(n);
    vector<vector<int>> pos(m + 1);
    vector<int> D;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (pos[a[i]].empty()) {
            D.push_back(a[i]);
        }
        pos[a[i]].push_back(i);
    }

    int ans = 0;

    int na = m - D.size();
    ans += D.size() * na * 1;

    for (int i = 0; i < D.size(); i++) {
        for (int j = i + 1; j < D.size(); j++) {
            int x = D[i];
            int y = D[j];

            int p1 = 0, p2 = 0;
            int pval = -1;
            int curlen = 0;

            while (p1 < pos[x].size() || p2 < pos[y].size()) {
                int nval;

                if (p1 < pos[x].size() && (p2 >= pos[y].size() || pos[x][p1] < pos[y][p2])) {
                    nval = x;
                    p1++;
                } else {
                    nval = y;
                    p2++;
                }

                if (nval != pval) {
                    curlen++;
                    pval = nval;
                }
            }
            
            ans += curlen;
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