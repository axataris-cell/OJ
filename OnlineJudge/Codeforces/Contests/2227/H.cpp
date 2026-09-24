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
// Created: 2026-04-30 22:58

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "H"

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

struct State {
    int fi, se, num;
};

void testcase() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    stack<State> st; // index - count left, increase
    vector<int> f(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int cnt = 1;
        int num = 0;
        while (st.size() && a[st.top().fi] >= a[i]) {
            cnt += st.top().se;
            f[i] += st.top().se * (a[st.top().fi] - a[i]) + num * ;
            st.pop();
        }
        if (st.size()) f[i] += f[st.top().fi];
        st.push({i, cnt, num});
    }

    for (int i = 1; i <= n; i++) cout << f[i] << ' ';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; cin >> t;
    while (t--) testcase();

    return 0;
}