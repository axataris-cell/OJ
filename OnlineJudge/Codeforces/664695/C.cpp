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
	int n; cin >> n;
	string s; cin >> s;
	
	string res = "";
	
	if ('a' <= s[0] && s[0] <= 'z') {
		char cur = s[0];
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == cur) ++cnt;
			else {
				res += to_string(cnt) + cur;
				cur = s[i];
				cnt = 1;
			}
		}
		res += to_string(cnt) + cur;
	} else {
		int i = 0;
		while (i < n) {
			int j = i;
			while (!('a' <= s[j] && s[j] <= 'z')) ++j;
			for (int k = 1; k <= stoi(s.substr(i, j - i)); k++) {
				res += s[j];
			}
			i = j + 1;
		}
	}
	cout << res << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
