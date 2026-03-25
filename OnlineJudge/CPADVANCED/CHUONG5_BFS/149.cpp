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
// Created: 2026-03-25 10:07

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "149"

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

map<pii, int> dist;
map<pii, bool> vis;
map<pii, bool> obs;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void testcase() {
    int n, D; cin >> n >> D;
    for (int i = 1; i <= n; i++) {
        int a, b; cin >> a >> b;
        obs[{a, b}] = true;
    }
    
    // bfs
    int res = 0;
    {
        queue<pii> q;
        
        q.push({0, 0});
        dist[{0, 0}] = 0;
        vis[{0, 0}] = true;

        while (q.size()) {
            pii u = q.front();
            q.pop();
            int x = u.first, y = u.second;
            ++res;
            if (dist[{x, y}] >= D) continue;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (!vis[{nx, ny}] && obs[{nx, ny}] == false) {
                    vis[{nx, ny}] = true;
                    dist[{nx, ny}] = dist[{x, y}] + 1;
                    q.push({nx, ny});
                }
            }
        }
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