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
// Created: 2026-03-28 14:54

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "165"

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

const int MAXN = 1e5 + 5;

vector<int> g[MAXN];
vector<int> color(MAXN, 0); // 0 = yellow, 1 = green
vector<int> yellow;
vector<int> green;
ld res = 0;
ld cnt = 0;
ld res2 = 0;
ld cnt2 = 0;

void testcase() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        char c; cin >> c;
        color[i] = (c == 'Y' ? 0 : 1);
        if (c == 'Y') yellow.pb(i);
        else green.pb(i);
    }
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    for (int i = 1; i < yellow.size(); i++) {
        int s = yellow[i];
        vector<int> dist(n + 1, INF); 
        pqueue<pii, vector<pii>, greater<pii>> pq;

        pq.emplace(0, s);
        dist[s] = 0;

        while (pq.size()) {
            pii x = pq.top(); pq.pop();
            int u = x.second;
            int d = x.first;

            if (d > dist[u]) continue;

            for (int v : g[u]) {
                int w = 1;
                if (color[v] != color[s]) w += 3;

                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }

        for (int j = 0; j < i; j++) {
            int v = yellow[j];
            cerr << 'j'; debug(j);
            cerr << 'i'; debug(i);
            ++cnt;
            res += dist[v];
        }
    }
    debug(999);
    for (int i = 1; i < green.size(); i++) {
        int s = green[i];
        vector<int> dist(n + 1, INF); 
        pqueue<pii, vector<pii>, greater<pii>> pq;

        pq.emplace(0, s);
        dist[s] = 0;

        while (pq.size()) {
            pii x = pq.top(); pq.pop();
            int u = x.second;
            int d = x.first;

            if (d > dist[u]) continue;

            for (int v : g[u]) {
                int w = 1;
                if (color[v] != color[s]) w += 3;

                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }

        for (int j = 0; j < i; j++) {
            int v = green[j];
            ++cnt2;
            res2 += dist[v];
        }
    }
    for (auto x : yellow) cerr << x << ' ';
    cerr << el;
    for (auto x : green) cerr << x << ' ';
    cerr << el;
    debug(res);
    debug(res2);
    debug(cnt);
    debug(cnt2);
    cout << fixed << setprecision(9) << (res + res2) / (cnt + cnt2);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}