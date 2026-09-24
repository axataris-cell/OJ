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

string sumDigit(string s) {
	int res = 0;
	int n = s.length();
	for (int i = 0; i < n; i++) {
		res += s[i] - '0';
	}
	return to_string(res);
}

void testcase() {
	string n; cin >> n;
	int cnt = 0;
	while (n.length() != 1) {
		++cnt;
		n = sumDigit(n);
	}
	cout << cnt;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
