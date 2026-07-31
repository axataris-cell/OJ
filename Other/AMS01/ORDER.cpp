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

/*
4
3 7 8
4 9 10
2 5 7
1 4 4
*/

#define int long long

const int MAXN = 105;

int n;

int t[MAXN], d[MAXN], p[MAXN];
bool vis[MAXN];
vector<int> bruh;
int res = 0;
vector<int> st;

void dfs(int curtime, int curval, int pos) {
    vis[pos] = true;
    st.pb(pos);

    for (int i = 1; i <= n; i++) {
        if (!vis[i] && curtime + t[i] < d[i]) {
            dfs(curtime + t[i], curval + p[i], i);
        }
    }

    if (curval > res) {
        bruh = st;
        res = curval;
    }

    vis[pos] = false;
    st.pop_back();
}

void testcase() {
    cin >> n;
    int MAXD = 0;
    map<int, int> sub2;
    for (int i = 1;  i <= n; i++) {
        cin >> t[i] >> d[i] >> p[i];
        MAXD = max(MAXD, d[i]);
        ++sub2[d[i]];
    }

    if (sub2.size() == 1) {
        vector<vector<int>> dp(n + 1, vector<int>(MAXD + 1, -LINF));
        vector<vector<int>> truy(n + 1, vector<int>(MAXD + 1, -1));
        for (int i = 1; i <= n; i++) dp[i][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int w = MAXD; w >= t[i]; w--) {
                for (int j = 1; j <= n; j++) {
                    if (i == j) continue;
                    if (dp[j][w - t[i]] + p[i] > dp[i][w]) {
                        dp[i][w] = dp[j][w - t[i]] + p[i];
                        truy[i][w] = j;
                    }
                }
            }
        }
        
        // for (int i = 0; i < MAXD; i++) cout << dp[i] << ' ';
        // return;

        int s = -1;
        int cur = 0;

        for (int w = 0; w < MAXD; w++) {
            for (int i = 1; i <= n; i++) {
                if (res < dp[i][w]) {
                    res = dp[i][w];
                    s = i;
                    cur = w;
                }
            }
        }

        vector<int> truyvet;

        while (s != -1) {
            truyvet.pb(s);
            s = truy[s][cur];
            cur -= t[s];
        }

        reverse(all(truyvet));

        cout << res << el;
        cout << truyvet.size() << el;
        for (auto x : truyvet) cout << x << ' ';

        return;
    }

    for (int i = 1; i <= n; i++) {
        dfs(t[i], p[i], i);
    }

    cout << res << el;
    cout << bruh.size() << el;
    for (auto x : bruh) cout << x << ' ';
}

/*

4
3 10 8
4 10 10
2 10 7
1 10 4

25
3
1 2 3 
*/

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}