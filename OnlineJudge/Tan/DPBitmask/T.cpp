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

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "L"

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

void testcase() {
    string s;
    cin >> s;

    int n = s.size();

    constexpr int ALPHA = 20;
    constexpr int FULL = (1 << ALPHA) - 1;

    vector<int> mx(1 << ALPHA, 0);

    int l = 0;
    int mask = 0;

    for (int r = 0; r < n; r++) {
        int c = s[r] - 'a';

        while (mask & (1 << c)) {
            mask ^= (1 << (s[l] - 'a'));
            l++;
        }

        mask |= (1 << c);

        int cur = mask;

        for (int st = l; st <= r; st++) {
            mx[cur] = max(mx[cur], r - st + 1);
            cur ^= (1 << (s[st] - 'a'));
        }
    }

    vector<int> sos = mx;

    for (int i = 0; i < ALPHA; i++) {
        for (int mask = 0; mask <= FULL; mask++) {
            if (mask & (1 << i)) {
                sos[mask] = max(sos[mask], sos[mask ^ (1 << i)]);
            }
        }
    }

    int ans = 0;

    for (int mask = 1; mask <= FULL; mask++) {
        if (mx[mask]) {
            ans = max(ans, mx[mask] + sos[(~mask) & FULL]);
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