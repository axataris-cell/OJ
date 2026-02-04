#include <bits/stdc++.h>
#include <chrono>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

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

#define INF 1e9

void testcase() {
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> adj(n + 1, vector<bool>(n + 1, false));

    for (int i = 1; i <= n; i++) adj[i][i] = true;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = adj[v][u] = true;
    }

    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (!adj[i][j]) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    vector<int> color(n + 1, -1);
    vector<pair<int,int>> comps;

    for (int i = 1; i <= n; i++) {
        if (color[i] != -1) continue;

        queue<int> q;
        q.push(i);
        color[i] = 0;

        int cnt0 = 1, cnt1 = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : g[u]) {
                if (color[v] == -1) {
                    color[v] = color[u] ^ 1;
                    if (color[v] == 0) cnt0++;
                    else cnt1++;
                    q.push(v);
                } else {
                    if (color[v] == color[u]) {
                        cout << -1 << el;
                        return;
                    }
                }
            }
        }

        comps.push_back({cnt0, cnt1});
    }

    vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (auto [a, b] : comps) {
        vector<bool> ndp(n + 1, false);
        for (int s = 0; s <= n; s++) {
            if (!dp[s]) continue;
            if (s + a <= n) ndp[s + a] = true;
            if (s + b <= n) ndp[s + b] = true;
        }
        dp = ndp;
    }

    int ans = INF;
    for (int s = 0; s <= n; s++) {
        if (dp[s]) {
            ans = min(ans, abs(n - 2 * s));
        }
    }

    cout << ans << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}
