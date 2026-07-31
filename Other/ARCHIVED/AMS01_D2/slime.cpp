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
// Created: 2026-07-07 08:33

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "slime"

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
    if (FILE *f = fopen(FILENAME".inp", "r")) {
        fclose(f);
        freopen(FILENAME".inp", "r", stdin);
        freopen(FILENAME".out", "w", stdout);
    }
}

#define int long long

struct Slime {
    int a, b, c, t;
};

struct Pref {
    int state;
    int pos;
};

void testcase() {
    int n, k, X; cin >> n >> k >> X;
    vector<Slime> slime(n);
    for (auto &s : slime) cin >> s.a >> s.b >> s.c >> s.t;
    vector<Pref> pf; // 2 * n phan tu
    
    double dx = X;
    for (auto &[a, b, c, t] : slime) {
        double ad = a;
        double bd = b;
        double cd = c;
        // gia su bat dau tai tgian 0
        int l = ceil(dx / ad); // tgian slime bat dau >= x
        int peak = max(floor(cd / ad), 1.0); // tgian slime di toi dinh cao
        int peakheight = peak * a; // do cao lon nhat
        if (X > peakheight) {
            continue; // deo the reach duoc x
        }
        int r = peak + floor((double(peakheight) - dx) / bd); // tgian cuoi cung ma >= x khi di xuong
        pf.pb({1, l + t});
        pf.pb({-1, r + t + 1}); // thoi gian cuoi cung >= x, + 1
    }

    sort(all(pf), [](Pref x, Pref y) {
        return x.pos < y.pos; // pos l -> r
    });

    int res = 0;

    int lastpos = -1;
    int curavail = 0;
    
    for (auto &[state, pos] : pf) {
        if (lastpos != -1 && curavail >= k) res += pos - lastpos; // từ lastpos -> pos -1
        curavail += state;
        lastpos = pos;
    }

    cout << res;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}