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
// Created: 2026-08-03 13:52

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "HAISANG"

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

const int MAXN = 1e6 + 5;

int sang[MAXN];
int mp[MAXN];
int vis[MAXN];

void sieve() {
    for (int i = 2; i < MAXN; i++) sang[i] = i;
    for (int i = 2; i * i < MAXN; i++) {
        if (sang[i] == i) {
            for (int j = i * i; j < MAXN; j += i) {
                if (sang[j] == j) sang[j] = i;
            }
        }
    } 
}

struct Dat {
    int p, q;
    int cnt;
};

void testcase() {
    sieve();
    int n; cin >> n;
    vector<int> a(n + 1, 0);
    
    vector<int> prime;
    vector<pii> twin;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vector<int> primes;

        while (a[i] > 1) {
            int p = sang[a[i]];
            primes.pb(p);
            while (a[i] % p == 0) a[i] /= p;
        }

        for (int p : primes) {
            if (mp[p] == 0) prime.pb(p);
            ++mp[p];
        }

        for (int i = 0; i < primes.size(); i++) {
            for (int j = 0; j < primes.size(); j++) {
                twin.pb({primes[i], primes[j]});
            }
        }
    }
    
    vector<Dat> chung;
    
    sort(all(twin));
    for (int i = 0; i < twin.size();) {
        int j = i;
        while (j < twin.size() && twin[j] == twin[i]) j++;
        chung.pb({twin[i].fi, twin[i].se, j - i});
        i = j;
    }

    int res = 0;
    if (prime.size()) res = mp[prime[0]];

    vector<vector<int>> g(MAXN + 1);

    for (auto &[p, q, cnt] : chung) {
        int value = mp[p] + mp[q] - cnt;

        if (value > res) {
            res = value;
        }
        g[p].pb(q);
        g[q].pb(p);
    }

    sort(all(prime), [&](int a, int b) {return mp[a] > mp[b];});

    int timer = 0;

    for (int i = 0; i < prime.size(); i++) {
        int p = prime[i];
        if (mp[p] + mp[prime[0]] <= res) break;

        timer++;
        for (int q : g[p]) vis[q] = timer;

        for (int j = 0; j < prime.size(); j++) {
            int q = prime[j];
            if (p == q) continue;
            if (vis[q] == timer) continue;
            int value = mp[p] + mp[q];
            if (value > res) {
                res = value;
            }
            break;
        }
    }

    cout << res;
}

/*
5   
6 10 15 7 1
*/

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}