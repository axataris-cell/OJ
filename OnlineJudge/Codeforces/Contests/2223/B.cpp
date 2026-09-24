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

#define int long long

int calc(vector<int> &a) {
    int n = a.size() - 1;
    int res = 0;
    map<int, bool> mp;
    int curmx = 0;
    int curmex = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > curmx) curmx = a[i];
        mp[a[i]] = true;
        while (mp[curmex]) ++curmex;
        // cout << i << ' ' << curmx << ' ' << curmex << el;
        res += curmx + curmex;
    }
    return res;
}

void testcase() {
    int n; cin >> n;
    vector<int> _a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> _a[i];

    {
        map<int, bool> mp;
        for (int i = 1; i <= n; i++) {
            mp[_a[i]] = true;
        }
        if (!mp[0]) {
            cout << n * (*max_element(all(_a))) << el;
            return;
        }
    }

    vector<int> a = _a;

    int posmx = -1;
    int valmx = -1;
    for (int i = 1; i <= n; i++) {
        if (a[i] > valmx) {
            valmx = a[i];
            posmx = i;
        }
    }
    swap(a[1], a[posmx]);
    if (n > 1) sort(a.begin() + 2, a.end());

    vector<int> b = _a;
    sort(b.begin() + 1, b.end());

    cout << max({calc(a), calc(b), calc(_a)}) << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1; cin >> t;
    while (t--) testcase();

    return 0;
}