#include <bits/stdc++.h>
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
	
	int k = 0, q = 0;
	vector<int> parts;
	
	int i = 0;
	while (s[i] != '1') ++i;
	while (i < n) {
		if (s[i] == '1') {
			++i; continue;
		} else {
			int l = i;
			while (i < n && s[i] == '0') {
				++i;
			}
			q += i - l;
			parts.push_back(i - l);
		}
	}
	k = parts.size();
	
	
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
