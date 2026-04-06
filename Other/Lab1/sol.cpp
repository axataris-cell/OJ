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
// Created: 2026-04-04 23:18

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "sol"

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

const int MAXN = 1e7 + 5;

bool p[MAXN];
void sieve() {
    for (int i = 2; i < MAXN; i++) p[i] = true;
    for (int i = 2; i * i < MAXN; i++) {
        if (p[i]) {
            for (int j = i * i; j < MAXN; j += i) {
                p[j] = false;
            }
        }
    }
}

void testcase() {
    int n; cin >> n;
    if (n < MAXN) cout << (p[n] ? "YES" : "NO") << el;
    else {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                cout << "NO" << el;
                return;
            }
        }
        cout << "YES" << el;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    sieve();

    int t = 1; cin >> t;
    while (t--) testcase();

    return 0;
}