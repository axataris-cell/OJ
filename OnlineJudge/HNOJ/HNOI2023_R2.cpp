#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000 + 5;
vector<int> g[MAXN];
int belong[MAXN]; // 1: thuộc s, 2: thuộc t

#define FILENAME "TDL"
void file() {
	if (FILE *f = fopen(FILENAME".INP", "r")) {
		fclose(f);
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
}

int dfs(int u, int p, int side) {
    vector<int> child;
    for (int v : g[u]) {
        if (v == p || belong[v] != side) continue;
        child.push_back(dfs(v, u, side));
    }
    sort(child.begin(), child.end(), greater<int>());

    int res = 0;
    for (int i = 0; i < (int)child.size(); i++)
        res = max(res, child[i] + i + 1);

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    file();

    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int m;
    cin >> m;

    if (m == 1) {
        int s;
        cin >> s;
        cout << dfs(s, 0, 0);
        return 0;
    }

    int s, t;
    cin >> s >> t;

    // BFS từ s
    vector<int> ds(n + 1, -1), dt(n + 1, -1);
    queue<int> q;
    q.push(s);
    ds[s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) if (ds[v] == -1) {
            ds[v] = ds[u] + 1;
            q.push(v);
        }
    }

    // BFS từ t
    q.push(t);
    dt[t] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) if (dt[v] == -1) {
            dt[v] = dt[u] + 1;
            q.push(v);
        }
    }

    // Gán mỗi node về nguồn gần hơn
    for (int i = 1; i <= n; i++) {
        if (ds[i] <= dt[i]) belong[i] = 1;
        else belong[i] = 2;
    }

    int ans1 = dfs(s, 0, 1);
    int ans2 = dfs(t, 0, 2);

    cout << max(ans1, ans2);
    return 0;
}
