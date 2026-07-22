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
// Created: 2026-07-22 08:38

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "SoUocTrenCay"

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

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;

vector<int> g[MAXN];
vector<int> num(MAXN, 0);
vector<int> res(MAXN, 1);
map<int, ll> f[MAXN];

vector<int> prime;
bool isprime[MAXN];
void sieve() {
    for (int i = 2; i < MAXN; i++) isprime[i] = true;
    for (int i = 2; i * i < MAXN; i++) {
        if (isprime[i]) {
            for (int j = i * i; j < MAXN; j += i) {
                isprime[j] = false;
            }
        }
    }
    for (int i = 0; i < MAXN; i++) {
        if (isprime[i]) prime.pb(i);
    }
}

void init(int u) {
    int k = num[u];
    for (int p : prime) {
        if (1LL * p * p > k) break;
        while (k % p == 0) {
            ++f[u][p];
            k /= p;
        }
    }
    if (k > 1) ++f[u][k];
}

void dfs(int u, int p) {
    init(u);
    for (int v : g[u]) {
        if (v == p) continue;
        dfs(v, u);
        if (f[u].size() < f[v].size()) swap(f[u], f[v]);
        for (auto &[k, v] : f[v]) {
            f[u][k] += v;
        }
    }
    for (auto &[k, v] : f[u]) {
        res[u] *= (v + 1);
        res[u] %= MOD;
    }
}

void testcase() {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    sieve();
    dfs(1, 1);
    while (q--) {
        int x; cin >> x;
        cout << res[x] << ' ';
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