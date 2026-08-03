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
// Created: 2026-07-31 08:46

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "ORDER"

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

struct Job {
    int t, d, p, id;
    bool operator<(const Job& other) const {
        if (d != other.d) return d < other.d; 
        return id < other.id; 
    }
};  

void testcase() {
    int n; cin >> n;

    vector<Job> a(n + 1);
    int max_d = 0;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i].t >> a[i].d >> a[i].p;
        a[i].id = i;
        max_d = max(max_d, a[i].d);
    }

    sort(a.begin() + 1, a.end());
    vector<int> dp(max_d + 1, -1);
    dp[0] = 0;
    vector<vector<bool>> pick(n + 1, vector<bool>(max_d + 1, false));

    for (int i = 1; i <= n; i++) {
        for (int j = a[i].d - 1; j >= a[i].t; j--) {
            if (dp[j - a[i].t] != -1) {
                if (dp[j - a[i].t] + a[i].p > dp[j]) {
                    dp[j] = dp[j - a[i].t] + a[i].p;
                    pick[i][j] = true;
                }
            }
        }
    }

    int max_profit = -1;
    int best_time = 0;
    for (int j = 0; j <= max_d; j++) {
        if (dp[j] > max_profit) {
            max_profit = dp[j];
            best_time = j;
        }
    }

    vector<int> ans;
    int curr_time = best_time;
    for (int i = n; i >= 1; i--) {
        if (pick[i][curr_time]) {
            ans.pb(a[i].id);
            curr_time -= a[i].t;
        }
    }

    cout << max_profit << '\n';
    cout << ans.size() << '\n';
    for (int id : ans) {
        cout << id << ' ';
    }
    cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}