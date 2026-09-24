#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-14 22:07

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME ""

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void file() {
    if (FILE *f = fopen(FILENAME".INP", "r")) {
        fclose(f);
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
}

void testcase() {
    int n; cin >> n;
    
    vector<int> c(n), p(n);
    for(int i = 0; i < n; i++) cin >> c[i] >> p[i];

    double f = 0.0;
    for(int i = n - 1; i >= 0; i--){
        double complete = c[i] + (1.0 - p[i] / 100.0) * f;
        double skip = f;
        f = max(complete, skip);
    }
    
    cout << fixed << setprecision(9) << f << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); file();

    int t = 1; cin >> t;
    while (t--) testcase();

    return 0;
}