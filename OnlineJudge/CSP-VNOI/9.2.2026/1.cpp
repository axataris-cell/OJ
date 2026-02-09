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
const int LOG = 40;
void testcase() {
	ll x; cin >> x;
	string s = "";
	while (x > 0) {
		s += (char)((x & 1) + '0');
		x >>= 1;
	}
	reverse(s.begin(), s.end());
	
	int n = s.length();
	set<ll> st;
	
	for (int i = 0; i < n; i++) {
		ll val = 0;
		for (int j = i; j < n; j++) {
			val = val * 2 + (s[j] - '0');
			st.insert(val);
		}
	}
	
	ll res = 0;
	for (auto v : st) res += v;
	
	cout << res;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
