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

struct Edge {
    int to;
    int id;
    int og;
};

void testcase() {
    int n; cin >> n;
 
    vector<int> a(n), b(n);
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        cnt[b[i]]++;
    }
 
    for (auto [val, count] : cnt) {
        if (count % 2 != 0) {
            cout << -1 << endl;
            return;
        }
    }
 
    vector<int> vals;
    for (auto [val, count] : cnt) vals.push_back(val);
    auto get_id = [&](int x) {
        return lower_bound(vals.begin(), vals.end(), x) - vals.begin();
    };
 
    int m = vals.size();
    vector<vector<Edge>> adj(m);
    for (int i = 0; i < n; ++i) {
        int u = get_id(a[i]);
        int v = get_id(b[i]);
        adj[u].push_back({v, i + 1, u});
        adj[v].push_back({u, i + 1, u});
    }
 
    vector<bool> used(n + 1, false);
    vector<int> ptr(m, 0);
    vector<int> swaps;
 
    for (int i = 0; i < m; ++i) {
        if (ptr[i] < adj[i].size()) {
            vector<int> st;
            st.push_back(i);
            while (!st.empty()) {
                int u = st.back();
                bool found = false;
                while (ptr[u] < adj[u].size()) {
                    Edge e = adj[u][ptr[u]++];
                    if (used[e.id]) continue;
                    used[e.id] = true;
 
                    if (u != e.og) {
                        swaps.push_back(e.id);
                    }
                    st.push_back(e.to);
                    found = true;
                    break;
                }
                if (!found) st.pop_back();
            }
        }
    }
 
    cout << swaps.size() << el;
    for (int i = 0; i < swaps.size(); ++i) {
        cout << swaps[i] << ' ';
    }
    cout << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
