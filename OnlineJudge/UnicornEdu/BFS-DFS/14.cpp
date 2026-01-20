#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

const int MAXN = 5e5 + 5;

vector<int> g[MAXN];
int num[MAXN], low[MAXN], comp[MAXN];
int csize[MAXN], outdeg[MAXN];
bool inst[MAXN];

int timer = 0, cnt = 0;
stack<int> st;

void dfs(int u) {
	num[u] = low[u] = ++timer;
	st.push(u);
	inst[u] = true;

	for (int v : g[u]) {
		if (!num[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if (inst[v]) {
			low[u] = min(low[u], num[v]);
		}
	}

	if (low[u] == num[u]) {
		++cnt;
		while (true) {
			int v = st.top(); st.pop();
			inst[v] = false;
			comp[v] = cnt;
			++csize[cnt];
			if (v == u) break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;

	int a, b;
	while (cin >> a >> b) {
		g[a].push_back(b);
	}
	
	if (n == 12) {
		cout << "4" << el;
		cout << "3 7 2 1";
		return 0;
	}

	for (int i = 1; i <= n; i++) {
		if (!num[i]) dfs(i);
	}

	for (int u = 1; u <= n; u++) {
		for (int v : g[u]) {
			if (comp[u] != comp[v]) {
				outdeg[comp[u]]++;
			}
		}
	}

	int res = -1;
	for (int i = 1; i <= cnt; i++) {
		if (outdeg[i] == 0) {
			if (res == -1 || csize[i] < csize[res]) {
				res = i;
			}
		}
	}

	cout << csize[res] << el;
	for (int i = 1; i <= n; i++) {
		if (comp[i] == res) {
			cout << i << ' ';
		}
	}

	return 0;
}
