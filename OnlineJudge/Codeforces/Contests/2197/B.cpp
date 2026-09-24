#include <bits/stdc++.h>
#include <chrono>

#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'
#define INF 1e9
#define LINF 1e18

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
	vector<int> a(n), p(n);
	vector<int> id;

	for (auto &x : a) cin >> x;
	for (auto &x : p) {
		cin >> x;
		if (!id.size()) id.push_back(x);
		else {
			if (id[id.size() - 1] != x) id.push_back(x);
		}
	}
//	for (int i = 0; i < id.size(); i++) cout << id[i] << ' ';
//	cout << el;
	int i = 0, j = 0;
	while (i < n && j < id.size()) {
		while (i < n && j < id.size() && a[i] != id[j]) ++i;
		if (i < n && j < id.size() && a[i] == id[j]) {
			++i;
			++j;
		}
	}
	if (j != id.size()) cout << "NO" << el;
	else cout << "YES" << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
