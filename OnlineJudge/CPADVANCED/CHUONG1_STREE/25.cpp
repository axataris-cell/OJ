#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define null nullptr
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-16 18:39

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
#define int long long

const int MOD = 1e9 + 7;

struct Fenwick {
    int n;
    vector<ll> bit;

    Fenwick(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update(int i, ll v) {
        for (; i <= n; i += i & -i) {
            bit[i] = (bit[i] + v) % MOD;
        }
    }

    ll query(int i) {
        ll s = 0;
        for (; i > 0; i -= i & -i)
            s = (s + bit[i]) % MOD;
        return s;
    }
};

void testcase() {
    int n, k; cin >> n >> k;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    // lọ rời rạc
    vector<int> comp = a;
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    for (int &x : a) x = lower_bound(comp.begin(), comp.end(), x) - comp.begin() + 1;

    int m = comp.size();
    vector<Fenwick> fenw;

    for (int i = 0; i <= k; i++) fenw.emplace_back(m);

    for (int i = 0; i < n; i++) {
        int val = a[i];

        for (int j = k; j >= 2; j--) {
            long long ways = fenw[j-1].query(val - 1);
            fenw[j].update(val, ways);
        }

        fenw[1].update(val, 1);
    }

    cout << fenw[k].query(m) << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}