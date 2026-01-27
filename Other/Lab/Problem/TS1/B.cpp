#include <bits/stdc++.h>
using namespace std;

#define FILENAME "B"

void file() {
	if (FILE *f = fopen(FILENAME".INP", "r")) {
		fclose(f);
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
}

const int MAXN = 100005;
vector<int> adj[MAXN];
bool visited[MAXN];

void dfs(int start) {
    stack<int> st;
    st.push(start);

    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (visited[u]) continue;

        visited[u] = true;
        cout << u << " ";

        for (int v : adj[u]) {
            if (!visited[v]) {
                st.push(v);
            }
        }
    }
}


int main() {
	file();
	
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // nếu là đồ thị vô hướng
    }

    dfs(1); // bắt đầu DFS từ đỉnh 1
    return 0;
}
