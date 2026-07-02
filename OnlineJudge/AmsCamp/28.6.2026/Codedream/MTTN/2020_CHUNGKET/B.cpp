#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define null nullptr
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-19 22:06

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME ""

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

void file() {
    if (FILE *f = fopen(FILENAME".INP", "r")) {
        fclose(f);
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
}

const int MAXN = 1e6 + 5;
bool p[MAXN];

void sieve() {
    for (int i = 2; i < MAXN; i++) p[i] = true;
    for (int i = 2; i * i < MAXN; i++) {
        if (p[i]) {
            for (int j = i * i; j < MAXN; j += i) p[j] = false;
        }
    }
}

void testcase() {
    int n; cin >> n;
    int res = 0;
    for (int i = 1; i <= n / 2; i++) {
        int j = n - i;
        if (p[i] && p[j]) {
            ++res;
        }
    }
    cout << res;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); file();
    sieve();
    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}