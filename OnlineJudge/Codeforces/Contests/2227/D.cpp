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

void testcase() {
    int n; cin >> n;
    vector<int> a(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) {
        cin >> a[i];
    }
    int pos1 = -1;
    int pos2 = -1;
    for (int i = 1; i <= 2 * n; i++) {
        if (a[i] == 0) {
            if (pos1 == -1) pos1 = i;
            else pos2 = i;
        }
    }
    int res = 0;
    // first pos
    {
        int l = pos1, r = pos1;
        map<int, bool> mp; // calc mex;
        while (l > 0 && r <= 2 * n) {
            if (a[l] != a[r]) break;
            mp[a[l]] = true;
            mp[a[r]] = true;
            --l;
            ++r;
        }
        int mex = 0;
        for (int i = 0; i <= n; i++) {
            if (!mp[i]) {
                mex = i;
                break;
            } 
        }
        res = max(res, mex);
    }
    // second pos
    {
        int l = pos2, r = pos2;
        map<int, bool> mp; // calc mex;
        while (l > 0 && r <= 2 * n) {
            if (a[l] != a[r]) break;
            mp[a[l]] = true;
            mp[a[r]] = true;
            --l;
            ++r;
        }
        int mex = 0;
        for (int i = 0; i <= n; i++) {
            if (!mp[i]) {
                mex = i;
                break;
            } 
        }
        res = max(res, mex);
    }
    // both pos
    {
        int l = pos1, r = pos2;
        map<int, bool> mp;
        bool ispalin = true;
        while (l <= r) {
            if (a[l] != a[r]) {
                ispalin = false;
                break;
            }
            mp[a[l]] = true;
            mp[a[r]] = true;
            ++l;
            --r;
        }
        if (!ispalin) {
            cout << res << el;
            return;
        }
        l = pos1, r = pos2;
        while (l > 0 && r <= 2 * n) {
            if (a[l] != a[r]) break;
            mp[a[l]] = true;
            mp[a[r]] = true;
            --l;
            ++r;
        }
        int mex = 0;
        for (int i = 0; i <= n; i++) {
            if (!mp[i]) {
                mex = i;
                break;
            } 
        }
        res = max(res, mex);
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