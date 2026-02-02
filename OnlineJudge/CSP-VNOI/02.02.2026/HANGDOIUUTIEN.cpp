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

void testcase() {
	pqueue<int, vector<int>> pq;
	int q; cin >> q;
	while (q--) {
		string s; cin >> s;
		if (s[0] == '+') {
			string t = "";
			for (int i = 1; i < s.length(); i++) t += s[i];
			int x = stoi(t);
			pq.push(x);
		} else if (s[0] == '-') {
			if (!pq.size()) continue;
			int x = pq.top();
			while (pq.size() && pq.top() == x) pq.pop();
		}
	}
	vector<int> res;
	while (pq.size()) {
		int x = pq.top();
		res.push_back(x);
		while (pq.size() && pq.top() == x) pq.pop();
	}
	cout << res.size() << el;
	for (auto x : res) cout << x << ' ';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}
