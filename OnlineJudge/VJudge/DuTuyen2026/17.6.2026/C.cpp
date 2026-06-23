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
// Created: 2026-06-17 09:41

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "C"

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

vector<int> g[MAXN];
vector<int> distA(MAXN, INF), distB(MAXN, INF);

void testcase() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    int s, t; cin >> s >> t;
    {
        queue<int> q;
        q.emplace(s);
        distA[s] = 0;
        while (q.size()) {
            int u = q.front(); q.pop();
            for (int v : g[u]) {
                if (distA[v] == INF) {
                    distA[v] = distA[u] + 1;
                    q.emplace(v);
                }
            }
        }
    }
    {
        queue<int> q;
        q.emplace(t);
        distB[t] = 0;
        while (q.size()) {
            int u = q.front(); q.pop();
            for (int v : g[u]) {
                if (distB[v] == INF) {
                    distB[v] = distB[u] + 1;
                    q.emplace(v);
                }
            }
        }
    }
    int q; cin >> q;
    while (q--) {
        int pos; cin >> pos;
        if (distA[pos] == INF) {
            cout << "NO" << el;
        } 
        else if (distA[pos] <= distB[pos]) {
            cout << "YES" << el;
        } 
        else {
            cout << "NO" << el;
        }
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