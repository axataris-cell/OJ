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

const bool dA[6] = {1, 0, 0, 0, 1, 1}; // 1 = {
const bool dB[6] = {0, 1, 0, 1, 0, 1};
const bool dC[6] = {0, 0, 1, 1, 1, 0};

bool check(string &s) {
	int n = s.length();
	for (int i = 0; i < 6; i++) {
		stack<bool> st;
		bool ok = true;
		for (int j = 0; j < n; j++) {
			bool cur;
			if (s[j] == 'A') cur = dA[i];
			if (s[j] == 'B') cur = dB[i];
			if (s[j] == 'C') cur = dC[i];
			
			if (cur == 0) {
				if (st.empty()) {
					ok = 0;
					break;
				} else {
					st.pop();
				}
			} else {
				st.push(cur);
			}
		}
		if (st.size()) ok = 0;
		if (ok) return true;
	}
	return false;
}

void testcase() {
	string s; cin >> s;
	if (check(s)) cout << "YES" << el;
	else cout << "NO" << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
