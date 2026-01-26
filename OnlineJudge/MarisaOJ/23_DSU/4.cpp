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

struct DSU {
    vector<int> par;
    DSU(int n) : par(n) {
        for (int i = 0; i < n; i++) par[i] = i;
    }

    int find(int u) {
        if (par[u] == u) return u;
        return par[u] = find(par[u]);
    }

    void occupy(int u, int n) {
        par[u] = find((u + 1) % n);
    }
};

void testcase() {
	int n; cin >> n;
	
	DSU dsu(n);

	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		--x;
		int pos = dsu.find(x);
		cout << pos + 1 << ' ';
		dsu.occupy(pos, n);
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}
