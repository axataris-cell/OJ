#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define null nullptr
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-18 10:57

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
    int a, b, k; cin >> a >> b >> k;
    vector<int> uocso;
    for (int i = 1; i <= sqrt(b); i++) {
        if (b % i) continue;
        uocso.push_back(b / i);
        if (i != sqrt(b)) uocso.push_back(i);
    }
    sort(uocso.begin(), uocso.end());
    map<int, int> mp;
    for (int i = 0; i < uocso.size(); i++) {
        mp[uocso[i]] = i;
    }
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}