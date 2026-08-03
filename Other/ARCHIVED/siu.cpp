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
// Created: 2026-08-03 10:55

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "siu"

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
    int n, m;
    cin >> n >> m;

    vector<int> color(n, 0);

    int B = 0;
    int B0 = 0;
    int B1 = 0;
    int O = 0;

    int deu = n / 3;
    vector<int> bc(n / 3, 0);

    auto res = [&]() -> int {
        int cnt = 0;
        if (n % 2 != 0) {
            cnt = (1LL * n * (n - 1) / 2) - 3LL * ((n - 1) / 2) * B + 3LL * B * (B - 1) / 2;
        } else {
            cnt = (1LL * n * (n - 2) / 2) - 3LL * ((n - 2) / 2) * B + 2LL * B * B - 2LL * B - 2LL * B0 * B1 - 2LL * O;
        }
        
        int ans = cnt;
        if (n % 3 == 0) {
            ans -= 2LL * deu;
        }
        return ans;
    };

    string s; cin >> s;
    for (int u = 0; u < n; u++) {
        if (s[u] == 'W') continue;
        if (n % 3 == 0) {
            int idx = u % (n / 3);
            if (bc[idx] == 0 || bc[idx] == 3) deu--;
            
            if (color[u] == 0) bc[idx]++;
            else bc[idx]--;
            
            if (bc[idx] == 0 || bc[idx] == 3) deu++;
        }

        if (color[u] == 0) {
            B++;
            if (n % 2 == 0) {
                if (u % 2 == 0) B0++;
                else B1++;
                int v = (u + n / 2) % n;
                if (color[v] == 1) O++;
            }
            color[u] = 1;
        } else {
            B--;
            if (n % 2 == 0) {
                if (u % 2 == 0) B0--;
                else B1--;
                int v = (u + n / 2) % n; // doi dinh
                if (color[v] == 1) O--;
            }
            color[u] = 0;
        }
    }

    for (int i = 0; i < m; ++i) {
        int u; cin >> u;
        u--;

        if (n % 3 == 0) {
            int idx = u % (n / 3);
            if (bc[idx] == 0 || bc[idx] == 3) deu--;
            
            if (color[u] == 0) bc[idx]++;
            else bc[idx]--;
            
            if (bc[idx] == 0 || bc[idx] == 3) deu++;
        }

        if (color[u] == 0) {
            B++;
            if (n % 2 == 0) {
                if (u % 2 == 0) B0++;
                else B1++;
                int v = (u + n / 2) % n;
                if (color[v] == 1) O++;
            }
            color[u] = 1;
        } else {
            B--;
            if (n % 2 == 0) {
                if (u % 2 == 0) B0--;
                else B1--;
                int v = (u + n / 2) % n;
                if (color[v] == 1) O--;
            }
            color[u] = 0;
        }

        cout << res() << el;
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