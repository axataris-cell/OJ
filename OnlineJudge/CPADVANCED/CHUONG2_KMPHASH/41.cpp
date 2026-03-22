#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define null nullptr
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-21 21:08

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

#define int long long

struct Hash {
    vector<int> H, P;
    map<int, int> mp;
    string s;
    int n;
    int BASE, MOD;
    int has;
    Hash(int _sz, int _BASE, int _MOD, string _s) : H(_sz + 1, 0), P(_sz + 1, 1), BASE(_BASE), MOD(_MOD), n(_sz), s(_s), has(0) {}

    void build() {
        for (int i = 1; i <= n; i++) {
            H[i] = ((H[i - 1] * BASE) % MOD + s[i - 1]) % MOD;
            P[i] = (P[i - 1] * BASE) % MOD;
        }
        has = H[n];
        ++mp[has];
    }

    void update(int pos, char val) {
        has = (has - ((s[pos - 1] * P[n - pos]) % MOD) + ((val * P[n - pos]) % MOD) + MOD) % MOD;
        s[pos - 1] = val;
        ++mp[has];
    }
};

void testcase() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    Hash h1(n, 911,  1e9 + 7, s);
    Hash h2(n, 131,  1e9 + 9, s);
    h1.build(); h2.build();

    set<pair<int,int>> seen;
    seen.insert({h1.has, h2.has});

    while (q--) {
        int pos; char val;
        cin >> pos >> val;
        h1.update(pos, val);
        h2.update(pos, val);
        seen.insert({h1.has, h2.has});
    }

    cout << seen.size();
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}