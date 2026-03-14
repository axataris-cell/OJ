#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-14 22:13

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
    int n; cin >> n;
    vector<vector<char>> a(n + 1, vector<char>(n + 1, '0'));
    vector<int> g[n + 1];
    vector<int> bruh[n + 1];
    vector<int> deg(n + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == '1') {
                g[i].push_back(j);
                bruh[j].push_back(i);
                bruh[i].push_back(j);
                ++deg[j];
            }
        } 
    }

    // check 1
    {
        queue<int> q;
        vector<bool> vis(n + 1, 0);

        q.push(1);
        vis[1] = true;

        while (q.size()) {
            int u = q.front();
            q.pop();

            for (int v : bruh[u]) {
                if (vis[v]) continue;
                q.push(v);
                vis[v] = true;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                cout << "NO" << el;
                return;
            }
        }
    }

    // check 2 Dag
    {
        queue<int> q;
        vector<int> topo;
        vector<int> deg2 = deg;

        for (int i = 1; i <= n; i++) {
            if (deg[i] == 0) {
                q.push(i);
                topo.push_back(i);
            }
        }

        while (q.size()) {
            int u = q.front();
            q.pop();

            for (int v : g[u]) {
                --deg2[v];
                if (deg2[v] == 0) {
                    q.push(v);
                    topo.push_back(v);
                }
            }
        }

        if (topo.size() < n) {
            cout << "NO" << el;
            return;
        }
    }

    

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); file();

    int t = 1; cin >> t;
    while (t--) testcase();

    return 0;
}