#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define null nullptr
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-17 08:04

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

const int MAXN = 2e5 + 5;

int n, m;

vector<int> g[MAXN];
vector<int> color(MAXN, -1);
bool vis[MAXN];

int bipartite(int s) {
    queue<int> q;

    int cnt1 = 0, cnt0 = 0;

    bool bruh = true;

    q.push(s);
    vis[s] = true;
    color[s] = 1;

    while (q.size()) {
        int u = q.front(); q.pop();

        if (color[u] == 1) ++cnt1;
        else ++cnt0;

        for (int v : g[u]) {
            if (!vis[v]) {
                vis[v] = true;
                color[v] = color[u] ^ 1;
                q.push(v);
            } else {
                if (color[v] == color[u]) {
                    bruh = false;
                }
            }
        }
    }
    
    if (!bruh) return 0;

    return max(cnt0, cnt1);
}

// int check(int s) {
//     vector<bool> ass;
//     {
//         queue<int> q;
//         vector<bool> vis2(n + 1, 0);
//         q.push(s);
//         vis2[s] = true;
//         while (q.size()) {
//             int u = q.front(); q.pop();
//             ass.push_back(u);
//             for (int v : g[u]) {
//                 if (!vis2[v]) {
//                     vis2[v] = true;
//                     q.push(v);
//                 }
//             }
//         }
//     }
//     for (auto x : ass) {
//         queue<int> q;

//         vector<int> color2(n + 1, -1);
//         vector<bool> vis2(n + 1, 0);

//         bool bruh = true;
        
//         for (int v : g[x]) {
//             q.push(v);
//             vis2[v] = true;
//             color2[v] = 1;
//         }

//         while (q.size()) {
//             int u = q.front(); q.pop();
//             for (int v : g[u]) {
//                 if (!vis2[v]) {
//                     vis2[v] = true;
//                     color2[v] = color2[u] ^ 1;
//                     q.push(v);
//                 } else {
//                     if (color2[u] == color2[v]) bruh = false;
//                 }
//             }
//         }

//         if (bruh) return 1;
//     }

//     return 0;
// }

void testcase() {
    cin >> n;
    cin >> m;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        vis[i] = false;
        color[i] = -1;
    }
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) { // duyet T{T:}
            if (bipartite(i)) {
                res += bipartite(i);
            }
        }
    }
    cout << res << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); file();

    int t = 1; cin >> t;
    while (t--) testcase();

    return 0;
}